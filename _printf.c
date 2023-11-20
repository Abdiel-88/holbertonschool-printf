#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function to handle c, s, and % specifiers.
 * @format: Format string containing the directives.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...) {
    int count = 0;
    va_list args;
    va_start(args, format);

    for (int i = 0; format && format[i]; i++) {
        if (format[i] == '%') {
	  i++; /* Check the next character after % */

            switch (format[i]) {
                case 'c': {
		  char c = (char)va_arg(args, int); /* char is promoted to int in stdarg */
                    write(1, &c, 1);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char*);
                    if (s == NULL) s = "(null)";
                    for (int j = 0; s[j]; j++, count++) {
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
		  /* Handle an unknown format specifier */
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
