#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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
    if (argc == 2)
    {
        int pid = fork();
        switch(pid)
        {
            case 0:

            sprintf(buffer, "Mi PID es %d y el usuario es %s \n", getpid(), argv[1]);
            write(1,buffer,strlen(buffer));
            muta_a_PS(argv[1]);
            break;

            case -1:
            error_y_exit("ERROR AL HACER EL FORK",1);

            default:
            sprintf(buffer, "Mi PID es %d \n", getpid());
            write(1,buffer,strlen(buffer));
        }
    }
    else
    {
        sprintf(buffer, "Añada unicamente un parámetro \n");
        write(1,buffer,strlen(buffer));
    }
    while(1);
}