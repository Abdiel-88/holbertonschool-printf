#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function to handle c, s, and % specifiers.
 * @format: Format string containing the directives.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...) {
    if (!format) {
        return -1;
    }

    int count = 0;
    int i, j;
    va_list args;
    va_start(args, format);

    for (i = 0; format[i]; i++) {
        if (format[i] == '%') {
            if (!format[i + 1]) {
	      /* If '%' is the last character, print it and break the loop */
                write(1, &format[i], 1);
                count++;
                break;
            }

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
                    for (j = 0; s[j]; j++, count++) {
                        write(1, &s[j], 1);
                    }
                    break;
                }
                case '%': {
                    write(1, &format[i], 1);
                    count++;
                    break;
                }
                default: {
		  /* Print the '%' and the current character, then continue */
                    write(1, &format[i - 1], 1);
                    write(1, &format[i], 1);
                    count += 2;
                    break;
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
