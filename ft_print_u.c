/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:11:10 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/03/05 20:52:06 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u(unsigned int n, t_flags *flags)
{
	int	len;

	len = ft_count(n);
	if (flags->precision == 0)
	{
		flags->count += ft_slots(flags->width, flags->zero);
		return ;
	}
	if (flags->precision != -1)
		return (ft_precision(n, flags, len));
	if (flags->width > 0 && flags->minus == 1)
		return (ft_minus(n, flags, len));
	if (flags->width > 0 && flags->minus == -1)
		flags->count += ft_slots(flags->width - len, flags->zero);
	ft_putunbr(n, flags);
}
