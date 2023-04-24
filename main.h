#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
  * struct partof - the struct tag specifier
  *@ok : the valid char.
  *@f: the functiosn associated
 */
typedef struct partof
{
	char *ok;
	int (*f)(va_list);
} quality;

int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int _putchar(char c);
int print_percent(va_list args);
int print_integer(va_list args);
int print_bin(va_list args);

#endif /* MAIN_H */
