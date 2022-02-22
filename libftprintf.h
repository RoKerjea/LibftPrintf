#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_strlen(char *str);
int	ft_putchar(char c);

int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putnbr_unsi(unsigned int nb);
int	ft_putnbr_base_uhexa(unsigned int nbr);
int	ft_putnbr_base_lhexa(unsigned int nbr);
int	ft_putpercent();
int	ft_char_in_base(char c, char *base);
int	ft_putpoint(unsigned int nbr);
int	ft_parse(va_list ap, const char *text, int i);
int	ft_printf(const char *text, ...);
#endif