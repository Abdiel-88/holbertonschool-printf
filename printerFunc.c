#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
* printChar - prints to standard output
* @letter: recive char
*
* Return: the amount of values printed
*/
int printChar(char letter)
{
	write(1, &letter, 1);
	return (1);
}
/**
* printStr - prints to standard output
* @word: recive string
*
* Return: the amount of values printed
*/
int printStr(char *word)
{
	int i;

	for (i = 0; word[i] != '\0'; i++)/*iterates the word and prints it*/
	{
		write(1, &word[i], 1);
	}
	return (i);
}
/**
* printPercent - prints to standard output
*
* Return: the amount of values printed
*/
int printPercent(void)
{
	write(1, "%", 1);
	return (1);
}
/**
 * printDeci - prints a int as char to standar output
 * @num: number to print
 *
 * Return: the amount of values printed
 */
int printDeci(int num)
{
	int count = 0;
	char digit;/* grabs the last digit of num */

	if (num < 0)/* prints a - if negative and turns num into positive*/
	{
		num = (num * -1);
		write(1, "-", 1);
		count++;
	}
	if (num > 9)/* save guard so recursion doesnt infinitly loop*/
	{
		/* num / 10 this takes out the last digit of num*/
		count = count + printDeci(num / 10);
		/*calls itself till only 1 digit is left*/
	}
	digit = '0' + (num % 10);
	write(1, &digit, 1);/* prints the last digit*/
	return (count + 1);/*sums all the times it call itself*/
}
/**
 * printReg - prints the recive char to stdoutput
 * @letter: recive char
 *
 * Return: the count of value printed
 */
int printReg(char letter)
{
	write(1, &letter, 1);
	return (1);
}
