#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);

/**
 * _printf - prints a formatted string to the output stream
 * @format: the format string
 *
 * Return: number of characters printed, otherwise (-1).
 */
int _printf(const char *format, ...)
{
	int index = 0, printed_chars = 0, num;
	char buffer[1024];
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			switch (format[index])
			{
				case 'c':
					printed_chars += putchar(va_arg(args, int));
					break;
				case '%':
					printed_chars += putchar('%');
					break;
				case 's':
					printed_chars += puts(va_arg(args, char *));
					break;
				case 'd':
					num = va_arg(args, int);
					if (num == 0)
					{
						printed_chars += putchar('0');
						break;
					}
					snprintf(buffer, sizeof(buffer), "%d", num);
					printed_chars += fputs(buffer, stdout);
					break;
				case 'i':
					num = va_arg(args, int);
					if (num == 0)
					{
						printed_chars += putchar('0');
						break;
					}
					snprintf(buffer, sizeof(buffer), "%d", num);
					printed_chars += fputs(buffer, stdout);
					break;
				default:
					printed_chars += putchar(format[index]);
					break;
			}
		}
		else
		{
			printed_chars += putchar(format[index]);
		}
		index++;
	}
	va_end(args);
	return (printed_chars);
}
