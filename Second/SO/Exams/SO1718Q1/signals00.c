#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int hijos;

void usage()
{
    //printf("usage: procesos00 arg1 [arg2 ... argN]\n");
    char buff[256];
    sprintf(buff,"usage: signals00 command [OPTION1 ... OPTIONn]\n");
    write(1,buff,strlen(buff));
    exit(EXIT_FAILURE);
}

void error_y_acaba(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

void printchild(int pid,int status)
{
    char buff[256];
    if(WEXITSTATUS(status))
    {
        int exitcode = WEXITSTATUS(status);
        sprintf(buff,"El proceso %d termina con exit code %d\n",pid,exitcode);
    }
    else
    {
        int signalcode = WTERMSIG(status);
        sprintf(buff,"El proceso %d termina con signal code %d\n",pid,signalcode);
    }
    write(1,buff,strlen(buff));
}

void f_child(int s)
{
    if (s == SIGCHLD)
    {
        char buff[256];
        int res,status;
        while((res = waitpid(-1, &status, WNOHANG)) > 0)
        {
            printchild(res,status);
            --hijos;
        }
    }
}

int main(int argc, char *argv[])
{
    int pid,res,i;
    char buff[250];
    struct sigaction sa;
    sigset_t mask;

    if (argc < 2) usage();
    char *programa = argv[1];
    ++argv;
    hijos = argc - 1;

    // Block signals
    sigemptyset(&mask);
	sigaddset(&mask, SIGCHLD);
	sigprocmask(SIG_BLOCK, &mask, NULL);

    // Reprogram SIGCHILD
    sa.sa_handler = &f_child;
    sa.sa_flags = SA_RESTART;
    sigfillset(&sa.sa_mask);
    if (sigaction(SIGCHLD, &sa, NULL) < 0) error_y_acaba("sigaction");

    for(i = 1; i < argc; ++i)
    {
        pid = fork();
        if(pid == 0) //HIJO
        {
            // Como el proceso muta, se pierde la reprogramación de los signals
            execvp(programa,argv);
            error_y_acaba("ERROR: Al mutar");
        }
        if(pid < 0) error_y_acaba("ERROR: En el Fork");
    }
    sigprocmask(SIG_UNBLOCK,&mask,NULL);

    while(hijos > 0);

}