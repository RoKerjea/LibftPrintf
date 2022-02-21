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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	ft_parse(va_list ap, const char *text, int i)
{
	if (text[i] == 's')
		return (ft_putstr(va_arg(ap, char *)));
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
