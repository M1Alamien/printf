#include "main.h"
/**
 * get_prec - name
 * @format: string from main
 * @i: int
 * @prnt: list
 *
 * calcs prec for printing
 * Return: prec
 */
int get_prec(const char *format, int *i, va_list prnt)
{
	int ci = *i + 1;
	int prec = -1;

	if (format[ci] != '.')
		return (prec);
	prec = 0;
	for (ci += 1; format[ci] != '\0'; ci++)
	{
		if (is_digit(format[ci]))
		{
			prec *= 10;
			prec += format[ci] - '0';
		}
		else if (format[ci] == '*')
		{
			ci++;
			prec = va_arg(prnt, int);
			break;
		}
		else
			break;
	}
	*i = ci - 1;
	return (prec);
}
