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

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *str)
{
	char *null;

	null = "(null)";
	if (!str)
		return (write(1, null, 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putnbr(int nb)
{
	int		count;
	long	n;

	n = nb;
	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		count++;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar('0' + n % 10);
	return (count);
}

int	ft_putnbr_unsi(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr_unsi(nb / 10);
	count += ft_putchar('0' + nb % 10);
	return (count);
}

/*
#include <stdio.h>
int	main()
{
	unsigned int nb = 4294967295;

	printf("le nombre est \"%u\" \n", nb);
	printf(" a \"%i\" chiffres dans le nombre\n", ft_count_number_unsi(nb));
	unsigned int number = 4294967295;
	printf("le nombre est \"%X\" en hexa lowercase\n", number);
	int count = ft_putnbr_base_uhexa(number);
	printf("\nnumber of char printed : %i\n", count);
	printf("blablabla : %i", ft_putpercent());
	return (0);
}*/