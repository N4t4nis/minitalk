/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:30:16 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/07 21:45:44 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr_on_next;

	while (*lst)
	{
		ptr_on_next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = 0;
		*lst = ptr_on_next;
	}
	*lst = 0;
}
