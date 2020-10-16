#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	isnot_word(char c)
{
	return (c == ' ' || c == '\n' || c == '.' || c == ',');
}

int	countw(char *str)
{
	int	word = 0;
	int count = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if (word == 0 && !isnot_word(str[i]))
		{
			++count;
			word = 1;
		}
		else if (isnot_word(str[i]))
		{
			word = 0;
		}
		++i;
	}
	return (count);
}

int main(int argc, char *argv[])
{
	if (argc >= 2) {
		printf("%i palabras\n", countw(argv[1]));
	}
	return 0;
}