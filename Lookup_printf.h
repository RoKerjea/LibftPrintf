#ifndef LOOKUP_PRINTF_H
# define LOOKUP_PRINTF_H

typedef struct		s_lookup	t_list;

struct s_lookup
{
	char c;
	int		(*fct)()
}

int	ft_putstr(va_arg(va_list ap, char *)));

{'c', ft_putchar},
{'s', ft_putstr},
{'p', ft_putstr},
{'d', ft_putnumber},
{'i', ft_putnumber},
{'u', ft_putnumber_unsi},
{'x', ft_putbaselow},
{'X', ft_putbaseup},
{'%', ft_putpercent},
{0}
};

#endif