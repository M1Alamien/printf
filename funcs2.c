#include "main.h"
/**
 * prnt_ uns - name
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
int prnt_uns(va_list types, char buff[], int flags, int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int uli = va_arg(types, unsigned long int);

	uli = convert_size_uns(uli, size);
	if (uli == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (uli > 0)
	{
		buff[i--] = (uli % 10) + '0';
		uli /= 10;
	}
	i++;
	return (write_uns(0, i, buff, flags, width, prec, size));
}
/**
 * prnt_octal - name
 * @types: list
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * prints unsigned int in octal
 * Return: num of char printed
 */
int prnt_octal(va_list types, char buff[], int flags, int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int uli = va_arg(types, unsigned long int);
	unsigned long int ouli = uli;

	UNUSED(width);
	uli = convert_size_uns(uli, size);
	if (uli == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (uli > 0)
	{
		buff[i--] = (uli % 10) + '0';
		uli /= 8;
	}
	if (flags & F_HASH && ouli != 0)
		buff[i--] = '0';
	i++;
	return (write_uns(0, i, buff, flags, width, prec, size));
}
/**
 * prnt_hex - name
 * @types: list
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * prints unsigned int in hex
 * Return: num of char printed
 */
int prnt_hex(va_list types, char buff[], int flags, int width, int prec, int size)
{
	return (prnt_hexa(types, "0123456789abcdef", buff,
		flags, 'x', width, prec, size));
}
/**
 * prnt_hexu - name
 * @types: list
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * prints unsigned int in hex
 * Return: num of char printed
 */
int prnt_hexu(va_list types, char buff[], int flags, int width, int prec, int size)
{
	return (prnt_hexa(types, "0123456789ABCDEF", buff,
		flags, 'X', width, prec, size));
}
/**
 * prnt_hexa - name
 * @types: list
 * @buff: array from printf
 * @flags: active flags
 * @width: width
 * @prec: precision
 * @size: size
 *
 * prints unsigned int in hex
 * Return: num of char printed
 */
int prnt_hexa(va_list types,char map_to[], char buff[], int flags, char flag_ch, int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int uli = va_arg(types, unsigned long int);
	unsigned long int ouli = uli;

	UNUSED(width);
	uli = convert_size_uns(uli, size);
	if (uli == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (uli > 0)
	{
		buff[i--] = map_to[uli % 16];
		uli /= 16;
	}

	if (flags & F_HASH && ouli != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}
	i++;
	return (write_uns(0, i, buff, flags, width, prec, size));
}
