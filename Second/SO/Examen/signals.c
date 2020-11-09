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
    sprintf(buff,"usage: signals NumeroProcesosHijo(>0 && <= 10)\n");
    write(1,buff,strlen(buff));
    exit(EXIT_FAILURE);
}

void error_y_exit(char *msg, int status)
{
    perror(msg);
    exit(status);
}

void f_signals(int s)
{
    if(s == SIGALRM)
    {
        char buff[256];
        sprintf(buff,"%d: Timeout\n",getpid());
        write(1,buff,strlen(buff));
        exit(EXIT_SUCCESS);
    }
    if(s == SIGUSR1)
    {
        exit(alarm(0));
    }
}
int main(int argc, char *argv[])
{
    int pid, i,res,hijos,status;
    char buff[256];
    struct sigaction sa;
    sigset_t mask;
    
    if(argc != 2) usage();

    // Bloqueamos signals
    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM);
    sigaddset(&mask, SIGUSR1);
	sigprocmask(SIG_BLOCK, &mask, NULL);

    hijos = atoi(argv[1]);
    int pidHijos[hijos];
    
    // Reprogramamos  SIGALRM
    sa.sa_handler = &f_signals;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);
    if (sigaction(SIGALRM, &sa, NULL) < 0) error_y_exit("sigaction",EXIT_FAILURE);
    if (sigaction(SIGUSR1, &sa, NULL) < 0) error_y_exit("sigaction",EXIT_FAILURE);
    
    if(hijos < 0 || hijos > 10) usage();
    for(i = 0; i < hijos; ++i)
    {
        pid = fork();
        if (pid == 0) //HIJO
        {
            alarm(3);

            //BLOQUEAMOS HASTA RECIBIR LA SEÑAL ALARM
            sigfillset(&mask);
            sigdelset(&mask, SIGALRM);
            sigdelset(&mask,SIGUSR1);   
            sigdelset(&mask, SIGINT);
            sigsuspend(&mask);
            error_y_exit("ERROR: al mutar a touch",EXIT_FAILURE);
        }
        if(pid < 0) error_y_exit("ERROR: al hacer el fork",EXIT_FAILURE);
        else pidHijos[i] = pid;
    }
    for(i = 0; i < hijos; ++i)
    {
        if(pidHijos[i] % 2 == 0) //pid del hijo par
        {
            kill(pidHijos[i],SIGUSR1);
        }
    }
    while(hijos > 0)
    {
        if((res = waitpid(-1,&status,0)) < 0) error_y_exit("ERROR: al hacer la espera del hijo(waitpid)",EXIT_FAILURE);
        {
            if(res % 2 == 0) 
            {
                sprintf(buff,"Hijo %d, Segundos restantes %d\n",res,WEXITSTATUS(status));
                write(1,buff,strlen(buff));
            }
            --hijos;
        }
    }
}
