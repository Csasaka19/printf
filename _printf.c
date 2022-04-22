#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format of string
 * Description: this function will produce output according to a format
 * Return: length of string
 */
int _printf(const char *format, ...)
{
int (*pfunc)(va_list, flags_t *);
const char *p;
va_list arguments;
flags_t flags = {0, 0, 0};

register int counter = 0;

va_start(arguments, format);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (p = format; *p; p++)
{
if (*p == '%')
{
p++;
if (*p == '%')
{
counter += _putchar('%');
continue;
}
while (get_flag(*p, &flags))
p++;
pfunc = get_print(*p);
counter += (pfunc)
? pfunc(arguments, &flags)
: _printf("%%%c", *p);
}
else
counter += _putchar(*p);
}
_putchar(-1);
va_end(arguments);
return (counter);
}
