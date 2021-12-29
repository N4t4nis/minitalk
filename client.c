/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:30:05 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/29 20:14:08 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>



void            client(int pid, char *str)
{
    // envoie le signal SIGUSR1 au pid (donc au serveur), return 0 si ok, sinon -1
    if (kill(pid, SIGUSR1))
        ft_putstr_fd(str, 1);
    else
        printf("rate");
}

//indique ce que fait SIGUSR1 ou SIGUSR2 (gestionnaire)
// parametre = signal qui l'a activee (1 ou 2 dans notre cas)
static void handler(int signo)
{
    if (signo == SIGUSR1)
        printf("message recue bg\n");

}


int main(int ac, char **av)
{
    //client(ft_atoi(av[1]), av[2]);   
    kill(ft_atoi(av[1]), SIGUSR1);
}




