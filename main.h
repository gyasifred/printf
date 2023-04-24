#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

typedef fmt
{
	char *type;
	int (*f)(va_list);
}fmt_t;
int _printf(const char *format, ...);
int _putchar(char c);



#endif /* MAIN_H */
