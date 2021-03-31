#include <unistd.h>
#include <stdio.h>

int main()
{
    int num;
    char buff[100];
    read(0,&num,sizeof(int));
    sprintf(buff,"%d\n",num);
    write(1,buff,strlen(buff));
}