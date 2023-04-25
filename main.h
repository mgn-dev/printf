#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct formats - a structure that contains 2 variables
 *
 * @s: the format specifier.
 * @fn: pointer to the corresponding function.
 */
typedef struct formats
{
	char s;
	int (*fn)(va_list args);
} s_formats;

int print_string(va_list args);
int print_char(va_list args);
int print_perc(va_list args);
int print_unsigned(va_list args);
int _putchar(char c);
int print_dec(va_list args);
int print_int(va_list args);
int print_binary(va_list args);

int printf_buffer(const char *str, int *length);

int (*get_fmt_fn(char s))(va_list);
int handle_specifier(const char *format, va_list args_copy, int index);
int handle_char(char curr_char);
int _printf(const char *format, ...);
#endif
