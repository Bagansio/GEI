#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void error_y_exit(char *msg,int exit_status)
{
    perror(msg);
    exit(exit_status);
}

/* Ejecuta el comando ps –u username mediante la llamada al sistema execlp */
/*Devuelve: el código de error en el caso de que no se haya podido mutar */
void muta_a_PS(char *username)
{
    execlp("ps", "ps", "-u", username, (char*)NULL);
    error_y_exit("Ha fallado la mutación al ps", 1);
} 

int main(int argc,char *argv[])
{
    char buffer[300];
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            int pid = fork();
            switch(pid)
            {
                case 0:

                sprintf(buffer, "Mi PID es %d y el usuario es %s \n", getpid(), argv[i]);
                write(1,buffer,strlen(buffer));
                exit(0);
                muta_a_PS(argv[i]);
                break;

                case -1:
                error_y_exit("ERROR AL HACER EL FORK",1);

                default:
                waitpid(-1, NULL, 0);
                sprintf(buffer, "Mi PID es %d \n", getpid());
                write(1,buffer,strlen(buffer));
            }
        }
        
    }
    else
    {
        sprintf(buffer, "Añada unicamente un parámetro \n");
        write(1,buffer,strlen(buffer));
    }
}