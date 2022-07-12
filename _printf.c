#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - function entry point
 * @format: string specifier
 * @...: variable argument lis
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	unsigned int len = 0;
	va_list arg_list;
	const char *ptr, *str;
	/*
		 conv_type func[] = {
		 {'%': print_conv_spfr},
	}
	*/

	va_start(arg_list, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == '\0' && !format[2])
		return (-1);
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
			{
				putchar(va_arg(arg_list, int));
				len++;
			}
			else if (*ptr == 's')
			{
				str = va_arg(arg_list, char *);
				while (*str != '\0')
				{
					putchar(*str);
					str++;
					len++;
				}
			}
			else if	(*ptr == '%')
			{
				int x = 45, y = 90;
				printf("%d\n", x);
				printf("%i\n", x);
			}
			
		}
		else
		{
			putchar(*ptr);
			len++;
		}
	}
	va_end(arg_list);

	return (len);
}
