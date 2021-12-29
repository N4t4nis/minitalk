/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:36:47 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/14 13:00:33 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
	return (i);
}

int	find_format(char c, va_list *arg_ptr)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*arg_ptr, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*arg_ptr, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(*arg_ptr, int)));
	else if (c == 'u')
		return (putnbr_unsigned(va_arg(*arg_ptr, int)));
	else if (c == 'p')
		return (print_p(va_arg(*arg_ptr, unsigned long long)));
	else if (c == 'x')
		return (hexa_putnbr(va_arg(*arg_ptr, int), c));
	else if (c == 'X')
		return (hexa_putnbr(va_arg(*arg_ptr, int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	arg_ptr;

	ret = 0;
	i = 0;
	va_start(arg_ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += find_format(str[i + 1], &arg_ptr);
			i++;
		}
		else
			ret += ft_putchar(str[i]);
		i++;
	}
	va_end(arg_ptr);
	return (ret);
}
