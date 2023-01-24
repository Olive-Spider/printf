#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - function to immitate printf
 * @format: parameters for _printf
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int len = 0;
	char tempchar;
	char *tempstr;

	va_list ap;

	va_start(ap, format);

	for (; format[len] != '\0'; len++)
	{
		fputc(format[len], stdout);

		if (format[len] == '%')
		{
			len++;
			switch (format[len])
			{
				case 'c':
				tempchar = va_arg(ap, int);
				fputc(tempchar, stdout);
				break;
				case 's':
				tempstr = va_arg(ap, char *);
				fputs(tempstr, stdout);
				break;
			}
		}
	else
		fputc(format[len], stdout);
	}

	va_end(ap);
	return (len);
}
