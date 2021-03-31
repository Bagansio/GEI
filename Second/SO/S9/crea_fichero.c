#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void error_y_exit(char* msg,int error_status) {
	perror(msg);
	exit(error_status);
}

int main()
{
    char b[256];
    int file = creat("salida.txt",O_CREAT|O_TRUNC|0600);   //S_IRUSR  00400 user has read permission + S_IWUSR  00200 user has write permission 
    if (file == -1) error_y_exit("ERROR: creando el archivo -salida.txt-", 1);
    sprintf(b,"ABCD");
    write(file,b,strlen(b)); 
}