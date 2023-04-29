#include "main.h"

/**
 *print_from_to - print range of addresses
 *@start: start address
 *@stop: stop address
 *@except: except address
 *
 *Return: bytes printed
 */
int print_from_to(char *start, char *stop, params_t *params)
{
	int sum = 0;
	(void)params;

	while (start <= stop)
	{
		sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
*print_rev - prints in reverse
*@ap: string
*@params: struct parameter
*
*Return: bytes printed
*/
int print_rev(va_list ap, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
*print_rot13 - prints in rot13
*@ap: string
*@params: struct parameter
*
*Return: bytes printed
*/
int print_rot13(va_list ap, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ      abcdefghijklmnopqrstuvwxyz";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if
			((a[i] >= 'A'  && a[i] <= 'Z')
				|| (a[i] >= 'a' && a[i] <= 'z'))
		{
				index = a[i] - 65;
				count += _putchar(arr[index]);
			}
			else
				count += _putchar(a[i]);
			i++;
	}
	return (count);
}
