#include "main.h"
#include <stddef.h>

/**
 * _printf - function that produces output according to a format.
 * @format: is a character string.
 * @...: variadic function operator.
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
*/
int _printf(const char *format, ...)
{
	int count = 0, result = 0, i;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			result = handle_specifier(format, args, i);

			if (result == 0)
			{
				if (format[i + 1] == '\0')
					count = -1;
				else
					count += handle_char('%');
			}
			else
			{
				count += result;
				i++;
			}
		}
		else
		{
			count += handle_char(format[i]);
		}
	}

	va_end(args);

	return (count);
}

/**
 * handle_specifier - function to handle a case that a string has
 * format specifers.
 * @format: input string to evaluate.
 * @args: a copy a the va_list from parent function.
 * @index: the current index to the input string.
 *
 * Return: number of chars printed.
*/
int handle_specifier(const char *format, va_list args, int index)
{
	int (*fn_ptr)(va_list);
	int count = 0;

	if (format[index + 1] != '\0')
		fn_ptr = get_fmt_fn(format[index + 1]);

	if (fn_ptr != NULL)
		count = fn_ptr(args);

	return (count);
}

/**
 * handle_char - function to handle a case where
 * an individual character is printed.
 * @curr_char: input string to evaluate.
 *
 * Return: number of chars printed
*/
int handle_char(char curr_char)
{
	return (write(1, &curr_char, 1));
}

/**
* get_fmt_fn - function that selects the correct function to
* use to print.
* @s: format specifier.
*
* Return: pointer to corresponding function.
*/
int (*get_fmt_fn(char s))(va_list)
{
	s_formats ops[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_perc},
		{'d', print_dec},
		{'i', print_int},
	};
	int i = 0;

	while (s != ops[i].s && i < 5)
		i++;

	if (s == ops[i].s)
		return (ops[i].fn);

	return (NULL);
}
