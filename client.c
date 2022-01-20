/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:30:05 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/07 21:35:01 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static void	bad_pid(void)
{
	ft_printf("Server didnt received your message, may be bad PID\n");
	exit(1);
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
static void	send_one_octet(int pid, char c)
{
	int	i;
	int	is_true;

	i = 7;
	while (i != -1)
	{
		is_true = c & (1 << i);
		if (is_true)
		{
			if (kill(pid, SIGUSR1) == -1)
				bad_pid();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				bad_pid();
		}
		i--;
		usleep(300);
	}
}

static void	send_str(int pid, char *str)
{
	int				i;
	unsigned int	pid_c;
	char			*pid_s;

	i = -1;
	pid_c = getpid();
	pid_s = ft_itoa(pid_c);
	while (pid_s[++i])
		send_one_octet(pid, pid_s[i]);
	send_one_octet(pid, 'Z');
	i = -1;
	while (str[++i])
		send_one_octet(pid, str[i]);
	send_one_octet(pid, '\0');
	free(pid_s);
}

static void	handler(int signo)
{
	if (signo == SIGUSR1)
		ft_printf("Server receveid message and displayed it");
}

int	main(int ac, char **av)
{
	if (ac != 3 || ft_atoi(av[1]) < 1)
	{
		if (ac != 3)
			ft_printf("Invalid number of args");
		else
			ft_printf("Invalid PID, must be > 0");
		return (1);
	}
	signal(SIGUSR1, &handler);
	send_str(ft_atoi(av[1]), av[2]);
	return (0);
}
