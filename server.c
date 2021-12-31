/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:23:57 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/31 17:33:29 by nbenhado         ###   ########.fr       */
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
	static char tabs[8];
	static int i = 0;
	int y;
	
    if (signo == SIGUSR1)
		tabs[i] = '1';

    else if (signo == SIGUSR2)
		tabs[i] = '0';
	if (i == 7)
	{
		i = 0;
		y = 0;
		while (i != 7)
		{
			if (tabs[i] == '1')
			{
				y++;
				break;
			}
			i++;
		}
		if (y == 0)
			exit (0);
		y = -1;
		while (++y <= 8)
			printf("tab[%d] : %c\n", y, tabs[y]);
		printf("%c", binary_atoi(tabs));
		i = -1;
	}
	i++;
}


char *print_char()
{
    char *tabs;
    int i = 7;
    int j = 0;
	int numb = 9;
	
    tabs = malloc(sizeof(char) * numb);
    while (i >= 0)
    {
        tabs[j] = bits + '0';
        i--;
        j++;
        pause();
    }
    tabs[j] = '\0';
    return (tabs);
}


int main() 
{   
    int i;
	int y;
    char *tabs;

    /*Un signal est une notification asynchrone envoyée à un processus pour lui signaler l'apparition d'un événement.
    Signal() renvoie un pointeur vers handler()*/
    signal(SIGUSR1, &handler);
    signal(SIGUSR2, &handler);
    int pid_c = getpid();
    ft_printf("listening... %d\n", pid_c);
	i = 0;
	while (1)
		pause();

    ft_printf("terminating... %d\n", pid_c);
 }