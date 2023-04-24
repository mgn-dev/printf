#include "main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	int i = 0, j, len = 0;
	va_list args;

	dispatcher d[] = {
		{"%s", printf_string},
		{"%c", printf_char},
		{"%i", printf_int},
		{"%d", printf_dec},
	};
	va_start(args, format);
	if (!format)
		return (-1);
start:
	while (format[i] != '\0')
	{
		j = 3;
		while (j >= 0)
		{
			if (d[j].identifier[0] == format[i] && d[j].identifier[1] == format[i + 1])
			{
				len += d[j].func(args);
				i = i + 2;
				goto start;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}

