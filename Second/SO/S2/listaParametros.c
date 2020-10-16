#include <unistd.h>
#include <stdio.h>
#include <string.h>

void Usage()
{
	char buf[500];
	sprintf(buf,"Usage:listaParametrosarg1 [arg2..argn] \n Este programa escribe por su salida la lista de argumentos \n que recibe \n");
	write(1,buf,strlen(buf));
}

int main(int argc,char *argv[])
{
	char buf[80];
	if (argc < 2) Usage();
	else 
	{
		for (int i=0;i<argc;i++){
			if (i==0) {
				sprintf(buf,"El argumento %d es %s (es el nombre del ejecutable)\n",i,argv[i]);
			}
			else {
				sprintf(buf,"El argumento %d es %s\n",i,argv[i]);
			}
			write(1,buf,strlen(buf));
		}
	}
	return 0;
}