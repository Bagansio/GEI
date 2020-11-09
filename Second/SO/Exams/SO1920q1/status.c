#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void usage()
{
    char buff[256];
    sprintf(buff,"usage: status PID1 [....... PIDn]\n");
    write(1,buff,strlen(buff));
    exit(EXIT_FAILURE);
}

void error_exit(char* msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

void muta_grep(char *pid)
{
    execlp("grep","grep","State",pid,(char*)NULL);
    error_exit("Ha fallado la mutacion al grep");
}

int main(int argc,char *argv[])
{
    char buff[256];
    int i,pid;
    if (argc == 1) usage();
    for(i = 1; i < argc; ++i)
    {
        pid = fork();
        switch(pid)
        {
            case 0:
                sprintf(buff,"/proc/%s/status",argv[i]);
                muta_grep(buff);

            case -1:
            error_exit("ERROR AL HACER EL FORK");

            default:
            waitpid(pid,NULL,0);
        }
    }
}