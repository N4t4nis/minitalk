/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:43:41 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/14 13:00:16 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	hexa_lenumber(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

int	hexa_putnbr(unsigned int nb, char c)
{
	char	*base;
	int		len;

	len = hexa_lenumber(nb);
	base = "0123456789abcdef";
	if (nb > 15)
	{
		hexa_putnbr(nb / 16, c);
		hexa_putnbr(nb % 16, c);
	}
	else if (c == 'X' && base[nb] >= 'a' && base[nb] <= 'f')
		ft_putchar(base[nb] - 32);
	else
		ft_putchar(base[nb]);
	return (len);
}

int	ptr_lenumber(unsigned long long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

void	hexa_putnbr_unsigned(unsigned long long nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb > 15)
	{
		hexa_putnbr_unsigned(nb / 16);
		hexa_putnbr_unsigned(nb % 16);
	}
	else
		ft_putchar(base[nb]);
}

int	print_p(unsigned long long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len += write(1, "0x0", 3);
	else
	{
		len += write(1, "0x", 2);
		hexa_putnbr_unsigned(nb);
		len += ptr_lenumber(nb);
	}
	return (len);
}
