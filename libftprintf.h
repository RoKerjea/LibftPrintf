#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_putstr(char *str);
int	ft_parse(va_list ap, const char *text, int i);
int	ft_printf(const char *text, ...);
#endif