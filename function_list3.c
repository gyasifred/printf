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
	int digits[22];
	int args_digits = 0;
	unsigned int num = va_arg(args, unsigned int);
	int i;

	if (num == 0)
	{
		_putchar('0');
		args_digits++;
	}
	else
	{
		while (num != 0)
		{
			digits[args_digits++] = num % 8;
			num /= 8;
		}

		for (i = args_digits - 1; i >= 0; i--)
		{
			_putchar(digits[i] + '0');
		}
	}
	return (args_digits);
}

