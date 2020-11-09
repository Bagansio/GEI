#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void usage()
{
    char buff[256] ;
    sprintf(buff,"usage: mstat nom_fitxer1 [nom_fitxer2.. nom_fitxerN]\n");
    write(1,buff,strlen(buff));
    exit(EXIT_FAILURE);
}

void error(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc,char *argv[])
{
    char buff[256];
    int pid, res, res_wp,ec;

    if(argc == 1) usage();
    for(int i = 1; i < argc; ++i)
    {
        int pid = fork();
        if (pid == 0)
        {
            sprintf(buff,"Ejecutamos el comando stat del fichero %s\n", argv[i]);
            write(1,buff,strlen(buff));
            exit(1);
        }
        else if (pid < 0) error("Error: En el fork\n");
        else
        {
            res_wp = waitpid(pid,&res,0);
            if(res_wp < 0)error("Error: En el waitpid\n");
            if(WIFEXITED(res))
            {
                ec = WEXITSTATUS(res);
                if(ec == 0) sprintf(buff,"stat ejecutado correctamente\n");
                else sprintf(buff,"stat ha detectado un problema con el fichero\n");
            }
            write(1,buff,strlen(buff));
        }
    }
}