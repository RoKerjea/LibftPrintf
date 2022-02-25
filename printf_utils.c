/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:18:42 by rokerjea          #+#    #+#             */
/*   Updated: 2022/02/22 19:18:47 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_printchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_printstr(char *str)
{
	char	*null;

	null = "(null)";
	if (!str)
		return (write(1, null, 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_printnbr(int nb)
{
	int		count;
	long	n;

	n = nb;
	count = 0;
	if (n < 0)
	{
		ft_printchar('-');
		n *= -1;
		count++;
	}
	if (n >= 10)
		count += ft_printnbr(n / 10);
	count += ft_printchar('0' + n % 10);
	return (count);
}

int	ft_printnbr_unsi(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_printnbr_unsi(nb / 10);
	count += ft_printchar('0' + nb % 10);
	return (count);
}