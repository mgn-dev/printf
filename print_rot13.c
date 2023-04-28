#include "main.h"

/**
 * print_rot13 - encrypts the string passed as argument.
 * @args: a copy a the va_list from parent function.
 *
 * Return: number of chars printed.
 */
int print_rot13(va_list args)
{
	char *ulcl = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *code = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i = 0;
	int j;
	char *s = va_arg(args, char *);

	if (s == NULL)
		return (0);

	while (s[i] != '\0')
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == ulcl[j])
			{
				_putchar(code[j]);
				break;
			}
		}

		if (j == 52)
			 _putchar(s[i]);
		i++;
	}

	return (i);
}
