// A proposal for main.c ..... just to inspire you
#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include "config.h"
#include "GLCD.h"
#include <string.h>
#include "messages.h"
#include "splash.h"
#include <time.h>
#define _XTAL_FREQ 8000000 


#define PIR1bits.TX1IF TX1IF
#define PIE1bits.TXIE TXIE

#define person_size 9
#define pic_size 5
#define LEFT PORTCbits.RC0 
#define RIGHT PORTCbits.RC1 

#define MENU 0
#define INIGAME 1
#define PLAYING 2
#define LOST 3

//DRAW MY NAME
const char nombre[14] = "ALEX MOA LEAL\0";
unsigned int indx = 0;	


unsigned char menu = 1; 					//ITS A BOOLEAN FOR START THE MENU (it works when u lose and start the pic)
unsigned char start_game = 0; 				//ITS A BOOLEAN FOR START THE GAME

/*
	
0 MENU
1 INIGAME
2 PLAYING
3 LOST
*/
unsigned int game_status = MENU;


char score_string[100];
unsigned int score = 0;						//THE POINTS/SCORE OF THE GAME
unsigned int record = 0;
unsigned char send_score = 0;
int lifes = 3;

//character things
const char character[2][5] = {{0x38,0x7C,0xDE,0x97,0x9F},{0x00,0x00,0x84,0xC9,0x7F}};  //this is for draw the character.
int pos_char[2] = {5,60};															   //The position of the character
char charmoving = 0;

char button_cd = 1;

//pic things

const char pic[2] = {0x55,0x7F};
//first row pos of pic (page)
//second row pos of pic (
//third row if this pic is enable or not
int pos_pic[3][5] = {{1,1,1,1,1},{10,0,0,0,0},{1,-1,-1,-1,-1}};


//timer things
int counter = 0;

//AD things
unsigned char AD_converter = 0;
int AD_value;



void writeTxt(byte page, byte y, char * s) {
	int i=0;
	while (*s!='\n' && *s!='\0') {
		putchGLCD(page, y+i, *(s++));
		i++;
	};
}	


//draw the i pic 
void drawPic(int i)
{
	clearGLCD(pos_pic[0][i],pos_pic[0][i],pos_pic[1][i],pos_pic[1][i]+pic_size);
	for(int j = 0; j < 5; ++j)
	{
		if(j == 0 || j == 4) writeByte(pos_pic[0][i],pos_pic[1][i]+j,pic[0]);
		else writeByte(pos_pic[0][i],pos_pic[1][i]+j,pic[1]);
	}
}

//draw our character
void drawCharacter()
{
	for(int i = 0; i < 5; ++i) //mid character draw
	{
		writeByte(pos_char[0],pos_char[1]+i,character[0][i]);
		writeByte(pos_char[0]+1,pos_char[1]+i,character[1][i]);
	}
	for(int i = 0; i < 4; ++i)	//inverted character draw 
	{
		writeByte(pos_char[0],pos_char[1]+i+5,character[0][3-i]);
		writeByte(pos_char[0]+1,pos_char[1]+i+5,character[1][3-i]);
	}
	if(charmoving) charmoving = 0;
	else charmoving = 1;
}

//move the character to left or right 
void moveCharacter(char move)
{
	int moved;


	//left move
	if(move == 'l')
	{
		if(pos_char[1] - 5 >= 0) moved = -5;
		else moved = -1; 
	}

	//right move	
	else if (move == 'r')
	{
		if(pos_char[1] + person_size + 5 < 128) moved = 5;
		else moved = -2;
	}
	else return;

	clearGLCD(pos_char[0],pos_char[0]+1,pos_char[1],pos_char[1]+person_size);
	
	if(moved == -1) pos_char[1] = 119;	  //move to right side
	else if(moved == -2) pos_char[1] = 0; //move to left side
	else pos_char[1] += moved;			  //normal move
	//drawCharacter();
}

char lecturaFlancRC0() {
	if (LEFT && (button_cd || game_status != PLAYING)) {
			__delay_ms(10);
			button_cd = 0;
			if (LEFT) return 1;
	}
	return 0;
}

char lecturaFlancRC1() {
	if (RIGHT && (button_cd || game_status != PLAYING)) {
			__delay_ms(10);
			button_cd = 0;
			if (RIGHT) return 1;
	}
	return 0;
}
		
void InitGLCD() {

	//GLCD
	ANSELD=0;                  //PORTD configurat com Digital
	ANSELB=0;                  //PORTB configurat com Digital
	PORTD=0; 		   //Donem uns valors inicials als ports
	PORTB=0;  
	TRISD=0x00;		   //Configurem D i B de sortida
	TRISB=0x00;
	GLCDinit();
	clearGLCD(0,7,0,127);
	setStartLine(0);
	 
	//INTERRUPCIONES
	GIEH = 1;	// ACTIVAMOS LAS INTERRUPCIONES HP
	GIEL = 1;	// ACTIVAMOS LAS INTERRUPCIONES LP
	TXIE = 1;       /* enable transmit interrupt */
    IPEN = 1;		//HABILITAR PRIORIDAD DE INTERRUPCIONES
	RBIE = 1;

    //SENDING INFO  CONFIGURATION
	TXSTA1 = 0x24; /* USART Configuration Register */
	BAUDCON1bits.BRG16 = 1;
	SPBRG1 = 16; /* Set de Baud rate */
	TRISCbits.RC6 = 1; /* configure TX1 pin for output */

	//CONFIGURE BUTTONS
	TRISCbits.RC0 = 0;
	TRISCbits.RC1 = 0;
	ANSELC = 0;

	//CONFIGURE TIMER
	//TMR2IE = 1;
	TMR0ON = 0;
	TMR0IF = 0;
	TMR0IE = 1;
	T08BIT = 0;		//  CONFIGURADO COMO 16BIT TIMER
	T0CS = 0;		//	Fosc/4
	PSA = 0;		// SI PRESCALER
	
	T0PS0 = 0;		
	T0PS1 = 1;		//  1:4 prescaler value
	T0PS2 = 0;	
	TMR0 = 65536 - 25000;	//CONFIGURADO PARA QUE CADA INTERRUPCION SEA 0,1S
	
	RCSTA1bits.SPEN = 1; /* enable USART port */

	CCPR1L = 0; //duty cycle = volume
 
    TMR1ON = 0;
	TMR1IF = 0;
	TMR1IE = 1;
	T1CKPS1 = 1;
	T1CKPS0 = 0;

	TMR1 = 65536 - 35000;	//CONFIGURADO PARA QUE CADA INTERRUPCION SEA 0,1S

	//CONFIGURE AD
	TRISA= 0x01;
	ADCON0 = 0x01; //Equivalente a poner CHS0 ... CHS4 a 0 ADON = 1; 	//modulo de conversion activado
	ADCON1 = 0x00; //default i guess
	
	//ADCON2
	ADFM = 1;	// Justificat a la dreta

	ACQT2 = 0; 
	ACQT1 = 1; // TAD = 4
	ACQT0 = 0;	
	
	ADCS2 = 0; 
	ADCS1 = 0; // Fosc/8
	ADCS0 = 1;	
}

void configureLost()
{
	//disable all the timers
	TMR0ON = 0;
	CCPR1L = 0;
	TMR0IE = 0;
	TMR1ON = 0;
	TMR1IE = 0; 
	//clear the GLCD
	clearGLCD(0,7,0,128);
	//set a new record if it need it
	if(score > record) record = score;
	//int size = strlen(lost_message);
	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 128; ++j)
		{
		writeByte(i,j,lostM[i*128+j]);
		}
	}
	__delay_ms(1500);
	lifes = 3;
	game_status = MENU;
}

//actualize our score
//and start sending if we are not sending already
void actualizeScore()
{
	score += 5;
	if(!send_score)
	{
	//score_string = itoa(score, 
	sprintf(score_string,"%u",score);
	indx = 0;
	send_score = 1;
	TXIE = 1;
	}
	writeNum(0,7,score);
}

//return 1 if we are touching a pic
//return 0 if not
char getScore(int i)
{
	if(pos_pic[2][i] == 1 && (pos_char[0] == pos_pic[0][i] || pos_char[0]+1 == pos_pic[0][i])) //the pic and the char are in the same row and the pic is enable
	{
		if(pos_char[1] <= pos_pic[1][i]+pic_size && pos_char[1]+person_size > pos_pic[1][i]) //only need to compare that
		{
			pos_pic[2][i] = -3;
			return 1;
		}
	}
	return 0;
}

//actualize the life
void actualizeLife()
{
	--lifes;
	if(lifes >= 0)
	{
		writeTxt(0,19+lifes*2,"  ");
		//clearGLCD(0,0,94+lifes*10,127);
	}
}



//HIGH PRIORITY INTERRUPTION
void interrupt /*low_priority */ service_routine_LP (void)
{

	if(TXIE && TX1IF)
     {
		if(send_score) //if we are sending the score
		{
			if(indx == strlen(score_string))
			{
				send_score = 0;
				TXIE = 0;
			}
			else
			{
				TXREG1 = score_string[indx];
				++indx;
			}
		}
		else //if not, we are sending our name
		{
			TXREG1 = nombre[indx];
			++indx;
			if(indx == strlen(nombre)) TXIE = 0;
		}	
     }
	  
      //if we are playing the game
	  if(game_status == PLAYING)
	  {
		if(lifes < 0) configureLost();
		if(lecturaFlancRC0()) 
		{
			moveCharacter('l');
			for(int i = 0; i < 5; ++i) //seeing if the character is touching a pic
			{
				
				if(getScore(i)) 
				{
					clearGLCD(pos_pic[0][i],pos_pic[0][i],pos_pic[1][i],pos_pic[1][i]+pic_size); //if we touch the pic we clear it for cleanest
					actualizeScore();
				}
			}
			drawCharacter();
			
		}
		else if(lecturaFlancRC1())  
		{
			moveCharacter('r');
			for(int i = 0; i < 5; ++i) //see if the character is touching a pic
			{
				if(getScore(i)) 
				{
					clearGLCD(pos_pic[0][i],pos_pic[0][i],pos_pic[1][i],pos_pic[1][i]+pic_size);
					actualizeScore();
				}
			}
			drawCharacter();
			
		}
		if(TMR0IF && TMR0IE) //PICS TIMER
		{
			TMR0IE = 0;
			TMR0IF = 0;
			TMR0 = AD_value*35 + 15000 ;// THE DIFICULTY GOES WITH THE PERCENTAGE OF PINA0
			
			if(counter < 2) ++counter;
			else 
			{
				counter = 0;
				for(int i = 0; i < 5; ++i)
				{
					switch(pos_pic[2][i]) //the pic is enabled
					{
						case 1:
						//clear the pic before one
						clearGLCD(pos_pic[0][i],pos_pic[0][i],pos_pic[1][i],pos_pic[1][i]+pic_size);
						++pos_pic[0][i];
						//see if the pic is in the character
						if(getScore(i))
						{
							actualizeScore();
						}
						//is on the floor = --lifes
						else if(pos_pic[0][i] == 7)
						{
							pos_pic[2][i] = -3;
							actualizeLife();
						}
						else drawPic(i); //if not draw the pic
						break;


						case -4:	//the pic is going to be enable
							pos_pic[0][i] = 1;
							unsigned char correct_pos = 0;
							int pos;
							while(correct_pos == 0)
							{
								pos = rand() % 120;
								correct_pos = 1;
								//for(int j = 0 ; j < 5; ++j) if(j != i && pos_pic[2][j] == 1 &&(pos_pic[1][j] >= pos || pos_pic[1][j]+pic_size >= pos)) correct_pos = 0; 
							}
							pos_pic[1][i] = pos;
							pos_pic[2][i] = 1;	//ENABLE the pic
							drawPic(i);
							break;

						default: //the pic is not enable
						if(score >= i*25) --pos_pic[2][i]; //thats for a raising difficult (the spawn of the pics depends of your score)
						break;
						
					}
				}
			}
			TMR0IE = 1;	//enable the timer again
		}
		if(TMR1IF && TMR1IE)	//CHARACTER timer
		{	
			TMR1IE = 0;
			TMR1IF = 0;
			TMR1 = 65536 - 42500;
			if(button_cd == 0) button_cd = 1;
			TMR1IE = 1;
		}
		if(AD_converter) //Started a ad conversion
		{
			if(!GO)	//finished the GO
			{
			//trato AD
				AD_value = ADRESH & 0x03;
				AD_value =  AD_value << 8; //shift a la izquierda
				AD_value = AD_value | ADRESL; //concatenar n y ADRES	
				AD_converter = 0;
			}
		}
		else	//finished the ad conversion
		{	
			GO = 1;
			AD_converter = 1;
		}		
	}
}



//DRAW OPENING 
void write_opening()
{
	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 128; ++j)
		{
		writeByte(i,j,bitmap[i*128+j]);
		}
	}
}


//DRAW MENU and CONFIGURE IT
configure_menu()
{
	clearGLCD(0,7,0,127);
	
	writeTxt(1,6,"PRESS A BUTTON");
	writeTxt(3,4,"FOR START THE GAME");
	writeTxt(5,6,"RECORD: ");
	writeNum(5,15,record);
	
	game_status = INIGAME;
	__delay_ms(100);
	lifes = 3;
}



//CONFIGURE THE GAME
configure_game()
{
	//CLEAR THE GLCD
	clearGLCD(0,7,0,127);

	//WRITE THE FLOOR BAR

	for(int i = 0; i < 127;++i)	
	{
		writeByte(7,i,0xFF);
	}
	

	//WRITE DEFAULT INFO

	//VARIABLES
	game_status = PLAYING; //2
	score = 0;
	writeTxt(0,0,"POINTS: ");
	writeNum(0,7,score);
	writeTxt(0,13,"LIVES: # # #"); //64 13 == 65

	//PICS TIMER
	CCPR1L = 0;
	TMR0ON = 1;
	TMR0IE = 1;
	TMR0 = 65536 - 45000;
	//CHARACTER TIMER
	TMR1 = 65536 - 45000;	
	TMR1ON = 1;
	TMR1IE = 1;
	//CHARGE DEFAULT CONFIGURATION OF PICS AND CHARACTER
	pos_char[0] = 5;
	pos_char[1] = 60; 
	for(int i = 0; i < 5; ++i)
	{
		pos_pic[0][i] = 1;
		pos_pic[1][i] = 0;
		pos_pic[2][i] = -1;
	}
	drawCharacter();
		
}
	
void main(void){
	InitGLCD();
	write_opening();
	__delay_ms(3000);
	clearGLCD(0,7,0,127);
    while(1)
	{
		switch (game_status)
		{
			case MENU:
				configure_menu();
				break;
			
			case INIGAME:
				if(lecturaFlancRC1() || lecturaFlancRC0()) configure_game();
				break;
			
		}
	}
}
