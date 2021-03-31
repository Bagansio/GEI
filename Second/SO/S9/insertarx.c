#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


void error_y_exit(char* msg,int error_status) {
	perror(msg);
	exit(error_status);
}

int main()
{
    char b[256];
    char b2[256];
    int file = open("salida.txt",O_RDWR);
    if(file == -1) error_y_exit("ERROR: al abrir el archivo",1); 


    lseek(file,-1,SEEK_END);      //cursor a la penultima posicion
    read(file,b,sizeof(char));    //read del ultimo caracter

    lseek(file,-1,SEEK_CUR);      //ponemos el cursor apuntando el ultimo caracter
    sprintf(b2,"X");            //cargamos b2 con una x

    write(file,b2,strlen(b2));    //sobrescribimos el ultimo caracter con una X
    write(file,b,strlen(b));      //escribimos el ultimo caracter del archivo original despues de la  x quedando .... -> ...X.
    //close(file);      deberia cerrarlo o es redundante?
}