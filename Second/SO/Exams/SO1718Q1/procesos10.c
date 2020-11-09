#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void usage()
{
    //printf("usage: procesos00 arg1 [arg2 ... argN]\n");
    char buff[256];
    sprintf(buff,"usage: procesos10 command [OPTION1 ... OPTIONn]\n");
    write(1,buff,strlen(buff));
    exit(EXIT_FAILURE);
}

void error_y_acaba(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    int pid,res,i;
    char buff[250];
    if (argc < 2) usage();
    char *programa = argv[1];
    ++argv;

    for(i = 1; i < argc; ++i)
    {
        pid = fork();
        if(pid == 0) //HIJO
        {
            execvp(programa,argv);
            error_y_acaba("ERROR: Al mutar");
        }
        else if(pid < 0) error_y_acaba("ERROR: En el Fork");
    }
    //PADRE (solo llega el)
    //for(i = 1; i < argc; ++i)
    waitpid(pid,NULL,0);    //ESTO PARA ESPERAR A QUE ACABEN TODOS (no se si haría falta)
    printf("El PID del hijo que ha terminado es %d\n", pid);
    while((res = waitpid(-1, NULL, 0)) > 0)
    {
        sprintf(buff, "El PID del hijo que ha terminado es %d\n", res);
        write(1, buff, strlen(buff));
    }   
}