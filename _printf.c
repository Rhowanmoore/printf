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
	/*	conv_type func[] = {
	 	{'%': print_conv_spfr},
	}*/

	va_start(arg_list, format);
	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
			{
				_putchar(va_arg(arg_list, int));
				len++;
			}
			else if (*ptr == 's')
			{
				str = va_arg(arg_list, char *);
				while (*str != '\0')
				{
					_putchar(*str);
					str++;
					len++;
				}
			}
		}
		else
		{
			_putchar(*ptr);
			len++;
		}
	}
	va_end(arg_list);

	return (len);
}

/* Main function just for preliminary testing purposes*/
int main(void)
{
	int x, y;
	char a = 'M';
	char b[] = "Michael";

	x = _printf("Hello, %c, %s\n", a, b);
	y = printf("Hello, %c, %s\n",a, b);
	printf("%d, %d\n", x, y);
	return (0);
}
