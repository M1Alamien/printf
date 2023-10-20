#include "main.h"
/**
 * hwc - name
 * @c: char
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * prints a stirng
 * Return: num of char printeed
 */
int hwc(char c, char buff[], int flags, int width,
		int prec, int size)
{
	int i = 0;
	char pp = ' ';

	UNUSED(prec);
	UNUSED(size);

	if (flags & F_ZERO)
		pp = '0';

	buff[i++] = c;
	buff[i++] = '\0';
	if (width > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buff[BUFF_SIZE - i - 2] = pp;

		if (flags & F_MINUS)
			return (write(1, &buff[0], 1) + write(1,
						&buff[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buff[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buff[0], 1));
	}
	return (write(1, &buff[0], 1));
}
/**
 * write_number - name
 * @isminus: int
 * @i: int
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * prints string
 * Return: num of char printed
 */
int write_number(int isminus, int i, char buff[], int flags,
	       int width, int prec, int size)
{
	int len = BUFF_SIZE - i - 1;
	char pp = ' ', c2 = 0;

	UNUSED(size);
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pp = '0';
	else if (isminus)
		c2 = '-';
	else if (flags & F_PLUS)
		c2 = '+';
	else if (flags & F_SPACE)
		c2 = ' ';
	return (write_num(i, buff, flags, width, prec, len, pp, c2));
}
/**
 * write_num - name
 * @i: int
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @len: int
 * @pp: pading char
 * @c2: char +
 *
 * write a num
 * Return: num of char printed
 */
int write_num(int i, char buff[], int flags, int width,
		int prec, int len, char pp, char c2)
{ int ii, ppst = 1;

	if (prec == 0 && i == BUFF_SIZE - 2 && buff[i] == '0' && width == 0)
		return (0);
	if (prec == 0 && i == BUFF_SIZE - 2 && buff[i] == '0')
		buff[i] = pp = ' ';
	if (prec > 0 && prec < len)
		pp = ' ';
	while (prec > len)
		buff[--i] = '0', len++;
	if (c2 != 0)
		len++;
	if (width > len)
	{
		for (ii = 1; ii < width - len + 1; ii++)
			buff[ii] = pp;
		buff[ii] = '\0';
		if (flags & F_MINUS && pp == ' ')
		{
			if (c2)
				buff[--i] = c2;
			return (write(1, &buff[i], len) + write(1,
						&buff[1], ii - 1));
		}
		else if (!(flags & F_MINUS) && pp == ' ')
		{
			if (c2)
				buff[--i] = c2;
			return (write(1, &buff[1], ii - 1) + write(1,
						&buff[i], len));
		}
		else if (!(flags & F_MINUS) && pp == '0')
		{
			if (c2)
				buff[--ppst] = c2;
			return (write(1, &buff[ppst], ii - ppst) +
					write(1, &buff[i], len - (1 - ppst)));
		}
	}
	if (c2)
		buff[--i] = c2;
	return (write(1, &buff[i], len));
}
/**
 * write_uns - name
 * @isminus: int
 * @i: int
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * write unsigned num
 * Return: num of char printed
 */
int write_uns(int isminus, int i, char buff[], int flags,
		int width, int prec, int size)
{
	int len = BUFF_SIZE - i - 1, ii = 0;
	char pp = ' ';

	UNUSED(isminus);
	UNUSED(size);

	if (prec == 0 && i == BUFF_SIZE - 2 && buff[i] == '0')
		return (0);
	if (prec > 0 && prec < len)
		pp = ' ';
	while (prec > len)
	{
		buff[--i] = '0';
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pp = '0';
	if (width > len)
	{
		for (ii = 0; ii < width - len; ii++)
			buff[ii] = pp;
		buff[ii] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &buff[i], len) + write(1,
						&buff[0], ii));
		}
		else
			return (write(1, &buff[0], ii) + write(1, &buff[i], len));
	}
	return (write(1, &buff[i], len));
}
/**
 * write_p - name
 * @i: int
 * @len: int
 * @pp: char
 * @c2: char
 * @ppst: int
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 *
 * writes pointer
 * Return: num of char printed
 */
int write_p(char buff[], int i, int len, int width, int flags,
		char pp, char c2, int ppst)
{
	int ii;

	if (width > len)
	{
		for (ii = 3; ii < width - len + 3; ii++)
			buff[ii] = pp;
		buff[ii] = '\0';
		if (flags & F_MINUS && pp == ' ')
		{
			buff[--i] = 'x';
			buff[--i] = '0';
			if (c2)
				buff[--i] = c2;
			return (write(1, &buff[i], len) + write(1,
						&buff[3], ii - 3));
		}
		else if (!(flags & F_MINUS) && pp == ' ')
		{
			buff[--i] = 'x';
			buff[--i] = '0';
			if (c2)
				buff[--i] = c2;
			return (write(1, &buff[3], ii - 3) + write(1,
						&buff[i], len));
		}
			else if (!(flags & F_MINUS) && pp == '0')
			{
				if (c2)
					buff[--ppst] = c2;
				buff[1] = '0';
				buff[2] = 'x';
				return (write(1, &buff[ppst], ii - ppst) + write(1,
							&buff[i], len - (1 - ppst) - 2));
			}
	}
		buff[--i] = 'x';
		buff[--i] = '0';
		if (c2)
			buff[--i] = c2;
		return (write(1, &buff[i], BUFF_SIZE - i - 1));
}
