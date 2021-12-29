/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:21:42 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/07 21:17:51 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	int		i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (unsigned char)searchedChar)
			return ((char *)string + i);
		i++;
	}
	if (string[i] == '\0' && (unsigned char)searchedChar == '\0')
		return ((char *)string + i);
	return (NULL);
}
