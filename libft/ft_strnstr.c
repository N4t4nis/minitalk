/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:34:19 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/05 21:08:07 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len && (ft_strlen(big) >= ft_strlen(little)))
	{
		if (big[i] == little[0])
		{
			y = 0;
			while (big[i + y] == little[y] && little[y] && ((i + y) < len))
				y++;
			if (little[y] == '\0' || y == len)
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
