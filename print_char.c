#include "main.h"

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
