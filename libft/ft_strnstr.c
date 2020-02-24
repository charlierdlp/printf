/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:18:02 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/01/14 11:28:38 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*need;
	char	*stack;
	size_t	i;
	size_t	len1;

	len1 = ft_strlen(needle);
	stack = (char *)haystack;
	need = (char *)needle;
	i = 0;
	if (needle[i] == '\0')
		return (&stack[0]);
	while (i < len)
	{
		if (!ft_strncmp(&haystack[i], needle, len1))
		{
			if (i + len1 <= len)
				return (&stack[i]);
		}
		i++;
	}
	return (NULL);
}
