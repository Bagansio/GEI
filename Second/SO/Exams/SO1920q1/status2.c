#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void usage()
{
    char buff[256];
    sprintf(buff,"usage: status PID1 [....... PID10]\n");
    write(1,buff,strlen(buff));
    exit(EXIT_FAILURE);
}

void error_exit(char* msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

void transform_grep(char *pid)
{
    execlp("grep","grep","State",pid,(char*)NULL);
    error_exit("Ha fallado la mutacion al grep");
}

int main(int argc,char *argv[])
{
    char buff[256];
    int i,pid,res;
    if (argc < 2 || argc > 11) usage(); //COMPROBAMOS QUE HEMOS PUESTO 10 ELEMENTOS
    for(i = 1; i < argc; ++i)
    {
        pid = fork();
        switch(pid)
        {
            case 0: //EL HIJO

                //Decimos que proceso vamos a ver su estado
                sprintf(buff,"Estado del proceso %s:\n",argv[i]);
                write(1,buff,strlen(buff));

                //Hacemos el grep
                sprintf(buff,"/proc/%s/status",argv[i]);
                transform_grep(buff);

            case -1: //SI FALLA EL FORK
            error_exit("ERROR AL HACER EL FORK");

            default: //EL PADRE
            waitpid(pid,&res,0); //ESPERAMOS QUE ACABE EL HIJO
            if (res != EXIT_SUCCESS) //SINO HA ACABO BIEN
            {
                sprintf(buff,"Proceso %s no existe\n", argv[i]);
                error_exit(buff);
            }
        }
    }
}