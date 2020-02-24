/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:05:38 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/01/14 14:31:23 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;
	size_t	s1_size;
	size_t	s2_size;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	if (!(dst = (char *)malloc((s1_size + s2_size + 1) * sizeof(char))))
		return (NULL);
	while (s1[++i] != '\0')
	{
		dst[i] = s1[i];
	}
	while (s2[++j] != '\0')
	{
		dst[i] = s2[j];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
