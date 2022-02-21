#include <stdarg.h>


int	parse(va_list *ap, char *tmp, int i)
{
	if (tmp[i] == 'c')
		return (write(1, va_arg(ap, int), 1));
	if (tmp[i] == 's')
		return (ft_putstr(va_arg(ap, char*)));
	if (tmp[i] == 'p')
	if (tmp[i] == 'd')
	if (tmp[i] == 'i')
	if (tmp[i] == 'u')
	if (tmp[i] == 'x')
	if (tmp[i] == 'X')
	{
		return (ft_putstr(ft_convert_base(va_arg(ap, int), "0123456789ABCDEF")));
	}
	if (tmp[i] == '%')
		return (write(1, "%", 1));
}
int		ft_printf(char *tmp, ...)
{
	va_list ap;
	int i;
	int count;

	i =0 ;
	count =0;
	va_start(ap, tmp);
	
	while (tmp[i])
	{
		while (tmp[i] !=  '%' && tmp[i])
		{
			write(1, &tmp[i], 1);
			count++;
			i++;
		}
		if (tmp[i] == '%')
		{
			i++;
			count += parse(&ap, tmp, i);
			i++;
		}
	}
	va_end(ap);
	return (count);
}