/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <nbenhado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:23:57 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/29 20:36:36 by nbenhado         ###   ########.fr       */
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
        printf("test\n");

}


int main() 
{   
    /*Un signal est une notification asynchrone envoyée à un processus pour lui     signaler l'apparition d'un événement.
    Signal() renvoie un pointeur vers handler()*/
    int car;
    struct sigaction act;
    
    act.sa_handler = handler;
    sigaction(SIGUSR1, &act, NULL);
    read(0, &car, sizeof(car)) <0) 
    
    int pid_c = getpid();
    ft_printf("listening... %d\n", pid_c);
    ft_printf("terminating... %d\n", pid_c);
    while (1) pause();
}