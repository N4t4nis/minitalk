/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:34:56 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/07 23:25:47 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isincharset(char comp, const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == comp)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		y;
	int		end_of_s1;
	char	*ret;

	if (!s1)
		return (NULL);
	end_of_s1 = ft_strlen(s1) - 1;
	i = 0;
	y = 0;
	if (isincharset(s1[0], set))
		while (isincharset(s1[i], set))
			i++;
	if (isincharset(s1[end_of_s1], set))
		while (isincharset(s1[end_of_s1--], set) && end_of_s1 >= i)
			y++;
	ret = ft_substr(s1, i, ft_strlen(s1) - y - i);
	if (!ret)
		return (NULL);
	return (ret);
}
