#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>
#include <ctype.h>

/**
  *print_rot13 - prints the rot13'ed string
  *@args: string argument
  *Return: rot13 of a character example rot13 of a is n
  */
int print_rot13(va_list args)
{
	int i, len;
	char *str;

	len = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if ((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N' && str[i] <= 'Z'))
			{
				len = len + _putchar(str[i] - 13);
			}
			else
				len = len + _putchar(str[i] + 13);
		}
		else
			len = len + _putchar(str[i]);
	}
	return (len);
}
/**
 *print_revstring - Function to reverse string
 *@args: string argument
 *Return: reverse string
 */
int print_revstring(va_list args)
{
	int i;
	char *s;
	int len = 0;

	s = va_arg(args, char *);
	if (s == NULL)
	{
		return (-1);
	}
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		len = len + _putchar(s[i]);
		i--;
	}
	return (len);
}

/**
 * unsignedIntToHex - prints unsigned int to hexadecimal.
 * @num: number to print
 * @_case: letter `a` on the case to print it (upper or lower)
 * Return: number of characters printed
 */
int unsignedIntToHex(unsigned int num, char _case)
{
	unsigned int n;
	int i, j, remainder, len = 0;
	char *num_hex;

	for (n = num; n != 0; len++, n /= 16)
	;

	num_hex = malloc(len);
	for (i = 0; num != 0; i++)
	{
		remainder = num % 16;
		if (remainder < 10)
			num_hex[i] = remainder + '0';
		else
			num_hex[i] = remainder - 10 + _case;
		num = num / 16;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(num_hex[j]);
	free(num_hex);
	return (len);
}

/**
 * print_S - prints a string with a `S` (upper case) specifier
 * @str: argument
 * Return: number of characters printed
 */
int print_S(va_list str)
{
	int i, len = 0;
	char *string = va_arg(str, char*);

	if (string == NULL)
		string = "(null)";
	else if (*string == '\0')
		return (-1);

	for (i = 0; string[i]; i++)
	{
		if ((string[i] < 32 && string[i] > 0) || string[i] >= 127)
		{
			len += _putchar('\\');
			len += _putchar('x');
			if (i < 16)
				_putchar('0');
			len += unsignedIntToHex(string[i], 'A');
		}
		else
		{
			len += _putchar(string[i]);
		}
	}
	return (len);
}

