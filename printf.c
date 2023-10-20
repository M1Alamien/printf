#include "main.h"

void print_buff(char buff[], int *bi);
/**
 * _printf - name
 * @format: string from main
 *
 * printf
 * Return: counter
 */
int _printf(const char *format, ...)
{
	int i, counter = 0, c2 = 0;
	int flags, width, prec, size, bi = 0;
	char buff[BUFF_SIZE];
	va_list prnt;

	if (format == NULL)
		return (-1);
	va_start(prnt, format);
	for (i =0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buff[bi++] = format [i];
			if (bi == BUFF_SIZE)
			{
				print_buff(buff, &bi);
			}
			counter++;
		}
		else
		{
			print_buff(buff, &bi);
			flags = get_flags(format, &i);
			width = get_width(format, &i, prnt);
			prec = get_prec(format, &i, prnt);
			size = get_size(format, &i);
			++i;
			c2 = handle_prnt(format, &i, prnt, buff,
					flags, width, prec, size);
			if (c2 == -1)
				return (-1);
			counter += c2;
		}
	}
	print_buff(buff, &bi);
	va_end(prnt);
	return (counter);
}
/**
 * print_buff - name
 * @buff: array from main
 * @bi: @ of int from main
 *
 * putchar with extras
 * Return: void
 */
void print_buff(char buff[], int *bi)
{
	if (*bi > 0)
		write(1, &buff[0], *bi);
	*bi = 0;
}
