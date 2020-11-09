#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int hijos;
int hijospid[5];

void usage()
{
    char buff[256];
    sprintf(buff,"usage: actualizar_fecha NombreFichero1 [NombreFichero2 ... NombreFichero5]\n");
    write(1,buff,strlen(buff));
    exit(EXIT_FAILURE);
}

void error_y_exit(char *msg, int status)
{
    perror(msg);
    exit(status);
}

int busquedargv(int pid)
{
    for(int i = 0; i < hijos; ++i)
    {
        if(hijospid[i] = pid) return i + 1;
    }
}

int main(int argc, char *argv[])
{
    int pid, i,res,hijosRest;
    char buff[256];
    if(argc < 2 || argc > 6) usage();

    hijos = argc - 1;
    hijosRest = hijos;  
    for(i = 1; i < argc; ++i)
    {
        pid = fork();
        if (pid == 0) //HIJO
        {
            execlp("touch","touch",argv[i],(char*)NULL);
            error_y_exit("ERROR: al mutar a touch",EXIT_FAILURE);
        }
        if(pid < 0) error_y_exit("ERROR: al hacer el fork",EXIT_FAILURE);
        else hijospid[i-1] = pid;
    }
    while(hijosRest > 0)
    {
        if((res = waitpid(-1,NULL,0)) < 0) error_y_exit("ERROR: al hacer la espera del hijo(waitpid)",EXIT_FAILURE);
        sprintf(buff,"Fecha %s actualizada por %d\n",argv[busquedargv(res)],res);
        write(1,buff,strlen(buff));
        --hijosRest;
    }
}
