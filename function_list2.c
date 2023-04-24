#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

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
