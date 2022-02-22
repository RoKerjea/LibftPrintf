
#include "libftprintf.h"

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
	return (write(1, str, ft_strlen(str)));
}

void	ft_putnbr(int nb)
{
	long n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar('0' + n % 10);
}

void	ft_putnbr_unsi(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbr_unsi(nb / 10);
	ft_putchar('0' + nb % 10);
}

int ft_count_number_unsi(unsigned int nb)
{
	int count;
	
	count = 0;
	ft_putnbr_unsi(nb);
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int ft_count_number(int nb)
{
	long n;
	int count;
	
	n = nb;
	count = 0;
	if (n < 0)
	{
		count = 1;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	ft_putnbr(nb);
	return (count);
}

int	ft_putnbr_base_lhexa(unsigned int nbr)
{
	int		count;
	char *base;
	long	nb;
	char	c;

	count = 0;
	base = "0123456789abcdef";
	nb = nbr;
	if (nb >= 10)
	{
		count += ft_putnbr_base_lhexa(nb / 16);
	}
	c = base[nb % 16];
	if (!(count == 0 && c == '0'))
		count += write(1, &c, 1);
	return (count);
}

int	ft_putnbr_base_uhexa(unsigned int nbr)
{
	int		count;
	char *base;
	long	nb;
	char	c;

	count = 0;
	base = "0123456789ABCDEF";
	nb = nbr;
	if (nb >= 10)
	{
		count += ft_putnbr_base_uhexa(nb / 16);
	}
	c = base[nb % 16];
	if (!(count == 0 && c == '0'))
		count += write(1, &c, 1);
	return (count);
}

int	ft_putpercent()
{
	char c;

	c = '%';
	return (write(1, &c, 1));
}

int	ft_putpoint(unsigned int nbr)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr_base_lhexa(nbr);
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