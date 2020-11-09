#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

void usage()
{
    char buff[256];
    sprintf(buff,"usage: hermano NumeroDeHijos\n");
    write(1,buff,strlen(buff));
    exit(EXIT_FAILURE);
}

void error_exit(char *msg, int status)
{
    perror(msg);
    exit(status);
}

int main(int argc, char *argv[])
{
    int pid, i, n, antecesorpid, res;
    char buff[256];
    if (argc != 2) usage();
    
    n = atoi(argv[1]);
    antecesorpid = getpid();

    for(i = 0; i < n; ++i)
    {
        pid = fork();
        if(pid == 0)
        {
            sprintf(buff,"El PID de mi antecesor es %d\n", antecesorpid);
            write(1,buff,strlen(buff));
            exit(EXIT_SUCCESS);
        }
        else if(pid < 0) error_exit("ERROR: en el fork", EXIT_FAILURE);
        antecesorpid = pid;
    }

    while(res = waitpid(-1,NULL,0) > 0);
}