/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:45:22 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/01/31 19:35:30 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	lwords(char const *s, char c)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != 0)
	{
		len++;
		i++;
	}
	return (len);
}

static	size_t	twords(char const *s, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			num++;
		while (s[i] != c && s[i + 1] != 0)
			i++;
		i++;
	}
	return (num);
}

char			**ft_split(char const *s, char c)
{
	char	**ssplit;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(ssplit = malloc(sizeof(char *) * (twords(s, c) + 1))))
		return (NULL);
	while (i < twords(s, c))
	{
		while (s[j] == c && s[j] != '\0')
		{
			j++;
		}
		ssplit[i] = ft_substr(s, j, lwords(&s[j], c));
		while (s[j] != c && s[j] != '\0')
		{
			j++;
		}
		i++;
	}
	ssplit[i] = NULL;
	return (ssplit);
}
