#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char c);

/**
 * struct - a struct that defines the conversion specifier
 * @c: format specifier
 * @conv_func: pointer to conversion function
 */
typedef struct conv_sp
{
	char c;
	void (*conv_func)(va_list);
} conv_type;

#endif
