/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:19:26 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/01/28 19:57:39 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	a;
	size_t	b;

	b = 0;
	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	a = dest_size;
	if (dstsize == 0)
		return (src_size);
	if (dstsize < dest_size)
		return (src_size + dstsize);
	while (a < dstsize - 1 && src[b] != '\0')
	{
		dst[a] = src[b];
		b++;
		a++;
	}
	dst[a] = '\0';
	return (src_size + dest_size);
}
