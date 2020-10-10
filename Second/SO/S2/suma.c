#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "mis_funciones.h"

int main(int argc, char *argv[]) {
    int suma = 0;
    int error = 0;
    int i = 1;
    if (Usage(argc) == 0)
    {
        while (i < argc && error == 0)
        {
            if (esNumero(argv[i])) {
                suma += mi_atoi(argv[i]);
                ++i;
            }
            else {
                error = 1;
            }
        }
        char buf[250];
        if (error == 0)
        {
            sprintf(buf, "La suma es %d \n", suma);
            write(1, buf, strlen(buf));
        }
        else
        {
            sprintf(buf, "Error: el parámetro (%s) no es un número\n",argv[i]);
            write(1, buf, strlen(buf));
        }
    }
}