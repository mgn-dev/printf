#include "main.h"

/**
 * print_string - function that prints string of characters.
 * @args: object that is a pointer to sn argument list.
 *
 * Return: number of characters printed.
*/
int print_string(va_list args)
{
	int len = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	while (str[len] != '\0')
		len++;

	return (write(1, str, len));
}
