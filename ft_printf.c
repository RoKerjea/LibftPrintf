/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:53:44 by rokerjea          #+#    #+#             */
/*   Updated: 2022/02/19 11:54:33 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_base(int nb, char c)
{
	char	zero;

	zero = '0';
	if (nb == 0)
		return (write(1, &zero, 1));
	if (c == 'x')
		return (ft_printnbr_hexa(nb, "0123456789abcdef"));
	else
		return (ft_printnbr_hexa(nb, "0123456789ABCDEF"));
}

int	ft_parse(va_list ap, const char *text, int i)
{
	if (text[i] == 'c')
		return (ft_printchar(va_arg(ap, int)));
	if (text[i] == 's')
		return (ft_printstr(va_arg(ap, char *)));
	if (text[i] == 'p')
		return (ft_printpoint(va_arg(ap, unsigned long long)));
	if (text[i] == 'd' || text[i] == 'i')
		return (ft_printnbr(va_arg(ap, int)));
	if (text[i] == 'u')
		return (ft_printnbr_unsi(va_arg(ap, unsigned int)));
	if (text[i] == 'x' || text[i] == 'X')
		return (ft_print_base(va_arg(ap, unsigned int), text[i]));
	if (text[i] == '%')
		return (ft_printpercent());
	return (0);
}

int	ft_printf(const char *text, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, text);
	while (text[i])
	{
		while (text[i] && text[i] != '%')
			count += write(1, &text[i++], 1);
		if (text[i] == '%' && ft_char_in_base(text[i + 1], "cspdiuxX%") == -1)
			i++;
		if (text[i] == '%' && ft_char_in_base(text[i + 1], "cspdiuxX%") >= 0)
		{
			count += ft_parse(ap, text, i + 1);
			i += 2;
		}
	}
	va_end(ap);
	return (count);
}
