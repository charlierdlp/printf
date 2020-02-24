/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:57:35 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/01/09 18:37:32 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	a;
	char	*tmp;

	a = 0;
	tmp = (char *)b;
	while (a < len)
	{
		tmp[a] = (unsigned char)c;
		a++;
	}
	return (b);
}
