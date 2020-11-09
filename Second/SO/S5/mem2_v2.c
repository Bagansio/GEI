#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#define REGION_SIZE		4096

int *p;

//NO ESTA ACABADO NO ME HA DADO TIEMPO 

void error(int s)
{
	char buff[256];
	sprintf( buff, "%d address of variable p, %d value of variable, addres where the heap of the process ends \n",&p,p,);
	write(1,buff,strlen(buff));
	exit(1);
}

int main(int argc, char *argv[])
{
	int i = 0;
	char buff[256];					

	struct sigaction sa;
	sa.sa_handler = &error;
	sa.sa_flags = SA_RESTART;
	sigfillset(&sa.sa_mask);
	sigaction(SIGSEGV, &sa, NULL);

	sprintf( buff, "Addresses:\n");
	write(1, buff, strlen(buff));	
	sprintf( buff, "\tp: %p\n", &p);
	write(1, buff, strlen(buff));	

	p = malloc(sizeof(int));
	
	if (p == NULL) {
		sprintf(buff, "ERROR en el malloc\n");
		write(2,buff,strlen(buff));
	}

	while (1) {
		*p = i;
		sprintf( buff, "\tProgram code -- p address: %p, p value: %p, *p: %d\n",
		      &p, p, *p);
		write(1, buff, strlen(buff));	
		p++;
		i++;
	}

}
