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

/**
 * print_char - function that prints single characters.
 * @args: object that is a pointer to an argument list.
 *
 * Return: number of characters printed.
*/
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_perc - function that prints a % character.
 * @args: object that is a pointer to an argument list.
 *
 * Return: number of characters printed.
*/
int print_perc(va_list args)
{
	(void) args;
	return (write(1, "%%", 1));
}
