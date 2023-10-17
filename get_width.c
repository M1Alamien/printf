#include "main.h"
/**
 * get_width - name
 * @fomat: string from main
 * @i: int
 * @prnt: list
 *
 * calcs width
 * Return: width
 */
int get_width(const char *format, int *i, va_list prnt)
{
	int ci, width = 0;

	for (ci = *i + 1; format[ci] != '\0'; ci++)
	{
		if (is_digit(format[ci]))
		{
			width *= 10;
			width += format[ci] - '0';
		}
		else if (format[ci] == '*')
		{
			ci++;
			width = va_arg(prnt, int);
			break;
		}
		else
			break;
	}
	*i = ci - 1;
	return (width);
}
