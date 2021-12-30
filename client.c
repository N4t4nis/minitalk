/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:30:05 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/30 22:41:48 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


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


void            client(int pid, char *str)
{
    // envoie le signal SIGUSR1 au pid (donc au serveur), return 0 si ok, sinon -1
    if (kill(pid, SIGUSR1))
        ft_putstr_fd(str, 1);
    else
        printf("rate");
}

//fonction qui envoie 8 signaux (1 signal pour 1 bits) avec la valeur binaire d'un char (table ascii)
// exemple : char c = 'a' (donc 97) 
// 97 = 1100001 en binaire
// 1 << i va placer un 1 a la derniere case et se decale a chaque iteration : 0000000 / 0000001 / 0000010 / 0000100...
// on compare 97 et 1 << i en binaire, si 1 et 1 = True / si 1 et 0 = False / si 0 et 0 = False
// ca envoi donc 8 signaux avec 1 bits dans l'ordre du nombre 97 en binaire
// kill envoie le signal avec SIGUSR1 si True (1) // SIGUSR2 si False (0)
// je sleep apres chaque signal envoye pour bien qu'ils s'envoient les uns a la suite des autres
void    send_char_with_bits(int pid, char c)
{
	int i;
	int is_true;
	i = 7;
	while (i != -1)
	{
		is_true = c & (1 << i);
		if (is_true)
		{
			kill(pid, SIGUSR1);
			printf("1");
		}
		else
		{
			kill(pid, SIGUSR2);		
			printf("0");
		}
		i--;
		usleep(500);

	}

}

//indique ce que fait SIGUSR1 ou SIGUSR2 (gestionnaire)
// parametre = signal qui l'a activee (1 ou 2 dans notre cas)
static void handler(int signo)
{
    if (signo == SIGUSR1)
        printf("message envoyer bg\n");

}


int main(int ac, char **av)
{
    send_char_with_bits(ft_atoi(av[1]), 'a');
    //signal(SIGUSR1, &handler);
    //kill(ft_atoi(av[1]), SIGUSR1);
	// printf("\n");
	// ftputnbr_base('a', "01");
    //client(ft_atoi(av[1]), av[2]);   
    // kill(ft_atoi(av[1]), SIGUSR1);
    return (0);
}




