#include "main.h"

/**
 * print_binary - function that prints and converts
 * unsigned int to binary.
 * @args: object that is a pointer to an argument list.
 *
 * Return: number of characters printed.
*/
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	unsigned int j = num;
	char *str = NULL;
	int i, len, count = 0;

	if (num == 0)
	{
		count = write(1, "0", 1);
		return (count);
	}

	for (len = 0; j > 0; len++)
		j /= 2;

	str = malloc(sizeof(char) * (len + 1));

	if (str == NULL)
		return (0);

	for (i = (len - 1); i >= 0 ; i--)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		num /= 2;
	}
	str[len] = '\0';

	count = write(1, str, len);

	free(str);

	return (count);
}
