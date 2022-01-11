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

int	ftatoi(const char *nptr, int index)
{
	int		i;
	int		negatif;
	int		result;

	i = 0;
	result = 0;
	negatif = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) | (nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negatif = -1;
		i++;
	}
	i -= 1;
	while (++i < index && nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + nptr[i] - '0';
	result *= negatif;
	return (result);
}

static void	print_str(char *str, int index, int *f)
{
	int	i;
	int	start;

	start = index + 1;
	i = 0;
	while (str[i])
		i++;
	while (start <= i)
	{
		write(1, &str[start], 1);
		start++;
	}
	write(1, "\n", 1);
	kill(ftatoi(str, index), SIGUSR1);
	*f = -1;
}

static void	handler(int signo)
{
	static char	one_char[8] = {0};
	static char	*str = NULL;
	static char	buff[12] = {0};
	static int	len = 0;
	static int	i = 0;
	static int	f = 0;
	static int	interupt = -1;

	if (signo == SIGUSR1)
		one_char[i] = '1';
	else if (signo == SIGUSR2)
		one_char[i] = '0';
	else
		ft_printf("Unknown signal");
	if (i == 7 && interupt == -1)
	{
		buff[len] = binary_atoi(one_char);
		if (buff[len] == 0)
		{
			str = malloc(sizeof(char) * ft_atoi(buff));
			interupt = 0;
		}
		len++;
		i = -1;
	}
	if (i == 7 && interupt >= 0)
	{
		str[f] = binary_atoi(one_char);
		if (str[f] == 0 && interupt > 0)
		{
			print_str(str, interupt, &f);
		}
		if (str[f] == 'Z' && interupt == 0)
			interupt = f;
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
	ft_printf("listening... PID: [%d]\n", pid_c);
	while (1)
		pause();
	return (0);
}
