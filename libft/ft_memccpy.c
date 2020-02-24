/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:15:32 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/01/13 18:46:30 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*src1;
	unsigned char	*dst1;
	unsigned char	c1;
	size_t			i;

	i = 0;
	c1 = (unsigned char)c;
	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	while (i < n)
	{
		dst1[i] = src1[i];
		if (src1[i] == c1)
			return (&dst[i + 1]);
		i++;
	}
	return (0);
}
