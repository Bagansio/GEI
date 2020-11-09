#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
int seconds = 0;

void error_y_exit(char* msg, int exit_status)
{
    perror(msg);
    exit(exit_status);
}

void trata_alarma(int s)
{
    if(s == SIGALRM) ++seconds;
    else if (s == SIGUSR1)
    {
        char buff[256];
        sprintf(buff, "Reinicio a 0 segundos\n");
        write(1,buff,strlen(buff));
        seconds = 0;
    }
    else if (s == SIGUSR2)
    {
        char buff[256];
        sprintf(buff, "El proceso lleva %d segundos\n",seconds);
        write(1,buff,strlen(buff));
    }
}

int main(int argc, char* argv[])
{
    struct sigaction sa;
    sigset_t mask;

    sigemptyset(&mask);
    sigaddset(&mask,SIGALRM);
    sigaddset(&mask,SIGUSR1);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    sa.sa_handler = &trata_alarma;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);

    if (sigaction(SIGALRM, &sa, NULL) < 0) error_y_exit("sigaction",1);
    if (sigaction(SIGUSR1, &sa, NULL) < 0) error_y_exit("sigaction",1);
    if (sigaction(SIGUSR2, &sa, NULL) < 0) error_y_exit("sigaction",1);
    
    while(1)
    {
        alarm(1);
        sigdelset(&mask, SIGALRM);
    	sigdelset(&mask, SIGINT);
        sigdelset(&mask, SIGUSR1);
        sigsuspend(&mask);
    }
    exit(1);
}