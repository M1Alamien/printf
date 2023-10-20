#include "main.h"
/**
 * get_flags - name
 * @format: string from main
 * @i: parameter
 *
 * calculates active flags
 * Return: flags
 */
int get_flags(const char *format, int *i)
{
	int ii, ci;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (ci = *i + 1; format[ci] != '\0'; ci++)
	{
		for (ii = 0; FLAGS_CH[ii] != '\0'; ii++)
		{
			if (format[ci] == FLAGS_CH[ii])
			{
				flags |= FLAGS_ARR[ii];
				break;
			}
		}
			if (FLAGS_CH[ii] == 0)
				break;
		}
		*i = ci - 1;
		return (flags);
}
