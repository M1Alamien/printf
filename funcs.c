#include "main.h"
/**
 * prnt_ch - name
 * @types: list
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * prints ch
 * Return: num of ch printed
 */
int prnt_ch(va_list types, char buff[], int flags, int width, int prec, int size)
{
	char ch = va_arg(types, int);

	return (hwc(ch, buff, flags, width, prec, size));
}
/**
 * prnt_s - name
 * @types: list
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * prints s
 * Return: num of ch in s printed
 */
int prnt_s(va_list types, char buff[], int flags, int width, int prec, int size)
{
	int i, len = 0;
	char *s = va_arg(types, char *);

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	if (s == NULL)
	{
		s = "(null)";
		if (prec >= 6)
			s = "      ";
	}
	while (s[len] != '\0')
		len++;
	if (prec >= 0 && prec < len)
		len = prec;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &s[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &s[0], len);
			return (width);
		}
	}
	return (write(1, s, len));
}
/**
 * prnt_pc - name
 * @types: list
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * prints %
 * Return: num of % printed
 */
int prnt_pc(va_list types, char buff[], int flags, int width, int prec, int size)
{
	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);
	UNUSED(types);
	return (write(1, "%%", 1));
}
/**
 * prnt_int - name
 * @types: list
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * prints int
 * Return: num of char printed
 */
int prnt_int(va_list types, char buff[], int flags, int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	int isminus = 0;
	long int li = va_arg(types, long int);
	unsigned long int n;

	li = convert_size_number(n, size);
	if (li == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	n = (unsigned long int)li;
	if (li < 0)
	{
		n = (unsigned long int)((-1) * li);
		isminus = 1;
	}
	while (n > 0)
	{
		buff[i--] = (n % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_num(isminus, i, buff, flags, width, prec, size));
}
/**
 * prnt_bi - name
 * @types: list
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * prints unsigned int
 * Return: num of char printed
 */
int prnt_bi(va_list types, char buff[], int flags, int width, int prec, int size)
{
	unsigned int i, ii, n, sum;
	unsigned int b[32];
	int count;

	UNUSED(buff);
	UNUSED(size);
	UNUSED(prec);
	UNUSED(width);
	UNUSED(flags);

	i = va_arg(types, unsigned int);
	ii = 2147483648;
	b[0] = i / ii;
	for (n = 1; n < 32; n++)
	{
		ii /= 2;
		b[n] = (i / ii) % 2;
	}
	for (n = 0, sum = 0, count = 0; n < 32; i++)
	{
		sum += b[n];
		if (n == 31 || sum)
		{
			char c = '0' + b[n];
			write(1, &c, 1);
			count++;
		}
	}
	return (count);
}
