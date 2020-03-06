/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extras.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 05:20:30 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/03/06 19:52:44 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_start_flags(t_flags *flags)
{
	flags->precision = -1;
	flags->width = -1;
	flags->minus = -1;
	flags->zero = -1;
}

int		ft_count(int n)
{
	int	count;

	count = n < 0 ? 2 : 1;
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

int		ft_count_x(unsigned long n)
{
	int	count;

	count = 1;
	while (n / 16 != 0)
	{
		count++;
		n = n / 16;
	}
	return (count);
}
