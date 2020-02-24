/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:26:20 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/01/24 12:53:16 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	const unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (const unsigned char *)src;
	if (dst1 == NULL && src1 == NULL)
		return (NULL);
	if (dst1 == src1)
		return (dst);
	else if (dst1 > src1)
	{
		src1 = src1 + len - 1;
		dst1 = dst1 + len - 1;
		while (len > 0)
		{
			*dst1 = *src1;
			dst1--;
			src1--;
			len--;
		}
	}
	else
		dst = ft_memcpy(dst1, src1, len);
	return (dst);
}
