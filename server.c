/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:23:57 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/31 19:45:03 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void	ftputchar(char c)
{
	write(1, &c, 1);
}

void	ftputnbr( long int nb, long int taille, char *base)
{
	if (nb < 0)
	{
		ftputchar('-');
		nb = -nb;
	}
	if (nb > taille - 1)
	{
		ftputnbr(nb / taille, taille, base);
		ftputnbr(nb %= taille, taille, base);
	}
	else
	{
		ftputchar(base[nb]);
	}
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

void	ftputnbr_base(int	nbr, char	*base)
{
	int	taille_base;
	int	i;
	int	j;

	i = 0;
	taille_base = ftstrlen(base);
	while (base[i])
	{
		if ((base[i] == '-' || base[i] == '+')
			|| ((base[i] >= 9 && base[i] <= 13) || (base[i] == 32)))
			return ;
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return ;
			j++;
		}
		i++;
	}
	if (base[0] == '\0' || ftstrlen(base) == 1)
		return ;
	ftputnbr(nbr, taille_base, base);
}

int	binary_atoi(const char *nptr)
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


/*
L'appel système kill() peut être utilisé pour envoyer n'importe quel 
signal à n'importe quel processus ou groupe de processus. 

SIGUSR1 User defined signal 1 : Définie par le programmeur. L'action par défaut est la
mise à mort du processus.
*/
void    serveur()
{
    int pid_c = getpid();
    ft_printf("%d\n", pid_c);
}


//global
int bits = 2;

//indique ce que fait SIGUSR1 ou SIGUSR2 (gestionnaire)
// parametre = signal qui l'a activee (1 ou 2 dans notre cas)
static void handler(int signo)
{
	static char one_char[8];
	static char str[1000000];
	static int i = 0;
	static int f = 0;
	int y;
	int kk;
	
	//str = malloc(sizeof(char) * 10);
    if (signo == SIGUSR1)
		one_char[i] = '1';

    else if (signo == SIGUSR2)
		one_char[i] = '0';
	if (i == 7)
	{

		str[f] = binary_atoi(one_char);
		if (str[f] == 0)
		{
			ft_putstr_fd(str, 1);
			exit(0);
		}
		f++;
		i = -1;
	}
	//printf("signal recu");
	i++;
	
}


char *print_char()
{
    char *one_char;
    int i = 7;
    int j = 0;
	int numb = 9;
	
    one_char = malloc(sizeof(char) * numb);
    while (i >= 0)
    {
        one_char[j] = bits + '0';
        i--;
        j++;
        pause();
    }
    one_char[j] = '\0';
    return (one_char);
}


int main() 
{      
	/*Un signal est une notification asynchrone envoyée à un processus pour lui signaler l'apparition d'un événement.
    Signal() renvoie un pointeur vers handler()*/
    signal(SIGUSR1, &handler);
    signal(SIGUSR2, &handler);
    int pid_c = getpid();
    ft_printf("listening... %d\n", pid_c);
	while (1)
		pause();

    ft_printf("terminating... %d\n", pid_c);
 }