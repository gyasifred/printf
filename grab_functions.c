#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"


/**
 * get_func - look for the quality
 * @x: variable to the function
 * Return: function
 */
int (*get_func(char x))(va_list)
{
	int i = 0;
	quality arr[] = {
		{"c", print_c},
		{"s", print_s},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_bin},
		{"R", print_rot13},
		{"r", print_revstring},
		{"u", print_u},
		{"o", print_o},
		{"X", print_X},
		{"x", print_x},
		{NULL, NULL}
	};
	while (arr[i].ok)
	{
		if (x == arr[i].ok[0])
			return (arr[i].f);
		i++;
	}
	return (NULL);
}
