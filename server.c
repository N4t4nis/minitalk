/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v3r <v3r@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:23:57 by nbenhado          #+#    #+#             */
/*   Updated: 2022/01/07 22:42:07 by v3r              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static unsigned char	binary_atoi(const char *nptr)
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (nptr[i] != '0' && nptr[i] != '1')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '1')
	{
		result = result * 2 + nptr[i] - '0';
		i++;
	}
	return (result);
}

static void	ftputstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

//indique ce que fait SIGUSR1 ou SIGUSR2 (gestionnaire)
// parametre = signal qui l'a activee (1 ou 2 dans notre cas)
static void	handler(int signo)
{
	static char	one_char[8] = {0};
	static char	str[10000000] = {0};
	static int	i = 0;
	static int	f = 0;

	if (signo == SIGUSR1)
		one_char[i] = '1';
	else if (signo == SIGUSR2)
		one_char[i] = '0';
	else
		ft_printf("Unknown signal");
	if (i == 7)
	{
		str[f] = binary_atoi(one_char);
		if (str[f] == 0)
		{
			ftputstr(str);
			write(1, "\n", 1);
			f = -1;
		}
		f++;
		i = -1;
	}
	i++;
}

/*Un signal est une notification asynchrone envoyée à un processus 
pour lui signaler l'apparition d'un événement.
Signal() renvoie un pointeur vers handler()*/
int	main(void)
{
	unsigned int	pid_c;

	pid_c = getpid();
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	ft_printf("listening... PID = [%d]\n", pid_c);
	while (1)
		pause();
	return (0);
}
