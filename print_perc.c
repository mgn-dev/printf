#include "main.h"

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
