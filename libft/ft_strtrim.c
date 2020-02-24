/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:42:58 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/01/31 12:01:08 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	str_len;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != 0)
		i++;
	str_len = ft_strlen(s1);
	j = str_len - 1;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	while (ft_strchr(set, s1[j]) != 0)
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
