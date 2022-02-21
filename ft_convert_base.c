#include <libft_printf.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int	i;
	int	max;
	int	tmp;

	max = 0;
	while (str[max])
		max++;
	max -= 1;
	i = 0;
	while (i <= max / 2)
	{
		tmp = str[i];
		str[i] = str[max - i];
		str[max - i] = tmp;
		i++;
	}
	return (str);
}

char	*ft_itoa_malloc_trad(int neg, int digitcount, long nb, char *base)
{
	int		i;
	char	*res;

	i = 0;
	if (neg == 1)
	{
		if (!(res = malloc(sizeof(char) * (digitcount + 2))))
			return (0);
	}
	else if (!(res = malloc(sizeof(char) * (digitcount + 1))))
		return (0);
	if (nb == 0)
		res[i++] = base[0];
	while (nb > 0)
	{
		res[i] = base[nb % ft_strlen(base)];
		nb = nb / ft_strlen(base);
		i++;
	}
	if (neg == 1)
		res[i++] = '-';
	res[i] = '\0';
	return (ft_strrev(res));
}

char	*ft_itoa_base(int nbr, char *base)
{
	char	*res;
	long	nb;
	int		digitcount;
	int		neg;

	neg = 0;
	if (nbr < 0)
	{
		nb = nbr * -1;
		neg = 1;
	}
	else
		nb = nbr;
	digitcount = (nb == 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr /= ft_strlen(base);
		digitcount++;
	}
	res = ft_itoa_malloc_trad(neg, digitcount, nb, base);
	return (res);
}
