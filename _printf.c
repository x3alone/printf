#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
/**
 * _putchar - writes a single char
 * @c: the character it prints
 * Return: the number of characters written (1)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * handle_string - prints string
 * @str: takes a pointer to a sting
 * Return: the number of characters printed.
 */
int handle_string(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		handle_string("(null)");
		return (i);
	}
	while (str[i])
	{
		_putchar(str[i]);
		i++; }
	return (i);
}
/**
 * _printf - prints a formatted string to the output stream
 * @format: the format string
 * Return: number of characters printed, otherwise return (-1)
 */
int _printf(const char *format, ...)
{
	unsigned int i, count = 0;
	va_list args;

	va_start(args, format);
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				count += _putchar(c);
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);

				count += handle_string(str);
			}
			else if (format[i] == '%')
			{
				_putchar('%');
				count++;
			}
			else
			{
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			count++; }
	}
	va_end(args); }
