#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>

/**
 * print_c - prints character
 * @args: character argument
 * Return: number of characters
 */
int print_c(va_list args)
{
	int c;

	c = va_arg(args, int);
	return (_putchar(c));
}
/**
 * print_s - prints a string
 * @args: string  argument
 * Return: number of characters
 */
int print_s(va_list args)
{
	int i, count = 0;
	char *str;

	i = 0;
	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
		count++;
	}
	return (count);
}
/**
 * print_percent - prints the percent sign
 * @args: string  argument
 * Return: return the percent sign
 *
 */
int print_percent(va_list args)
{
	char *str;

	str = "%";
	if (va_arg(args, int) == *str)
	{
		return (*str);
	}
	return (*str);
}
/**
  *print_integer - print integer values to stdout
  *@args:string argument
  *Return: return integer value to stdout
  */
int print_integer(va_list args)
{
	int a, divisor = 1, num = 0;
	unsigned int n;

	a = va_arg(args, int);

	if (a < 0)
	{
		num = num + _putchar('-');
		n = a * -1;
	}
	else
		n = a;
	while (n / divisor > 9)
		divisor *= 10;

	while (divisor != 0)
	{
		num = num + _putchar(n / divisor + '0');
		n = n % divisor;
		divisor = divisor / 10;
	}
	return (num);
}

/**
  *print_bin - Print integers in base 2 to stdout
  *@arggs: string arguments
  *Return: return base 2 of the integer
  */
int print_bin(va_list args)
{
	int i, j = 0;
	int *arr;
	unsigned int a = va_arg(args, unsigned int);
	unsigned int tmp = a;

	while (a / 2!= 0)
	{
		a /= 2;
		j++;
	}
	j++;
	arr = malloc(sizeof(unsigned int) * j);
	if (arr == NULL)
	{
		free(arr);
		return (0);
	}
	for (i = 0; i < j; i++)
	{
		arr[i] = tmp % 2;
		tmp /= 2;
	}
	for (i = j - 1; i >= 0; i--)
	{
		_putchar(arr[i] + 48);
	}
	free(arr);
	return (j);
}
