#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function to handle c, s, and % specifiers.
 * @format: Format string containing the directives.
 * Return: Number of characters printed.
 */
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...) {
    int count = 0;
    int i;
    va_list args;

    if (!format) {
        return -1;
    }

    va_start(args, format);

    for (i = 0; format[i]; i++) {
        if (format[i] == '%') {
	  i++; /* Check the next character after % */

            switch (format[i]) {
                case 'c': {
                    char c = (char)va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char*);
                    if (!s) s = "(null)";
                    for (int j = 0; s[j]; j++) {
                        write(1, &s[j], 1);
                        count++;
                    }
                    break;
                }
                case '%': {
                    write(1, &format[i], 1);
                    count++;
                    break;
                }
                default: {
		  /* When the format specifier is not valid, backtrack and continue. */
		  i--; /* Backtrack to handle this as a non-format specifier */
                    continue;
                }
            }
        } else {
            write(1, &format[i], 1);
            count++;
        }
    }

    va_end(args);
    return count;
}
