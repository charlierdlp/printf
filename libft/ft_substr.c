/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:47:25 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/01/28 20:55:09 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup(""));
	size = ft_strlen(s);
	i = 0;
	if (start > size)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
