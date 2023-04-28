#include "main.h"

/**
 * print_rev - reverses the string passed as argument.
 * @args: a copy a the va_list from parent function.
 *
 * Return: number of chars printed.
 */
int print_rev(va_list args)
{
	int len = 0, i;
	char *str;

	str = va_arg(args, char *);

	if (str == NULL)
		return (0);

	while (str[len] != '\0')
		len++;

	for (i = len - 1; i >= 0; i--)
		_putchar(str[i]);

	return (len);
}
