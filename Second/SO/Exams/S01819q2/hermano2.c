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
    int pid, i, n, antecesorpid, res,status;
    char buff[256];
    if (argc != 2) usage();
    
    n = atoi(argv[1]);
    antecesorpid = getpid();

    for(i = 0; i < n; ++i)
    {
        pid = fork();
        if(pid == 0)
        {
            sprintf(buff,"%d",antecesorpid);
            execlp("signal","signal",buff,(char*)NULL);
            error_exit("Error: al execlp", EXIT_FAILURE);
        }
        else if(pid < 0) error_exit("ERROR: en el fork", EXIT_FAILURE);
        antecesorpid = pid;
    }

    while(res = waitpid(-1,&status,0) > 0)
    {
        if(WEXITSTATUS(status))sprintf(buff,"El proceso %d termina con exit code %d\n",res,WEXITSTATUS(status));
        else
        {
            sprintf(buff,"El proceso %d termina con signal code %d\n",res,WTERMSIG(status));
        }
        write(1,buff,strlen(buff));
    }
}