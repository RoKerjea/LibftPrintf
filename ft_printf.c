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

#include "libftprintf.h"

int	ft_parse(va_list ap, const char *text, int i)
{
	if (text[i] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (text[i] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (text[i] == 'p')
		return (ft_putpoint(va_arg(ap, unsigned int)));
	if (text[i] == 'd' || text[i] == 'i')
		return (ft_count_number(va_arg(ap, int)));
	if (text[i] == 'u')
		return (ft_count_number_unsi(va_arg(ap, unsigned int)));
	if (text[i] == 'x')
		return (ft_putnbr_base_lhexa(va_arg(ap, unsigned int)));
	if (text[i] == 'X')
		return (ft_putnbr_base_uhexa(va_arg(ap, unsigned int)));
	if (text[i] == '%')
		return (ft_putpercent());
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
		{
			write(1, &text[i++], 1);
			count++;
		}
		if (text[i] == '%')
		{
			i++;
			count += ft_parse(ap, text, i);
			i++;
		}
	}
	va_end(ap);
	printf ("Number of char printed : %i\n", count);
	return (count);
}
