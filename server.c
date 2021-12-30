/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:23:57 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/30 15:11:50 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

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

//indique ce que fait SIGUSR1 ou SIGUSR2 (gestionnaire)
// parametre = signal qui l'a activee (1 ou 2 dans notre cas)
static void handler(int signo)
{
    if (signo == SIGUSR1)
        printf("Bonne reception du signal 1111\n");
    else if (signo == SIGUSR2)
        printf("Bonne reception du signal 2222\n");
    else
        printf("Unkown signal");
}




int main() 
{   
    /*Un signal est une notification asynchrone envoyée à un processus pour lui     signaler l'apparition d'un événement.
    Signal() renvoie un pointeur vers handler()*/

    signal(SIGUSR1, &handler);
    signal(SIGUSR2, &handler);
    int pid_c = getpid();
    ft_printf("listening... %d\n", pid_c);
    while (1) pause();
    ft_printf("terminating... %d\n", pid_c);
 }