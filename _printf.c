#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function to handle c, s, and % specifiers.
 * @format: Format string containing the directives.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...) {
    int count = 0;
    int i, j;
    va_list args;
    va_start(args, format);

    if (format == NULL) { /* checks if format string is NULL */
        return 0;
    }

    i = 0;
    while (format && format[i]) {
        if (format[i] == '%') {
	  i++; /* checks the next character after % */

            switch (format[i]) {
                case 'c': {
                    char c = (char)va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char*);
                    if (s == NULL) s = "(null)";
                    j = 0;
                    while (s[j]) {
                        write(1, &s[j], 1);
                        count++;
                        j++;
                    }
                    break;
                }
                case '%': {
                    write(1, &format[i], 1);
                    count++;
                    break;
                }
                default: {
                    break;
                }
            }
        } else {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }

    va_end(args);
    return count;
}
