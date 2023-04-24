#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
/**
 * struct format - dispatch to specified print function
 * @identifier: type char identifier (d, i, s, c)
 * @func: type pointer to print function
 **/

typedef struct format
{
	char *identifier;
	int (*func)();
} dispatcher;

int _printf(const char *format, ...);
int _putchar(char c);
int printf_int(va_list args);
int printf_dec(va_list args);

#endif
