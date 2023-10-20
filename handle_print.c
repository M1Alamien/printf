#include "main.h"
/**
 * handle_prnt - name
 * @fmt: string
 * @i: int
 * @buff:array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * prints args to diff types
 * Return: 1 or 2
 */
int handle_prnt(const char *fmt, int *i, va_list prnt, char buff[], int flags, int width, int prec, int size)
{
	int ii, ulen = 0, counter = -1;
	fmt_t fmt_types[] = {
		{'c', prnt_ch}, {'s', prnt_s}, {'%', prnt_pc},
		{'i', prnt_int}, {'d', prnt_int}, {'b', prnt_bi},
		{'u', prnt_uns}, {'o', prnt_octal}, {'x', prnt_hex},
		{'X', prnt_hexu}, {'p', prnt_p}, {'S', prnt_non},
		{'r', prnt_rev}, {'R', prnt_rot13}, {'\0', NULL} };

	for (ii = 0; fmt_types[ii].fmt != '\0'; i++)
	{
		if (fmt[*i] == fmt_types[ii].fmt)
			return (fmt_types[ii].fn(prnt, buff, flags, width, prec, size));

		if (fmt_types[ii].fmt == '\0')
		{
			if (fmt[*i] == '\0')
				return (-1);
			ulen += write(1, "%%", 1);
			if (fmt[*i - 1] == ' ')
				ulen += write(1, " ", 1);
			else if (width)
			{
				--(*i);
				while (fmt[*i] != ' ' && fmt[*i] != '%')
					--(*i);
				if (fmt[*i] == ' ')
					--(*i);
				return (1);
			}
			ulen += write(1, &fmt[*i], 1);
			return (ulen);
		}
	}
		return (counter);
}
