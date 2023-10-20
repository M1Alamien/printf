#include "main.h"
/**
 * prnt_p - name
 * @types: list
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * prints value of p
 * Return: num of char printed
 */
int prnt_p(va_list types, char buff[],
		int flags, int width, int prec, int size)
{
	char c2 = 0, sp = ' ';
	char map_to[] = "0123456789abcdef";
	int i = BUFF_SIZE - 2, len = 2, sp_st = 1;
	unsigned long adds;
	void *add = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (add == NULL)
		return (write(1, "(nil)", 5));
	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(prec);
	adds = (unsigned long)add;
	while (adds > 0)
	{
		buff[i--] = map_to[adds % 16];
		adds /= 16;
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		sp = '0';
	if (flags & F_PLUS)
		c2 = '+', len++;
	else if (flags & F_SPACE)
		c2 = ' ', len++;
	i++;

	return (write_p(buff, i, len, width, flags, sp, c2, sp_st));
}
/**
 * prnt_non - name
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 * @types: list
 *
 *
 * prints assci code of non printable chars
 * Return: num of char printed
 */
int prnt_non(va_list types, char buff[],
		int flags, int width, int prec, int size)
{
	int i = 0, off = 0;
	char *s = va_arg(types, char *);

	UNUSED(prec);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);

	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		if (is_printable(s[i]))
			buff[i + off] = s[i];
		else
			off += append_hexa_code(s[i], buff, i + off);
		i++;
	}
	buff[i + off] = '\0';
	return (write(1, buff, i + off));
}
/**
 * prnt_rev - name
 * @types: list
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * prints rev string
 * Return: num of char printed
 */
int prnt_rev(va_list types, char buff[],
		int flags, int width, int prec, int size)
{
	char *s;
	int i, count = 0;

	UNUSED(flags);
	UNUSED(size);
	UNUSED(width);
	UNUSED(buff);

	s = va_arg(types, char *);
	if (s == NULL)
	{
		UNUSED(prec);
		s = ")Null(";
	}
	for (i = 0; s[i]; i++)
	{

	}
	for (i = i - 1; i >= 0; i--)
	{
		char c = s[i];

		write(1, &c, 1);
		count++;
	}
	return (count);
}
/**
 * prnt_rot13 - name
 * @types: list
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * prints string in rot13
 * Return:num of char printed
 */
int prnt_rot13(va_list types, char buff[],
		int flags, int width, int prec, int size)
{
	char *s;
	char c;
	unsigned int i, ii;
	int count = 0;
	char ip[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char op[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(types, char *);
	UNUSED(buff);
	UNUSED(width);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(prec);
	if (s == NULL)
		s = "(AHYY)";
	for (i = 0; s[i]; i++)
	{
		for (ii = 0; ip[ii]; ii++)
		{
			if (ip[ii] == s[i])
			{
				c = op[ii];
				write(1, &c, 1);
				count++;
				break;
			}
		}
		if (!ip[ii])
		{
			c = s[i];
			write(1, &c, 1);
			count++;
		}
	}
	return (count);
}
