#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - Custom printf function to handle c, s, and % specifiers.
 * @format: Format string containing the directives.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	char *s;
	int i, count = 0;
	va_list args;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{/* iterate through format string */
		if (format[i] == '%' && format[(i + 1)] != '\0')
		{
			switch (format[(i + 1)])
			{/* switch cases for each specifier */
				case 'c':
					count = count + printChar((char)va_arg(args, int));
					break;
				case 's':
					s = va_arg(args, char*);
					if (s == NULL)/* checks if s is null */
						s = "(null)";
					count = count + printStr(s);
					break;
				case '%':
					count = count + printPercent();
					break;
				case 'd':/* kinda of a OR statement*/
				case 'i':/* d or i do the same */
					count = count + printDeci(va_arg(args, int));
					break;
				default:/* Print the current character, then continue */
					count = count + printReg(format[i]);
					i--;/*evades the skip ahead only when default*/
			}
			i++;/* skips next index */
		}
		else if (format[i] != '%')/* Print regular characters */
			count = count + printReg(format[i]);
	}
	va_end(args); /* finilize */
	return (count);
}
