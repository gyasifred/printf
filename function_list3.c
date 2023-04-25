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
 * _print_hex - helper function to print a hex number recursively
 * @n: the number to be printed
 * @hex: the base of the hex number
 * @alpha: Char 'A' to 'F' or 'a' to 'f'
 * Return: the number of characters printed
 */
int _print_hex(unsigned int n, unsigned int hex, int alpha)
{
	unsigned int i = n % hex;
	unsigned int j = n / hex;
	char c;

	if (i > 10)
	{
		c = (i - 10) + alpha;
	}
	else
	{
		c = i + '0';
	}
	if (j == 0)
		return (_putchar(c));
	if (j < hex)
	{
		if (j > 10)
			return (_putchar(j - 10 + alpha) + _putchar(c));
		return (_putchar(j + '0') + _putchar(c));
	}
	return (_print_hex(j, hex, alpha) + _putchar(c));
}

/**
 * print_x - prints the lowercase hex
 * @args: character argument
 * Return: the number of digits printed
 */

int print_x(va_list args)
{
	return (_print_hex(va_arg(args, unsigned int), 16, 'a'));
}
/**
 * print_X - prints the uppercase hex
 * @args: the arg
 * Return: return the number of digits
 */

int print_X(va_list args)
{
	return (_print_hex(va_arg(args, unsigned int), 16, 'A'));
}

