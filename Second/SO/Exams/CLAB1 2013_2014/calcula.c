#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SYSCALL_ERROR 1

int ITERACION_ACTUAL;

// Esta funcion no es relevante, solo pierde tiempo 
void calcula(int i)
{
	int it;
	int fd;
	for (it=0;it<i;it++){
		fd=open("F",O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
		if (fd<0){
			perror("Error en el open");
			exit(SYSCALL_ERROR);
		}
		write(fd,&it,sizeof(it));
		close(fd);
	}
}			

void usage()
{
    char buff[256] ;
    sprintf(buff,"usage: calcula ITERACIONES_MAIN(>0) ITERACIONES_CALCULA(>0) DURACION_MAX(>0)\n");
    write(1,buff,strlen(buff));
    exit(EXIT_FAILURE);
}

void usr1(int s)
{
	char buff[256] ;
    sprintf(buff,"El valor de la variable ITERACION_ACTUAL es: %d\n", ITERACION_ACTUAL);
    write(1,buff,strlen(buff)); 
}

void alrm(int s)
{
	char buff[256] ;
    sprintf(buff,"El valor de la variable ITERACION_ACTUAL es: %d\n", ITERACION_ACTUAL);
    write(1,buff,strlen(buff)); 
	exit(1);
}

void main(int argc,char *argv[])
{
	int i,ITERACIONES_MAIN,ITERACIONES_CALCULA,DURACION_MAX; 
	char b[128];

	if (argc != 4) usage();
	ITERACIONES_MAIN = atoi(argv[1]);
	ITERACIONES_CALCULA = atoi(argv[2]);
	DURACION_MAX = atoi(argv[3]);
	if((ITERACIONES_MAIN < 0) || (ITERACIONES_CALCULA < 0) || (DURACION_MAX < 0)) usage();

	signal(SIGUSR1,usr1);
	signal(SIGALRM,alrm);
	alarm(DURACION_MAX);
	for (i=0;i<ITERACIONES_MAIN;i++){
		ITERACION_ACTUAL=i;
		calcula(ITERACIONES_CALCULA);
	}	
}
