#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void error_y_exit(char *msg,int exit_status)
{
    perror(msg);
    exit(exit_status);
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
            break;
            
            case -1:
            sprintf(buffer, "ERROR AL HACER EL FORK");
            error_y_exit(buffer,1);

            default:
            sprintf(buffer, "Mi PID es %d \n", getpid());
        }
    }
    else
    {
        sprintf(buffer, "Añada unicamente un parámetro \n");
    }
    write(1,buffer,strlen(buffer));
    while(1);
}