#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>  /* For va_list and related macros */

int _printf(const char *format, ...);
int printChar(char letter);
int printStr(char *word);
int printPercent(void);
int printDeci(int num);
int printReg(char letter);

#endif /* MAIN_H */
