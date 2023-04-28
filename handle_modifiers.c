#include "main.h"

/**
 * handle_modifiers - function that formats the string
 * according to the modifiers.
 * @format: the string to print.
 * @index: index to beginning of specifier.
 *
 * Return: number of characters printed.
*/
int handle_modifiers(const char *format, int index)
{
    if (get_specifier_index(format) == -1)

    if (format[index + 1] == "+")
    {
        count += handle_flags(format, index);
        count += handle_length(format, index);
        count += handle_width(format, index);
        count += handle_precision(format, index);
        count += handle_length(format, index);
    }

    return (0);
}

int get_specifier_index(const char *format, int index)
{
    char s[][] = {
        {'d', 'i', 'o', 'u', 'x', 'X', 0, 0}, /* + flag modifier */
        {'o', 'x', 'X', 0, 0, 0, 0, 0}, /* # flag modifier */
        {'d', 'i', 'o', 'u', 'x', 'X', 'c', 's'}, /* - flag modifier*/
        {'d', 'i', 'o', 'u', 'x', 'X', 0, 0}, /* 0 flag modifier */
        {'d', 'i', 'o', 'u', 'x', 'X', 0, 0}, /* h, l length modifiers */
        {'d', 'i', 'o', 'u', 'x', 'X', 'c', 's'}, /* field width modifier */
        {'s', 0, 0, 0, 0, 0, 0, 0} /* precision modifier */
    };


}