#include "main.h"
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
    int index = 0, j = 0, num;
    char buffer[1024];
    va_list arguments;

    if (!format)
        return (-1);

    va_start(arguments, format);

    while (format[index] != '\0')
    {
        if (format[index] == '%')
        {
            index++;
            switch (format[index])
            {
                case 'c':
                    j += _putchar(va_arg(arguments, int));
                    break;
                case '%':
                    j += _putchar('%');
                    break;
                case 's':
                    j += print(va_arg(arguments, char *));
                    break;
                case 'd':
                    num = va_arg(arguments, int);
                    if (num == 0)
                    {
                        j += _putchar('0');
                        break;
                    }
                    i_to_str(buffer, num);
                    j += print(buffer);
                    break;
                case 'index':
                    num = va_arg(arguments, int);
                    if (num == 0)
                    {
                        j += _putchar('0');
                        break;
                    }
                    i_to_str(buffer, num);
                    j += print(buffer);
                    break;
                default:
                    j += _putchar(format[index]);
                    break;
            }
        }
        else
        {
            j += _putchar(format[index]);
        }
        index++;
    }
    va_end(argument);
    return (j);
}
