#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void usage()
{
    char *buff[256];
    sprintf(buff,"usage: exam1 nombre_processos(>=0)");
    write(1,buff,strlen(buff));
    exit(EXIT_FAILURE);
}

int main(int argc,char * argv[])
{
    int processos,i,pid;
    if (argc != 2) usage();
    processos = atoi(argv[1]);
    if (processos < 0) usage();
    for(i = 0; i < processos; ++i)
    {
        pid = fork();
    }
}