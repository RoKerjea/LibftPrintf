/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:28:12 by rokerjea          #+#    #+#             */
/*   Updated: 2022/02/23 12:28:16 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned int nbr, char *base)
{
	int		count;
	long	nb;
	char	c;

	count = 0;
	nb = nbr;
	if (nb >= 10)
	{
		count += ft_putnbr_hexa(nb / 16, base);
	}
	c = base[nb % 16];
	if (!(count == 0 && c == '0'))
		count += write(1, &c, 1);
	return (count);
}

int	ft_putpercent(void)
{
	char	c;

	c = '%';
	return (write(1, &c, 1));
}

int	ft_putnbr_hexapoint(unsigned long long nbr, char *base)
{
	int		count;
//	long	nb;
	char	c;

	count = 0;
	//nb = nbr;
	if (nbr >= 10)
	{
		count += ft_putnbr_hexapoint(nbr / 16, base);
	}
	c = base[nbr % 16];
	if (!(count == 0 && c == '0'))
		count += write(1, &c, 1);
	return (count);
}

int	ft_putpoint(unsigned long long nbr)
{
	char zero;
	int	count;

	count = 0;
	zero = '0';
	count += ft_putstr("0x");
	if (nbr == 0)
	{
		count += write(1, &zero, 1);
		return (count);
	}
	count += ft_putnbr_hexapoint(nbr, "0123456789abcdef");
	return (count);
}

int	ft_char_in_base(char c, char *base)
{
	int	i;

	i = 0;
	if (c == base[i])
		return (i);
	while (c != base[i] && base[i])
	{
		i++;
		if (c == base[i])
			return (i);
	}
	return (-1);
}
