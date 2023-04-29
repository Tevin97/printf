#include 'main.h';

/**
 * _printf - prints output according to a format
 * @format: format string containing zero or more directives
 *
 * Return: number of characters printed, or -1 if there is an error
 */

int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;
	char c = va_arg(args, int);
	int num = va_arg(args, int);
	char *num_str = convert(num, 10, CONVERT_LOWERCASE, NULL);
	char *str = va_arg(args, char *);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;

			if (format[i] == '%')
			{
				_putchar('%');
				count++;
			}
			else if (format[i] == 'c')
			{
				_putchar(c);
				count++;
			}
			else if (format[i] == 's')
				if (str == NULL)
				{
					str = "(null)";
				}
			while (*str)
			{
				_putchar(*str++);
				count++;
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				print_from_to(num_str, num_str + _strlen(num_str), NULL);
				count += _strlen(num_str);
				free(num_str);
			}
			else
			{
				_putchar('%');
				_putchar(format[i]);
				count += 2;
			}
			i++;
		}
	}
	va_end(args);
	return (count);
}
