/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:14:23 by rokerjea          #+#    #+#             */
/*   Updated: 2022/02/23 15:14:26 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_strlen(char *str);
int	ft_printchar(char c);

int	ft_printstr(char *str);
int	ft_printnbr(int nb);
int	ft_printnbr_unsi(unsigned int nb);
int	ft_printnbr_hexa(unsigned int nbr, char *base);
int	ft_printpercent(void);
int	ft_char_in_base(char c, char *base);
int	ft_printpoint(unsigned long long nbr);
int	ft_printnbr_hexapoint(unsigned long long nbr, char *base);
int	ft_parse(va_list ap, const char *text, int i);
int	ft_printf(const char *text, ...);
#endif
