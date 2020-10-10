#include <unistd.h>


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

int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; ++i) {
		if (esNumero(argv[i])) {
			write(1, "ES NUMERO\n", 10);
		}
		else {
			write(1, "NO ES NUMERO\n", 13);
		}
	}
}