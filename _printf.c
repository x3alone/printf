#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);

/**
 * _printf - prints a formated string to output stream
 *  @format: the format string
 *
 *  Return: number of characters printed, otherwise (-1).
 */

int _printf(const char *format, ...)
{
    int i = 0, l = 0, num;
    char buffer[1024];
    va_list args;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    l += _putchar(va_arg(args, int));
                    break;
                case '%':
                    l += _putchar('%');
                    break;
                case 's':
                    l += print(va_arg(args, char *));
                    break;
             :x   case 'd':
                    num = va_arg(args, int);
                    if (num == 0)
                    {
                        l += _putchar('0');
                        break;
                    }
                    i_to_str(buffer, num);
                    l += print(buffer);
                    break;
                case 'i':
                    num = va_arg(args, int);
                    if (num == 0)
                    {
                        l += _putchar('0');
                        break;
                    }
                    i_to_str(buffer, num);
                    l += print(buffer);
                    break;
                default:
                    l += _putchar(format[i]);
                    break;
            }
        }
        else
        {
            l += _putchar(format[i]);
        }
        i++;
    }
    va_end(args);
    return (l);
}
