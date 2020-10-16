unsigned int char2int(char c)
{
    return c - '0';
}

int mi_atoi(char *s)
{
    int n = 0;
    int i = 0;
    int neg = 0;
    if (s[i] == '-')
    {
        ++s;
        neg = 1;
    }
    while (s[i] != '\0')
    {
        n *= 10;
        n += char2int(s[i]);
        ++i;
    }
    if (neg != 0) n = n - 2 * n;
    return n;
}

int esNumero(char *str)
{
    if (str)
    {
        int i = 0;
        if (str[i] == '-') ++str;
        while (str[i] != '\0')
        {
            if (str[i] < '0' || str[i] > '9') return 0;
            ++i;
        }
        return (i > 0) && (i <= 8);
    }  
    return 0;
}

int Usage(int argc)
{
    if (argc < 2)
    {
        char buf[500];
        sprintf(buf,"Usage:listaParametrosarg1 [arg2..argn] \n Este programa escribe por su salida la lista de argumentos \n que recibe \n");
        write(1,buf,strlen(buf));
        return 1;
    }
    return 0;
}