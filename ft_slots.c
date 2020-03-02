/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:09:03 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/03/02 15:31:12 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_slots(int n, int type)
{
	int i;

	i = 0;
	if (type == -1)
	{
		while (i < n)
		{
			write(1, " ", 1);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			write(1, "0", 1);
			i++;
		}
	}
	return (i);
}
