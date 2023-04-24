#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "main.h"

/**
 * get_func - look for the quality
 * @x: variable to the function
 * Return: function
 */
int formatIdentifier(char next, va_list arg)
{
	int i;
	quality arr[] = {
		{"c", print_c},
		{"s", print_s},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_bin},
		{NULL, NULL}
	};
	for (i = 0; arr[i].ok != NULL; i++)
	{
		if (arr[i].ok[0] == next)
			return (arr[i].f(arg));
	}
	return (0);
}

/**
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i;
	int identifierPrinted = 0, charPrinted = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			charPrinted++;
			continue;
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			charPrinted++;
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);

		identifierPrinted = formatIdentifier(format[i + 1], arg);
		if (identifierPrinted == -1 || identifierPrinted != 0)
			i++;
		if (identifierPrinted > 0)
			charPrinted += identifierPrinted;

		if (identifierPrinted == 0)
		{
			_putchar('%');
			charPrinted++;
		}
	}
	va_end(arg);
	return (charPrinted);
}
