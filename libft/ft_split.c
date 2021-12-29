/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:20:16 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/07 21:48:14 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*split_copy(char const *str, int debut, int taille)
{
	int		i;
	char	*tab;

	i = 0;
	tab = malloc(sizeof(char) * taille + 1);
	if (!tab)
		return (NULL);
	while (i < taille)
	{
		tab[i] = str[debut];
		i++;
		debut++;
	}
	tab[i] = '\0';
	return (tab);
}

static int	next_c(char const *str, int debut, char c)
{
	int	i;

	i = 0;
	while (str[debut] != c && str[debut])
	{
		i++;
		debut++;
	}
	return (i);
}

static int	number_of_tabs(char const *str, char c)
{
	int	i;
	int	number;

	number = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			i += next_c(str, i, c) - 1;
			number += 1;
		}
		i++;
	}
	return (number);
}

static char	**ft_free(char **str, int index)
{
	while (index >= 0)
	{
		free(str[index]);
		index--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	f;
	char	**tab_de_tab;

	if (!s)
		return (NULL);
	tab_de_tab = malloc(sizeof(char *) * (number_of_tabs(s, c) + 1));
	if (!tab_de_tab)
		return (0);
	i = 0;
	f = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			tab_de_tab[f] = split_copy(s, i, next_c(s, i, c));
			if (tab_de_tab[f] == NULL)
				return (ft_free(tab_de_tab, f - 1));
			i += next_c(s, i, c) - 1;
			f++;
		}
		i++;
	}
	tab_de_tab[f] = 0;
	return (tab_de_tab);
}
