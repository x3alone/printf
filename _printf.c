#include "main.h"
#include <stdarg.h>

int _printf(const char *format, ...);

/**
 * _printf - prints a formated string to output stream
 *  @format: the format string
 *
 *  Return: number of characters printed, if not return (-1).
 */

int _printf(const char *format, ...)
{
    int i = 0, y = 0, num;
    char buffer[1024];
    va_list arguments;

    if (format == NULL)
        return (-1);

    va_start(argarguments, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    y += _putchar(va_arg(arguments, int));
                    break;
                case '%':
                    y += _putchar('%');
                    break;
                case 's':
                   y += print(va_arg(arguments, char *));
                    break;
                case 'd':
                    num = va_arg(arguments, int);
                    if (num == 0)
                    {
                        y += _putchar('0');
                        break;
                    }
                    i_to_str(buffer, num);
                    y += print(buffer);
                    break;
                case 'i':
                    num = va_arg(arguments, int);
                    if (!num)
                    {
                        y += _putchar('0');
                        break;
                    }
                    i_to_str(buffer, num);
                    y += print(buffer);
                    break;
                default:
                    y += _putchar(format[i]);
                    break;
            }
        }
        else
        {
            y += _putchar(format[i]);
        }
        i++;
    }
    va_end(arguments);
    return (y);
}
