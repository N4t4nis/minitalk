/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:25:00 by nbenhado          #+#    #+#             */
/*   Updated: 2021/11/26 20:28:27 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)

{
	int		i;
	int		max;
	char	*dest;

	i = 0;
	max = 0;
	while (src[max])
		max++;
	dest = (char *)malloc(sizeof(char) * max + 1);
	if (!dest)
		return (NULL);
	while (i < max)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
