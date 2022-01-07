/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:30:05 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/07 21:07:07 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ftputchar(char c)
{
	write(1, &c, 1);
}

int	ftstrlen(char	*str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

//fonction qui envoie 8 signaux (1 signal pour 1 bits) avec la valeur binaire 
// d'un char (table ascii)
// exemple : char c = 'a' (donc 97) 
// 97 = 1100001 en binaire
// 1 << i va placer un 1 a la derniere case et se decale a 
// chaque iteration : 0000000 / 0000001 / 0000010 / 0000100...
// on compare 97 et 1 << i en binaire, 
// si 1 et 1 = True / si 1 et 0 = False / si 0 et 0 = False
// ca envoi donc 8 signaux avec 1 bits dans l'ordre du nombre 97 en binaire
// kill envoie le signal avec SIGUSR1 si True (1) // SIGUSR2 si False (0)
// je sleep apres chaque signal envoye pour bien qu'ils s'envoient 
// les uns a la suite des autres
void	send_one_octet(int pid, char c)
{
	int	i;
	int	is_true;

	i = 7;
	while (i != -1)
	{
		is_true = c & (1 << i);
		if (is_true)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(300);
	}
}

void	send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_one_octet(pid, str[i]);
		i++;
	}
	send_one_octet(pid, '\0');
}

int	main(int ac, char **av)
{
	if (ac != 3)
		ft_printf("Invalid number of args");
	if (ft_atoi(av[1]) < 1 || ac != 3)
	{
		if (ac != 3)
			ft_printf("Invalid number of args");
		else
			ft_printf("Invalid PID, must be > 0");
		return (0);
	}
	send_str(ft_atoi(av[1]), av[2]);
	return (0);
}
