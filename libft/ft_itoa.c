/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:26:24 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/01/29 17:56:33 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fillstr(char *str, long n, int len)
{
	char c;

	if (n / 10 > 0)
		ft_fillstr(str, n / 10, len - 1);
	c = n % 10 + '0';
	str[len] = c;
}

static int	ft_count(int n)
{
	int	count;

	count = 1;
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*str;

	len = ft_count(n);
	nb = n;
	if (n < 0)
	{
		len = len + 1;
		nb = -nb;
	}
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	ft_fillstr(str, nb, len - 1);
	str[len] = '\0';
	return (str);
}
