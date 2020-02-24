/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:55:04 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/01/14 11:25:24 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			i;
	unsigned int	n;

	n = 0;
	i = 0;
	if (src == NULL || dest == NULL)
		return (0);
	while (src[i] != '\0')
	{
		i++;
	}
	if (size == 0)
	{
		return (i);
	}
	else
	{
		while (n < (size - 1) && src[n] != '\0')
		{
			dest[n] = src[n];
			n++;
		}
		dest[n] = '\0';
		return (i);
	}
}
