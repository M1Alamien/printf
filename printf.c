#include <stdio.h>
#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * longint - name
 * @n: int from main
 *
 * prints long int using _puchar
 * Return: lenght of int
 */
int longint(int n)
{
	static int c = 1;

	c++;
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
		longint(n / 10);

	_puthcar((n % 10) + '0');
	return (c - 1);
}
/**
 * _printf - name
 * @format: string from main
 *
 * produces output according to a format
 * Return: counter
 */
int _printf(const char *format, ...)
{
	int i, j, k, counter = 0;
	char *s;
	va_list prnt;

	va_start(prnt, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					_putchar(va_arg(prnt, int));
					counter++;
					break;
				case 'd':
					j = va_arg(prnt, int);
					counter += longint(j);
					break;
				case 's':
					s = va_arg(prnt, char *);
					if (s != NULL)
					{
					for (k = 0; s[k]; k++, counter++)
						_putchar(s[k]); }
					break;
				case 'i':
					j = va_arg(prnt, int);
					counter += longint(j);
					break;
				default:
					_putchar(format[i]);
					counter++;
					break; }
			i++; }
		else
		{ putchar(format[i]);
			i++; } }
	va_end(prnt);
	return (counter); }
