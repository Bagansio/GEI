#include <unistd.h>
#include <stdio.h>
#include <string.h>

int count(char *s)
{
    int c = 0;
    for(int i = 0; s[i] != '\0' && s[i] != '.' && s[i] != ',' && s[i] != '\n'; ++i)
    {
        if (s[i] == ' ' && i == 0 || s[i-1] != '-') ++c;
    }
    return c;
}

int main(int argc, char *argv[])
{
    char buf[500];
    if (argc > 1)
    {
        sprintf(buf, "%d palabras \n", count(argv[1]));
    }
    else 
    {
        sprintf(buf, "0 palabras \n");
    }
    write(1,buf,strlen(buf));
    
}