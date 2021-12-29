/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:45:58 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/14 12:46:32 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		lenumber(int nbr);
int		hexa_lenumber(unsigned int nbr);
int		unsigned_lenumber(unsigned int nbr);
int		ft_putnbr(int nb);
int		putnbr_unsigned(unsigned int nb);
int		hexa_putnbr(unsigned int nb, char c);
void	hexa_putnbr_unsigned(unsigned long long nb);
int		ptr_lenumber(unsigned long long nbr);
int		print_p(unsigned long long nb);
int		find_format(char c, va_list *arg_ptr);
int		ft_printf(const char *str, ...);

#endif
