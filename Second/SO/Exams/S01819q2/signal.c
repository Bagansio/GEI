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
    sprintf(buff,"usage: signal PID\n");
    write(1,buff,strlen(buff));
    exit(EXIT_FAILURE);
}

void error_exit(char *msg, int status)
{
    perror(msg);
    exit(status);
}

void alrm(int s)
{
}

int main(int argc, char *argv[])
{
    int pid, i, n, status;
    char buff[256];
    struct sigaction sa;
    sigset_t mask;

    if (argc != 2) usage();
    // Block signals
    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM);
	sigprocmask(SIG_BLOCK, &mask, NULL);

    // Reprogram SIGCHILD SIGALRM
    sa.sa_handler = &alrm;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);
    if (sigaction(SIGALRM, &sa, NULL) < 0) error_exit("sigaction",EXIT_FAILURE);

    alarm(1);
    //BLOQUEAMOS HASTA RECIBIR UNA DE LAS SEÑALES
    sigfillset(&mask);
    sigdelset(&mask, SIGALRM);
    sigdelset(&mask, SIGINT);
    sigsuspend(&mask);

    status = kill(SIGUSR1,pid);
    error_exit("ERROR: PID no encontrado", status);
}
