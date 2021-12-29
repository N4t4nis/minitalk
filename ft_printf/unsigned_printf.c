/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:44:58 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/14 12:45:46 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lenumber(int nbr)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	len;

	len = lenumber(nb);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		len++;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (len);
}

int	unsigned_lenumber(unsigned int nbr)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	putnbr_unsigned(unsigned int nb)
{
	int	len;

	len = unsigned_lenumber(nb);
	if (nb > 9)
	{
		putnbr_unsigned(nb / 10);
		putnbr_unsigned(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (len);
}
