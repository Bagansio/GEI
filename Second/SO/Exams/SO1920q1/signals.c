#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int pidpadre;
void usage()
{
    char buff[256];
    sprintf(buff,"usage: signals NumeroDeHijos\n");
    write(1,buff,strlen(buff));
    exit(EXIT_FAILURE);
}

void error_y_exit(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

void trata_alarma(int s)
{
    kill(pidpadre,SIGUSR1);
}

void trata_sigusr1(int s)
{

}

int main(int argc, char *argv[])
{
    int pid, res, hijos, i;
    char buff[256];
    struct sigaction sa,sa2;
    sigset_t mask;

    
    if(argc != 2) usage();

    pidpadre = getpid(); //Para que el hijo pueda enviar la señal al padre
    
    // CONFIGURAMOS SIGUSR1
    sa.sa_handler = &trata_sigusr1;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);

     if (sigaction(SIGUSR1, &sa, NULL) < 0) error_y_exit("sigaction");

    // CONFIGURAMOS SIGALRM (para que envie SIGUSR1 al padre)
    sa2.sa_handler = &trata_alarma;
    sa2.sa_flags = SA_RESTART;
    sigfillset(&sa2.sa_mask);

     if (sigaction(SIGALRM, &sa2, NULL) < 0) error_y_exit("sigaction");


    hijos = atoi(argv[1]);

    for(i = 0; i < hijos; ++i)
    {
        pid = fork();
        if(pid == 0)    //HIJO
        {
            sprintf(buff,"Mi PID es %d\n",getpid());
            write(1,buff,strlen(buff));
            alarm(1);

            //BLOQUEAMOS ESPERANDO LA SEÑAL ALARM
            sigfillset(&mask);
            sigdelset(&mask, SIGALRM);
            sigdelset(&mask, SIGINT);
            sigsuspend(&mask);


            exit(EXIT_SUCCESS);
        }
        else    //PADRE
        {
            //BLOQUEAMOS ESPERANDO LA SEÑAL SIGUSR1

            sigfillset(&mask);
            sigdelset(&mask, SIGUSR1);
            //sigdelset(&mask, SIGINT);
            sigsuspend(&mask);
        }
    }
    
}