/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:12:53 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/02/27 13:46:16 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*src;
	char	*dst;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	src = (char *)s1;
	len = ft_strlen((char *)s1);
	if (!(dst = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
