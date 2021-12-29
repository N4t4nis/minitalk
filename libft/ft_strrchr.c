/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:34:26 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/05 16:44:43 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	int	max;

	max = ft_strlen(string);
	if (string[max] == (unsigned char)searchedChar)
		return ((char *)&string[max]);
	while (max != -1)
	{
		if (string[max] == (unsigned char)searchedChar)
			return ((char *)&string[max]);
		max--;
	}
	return (NULL);
}
