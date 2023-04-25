#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

/**
  *print_u - print an unsigned decimal (base 10) argsber
  *@args: the arg
  *Return: the number digits printed
  */

int print_u(va_list args)
{
	int divisor = 1, num = 0;
	unsigned int a;

	a = va_arg(args, unsigned int);

	while (a / divisor > 9)
		divisor *= 10;

	while (divisor != 0)
	{
		num = num + _putchar(a / divisor + '0');
		a = a % divisor;
		divisor = divisor / 10;
	}
	return (num);
}
/**
 * print_o - prints an octal number
 * @args: the argument
 * Return: the number of digits printed
 */

int print_o(va_list args)
{
	int i, len = 0;
	int *arr;
	unsigned int tmp;
	unsigned int num = va_arg(args, unsigned int);

	tmp = num;
	while (num / 8 != 0)
	{
		num /= 8;
		len++;
	}
	len++;
	arr = malloc(sizeof(int) * len);
	if (arr == NULL)
	{
		return (-1);
	}
	i = 0;
	while (tmp != 0)
	{
		arr[i] = tmp % 8;
		tmp /= 8;
		i++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (len);
}

/**
 * printxx - converts the character to hex
 *
 * @args: character argument
 * @casetype: th args case type
 * Return: the number of digits printed
 */
int printxx(unsigned int args, int casetype)
{
	int digits[20];
	int args_digits = 0;
	int i, num;

	for (i = 0; args != 0; i++)
	{
		num = args % 16;
		while (num != 0)
	{
		digits[args_digits++] = num % 16;
		num /= 16;
	}
		args /= 16;
	}

	for (i = args_digits - 1; i >= 0; i--)
	{
		if (digits[i] < 10)
		{
			_putchar(digits[i] + '0');
		}
		else
		{
			if (casetype >= 1)
			{
			_putchar(digits[i] - 10 + 'A');
			}
			else
			{
				_putchar(digits[i] - 10 + 'a');
			}
		}
	}
	return (args_digits);
}

/**
 * print_X - prints the uppercase hex
 * @args: the arg
 * Return: return the number of digits
 */
int print_X(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int j = printxx(num, 1);

	return (j);
}

/**
 * print_x - prints the lowercase hex
 * @args: character argument
 * Return: the number of digits printed
 */
int print_x(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int j = printxx(num, 0);

	return (j);
}
