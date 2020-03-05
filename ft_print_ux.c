/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:37:09 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/03/05 20:25:12 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precixion_vis(unsigned int n, t_flags *flags, int len)
{
	if (flags->width > 0 && flags->minus == -1)
	{
		if (flags->precision < len)
			flags->count += ft_slots(flags->width - len, -1);
		else
			flags->count += ft_slots(flags->width - flags->precision, -1);
		flags->count += ft_slots(flags->precision - len, 1);
		ft_putuhex(n, flags);
	}
	else if (flags->width > 0 && flags->minus == 1)
	{
		flags->count += ft_slots(flags->precision - len, 1);
		ft_putuhex(n, flags);
		if (flags->precision < len)
			flags->count += ft_slots(flags->width - len, -1);
		else
			flags->count += ft_slots(flags->width - flags->precision, -1);
	}
	else
	{
		flags->count += ft_slots(flags->precision - len, 1);
		ft_putuhex(n, flags);
	}
}

void	ft_minux_vis(unsigned int n, t_flags *flags, int len)
{
	ft_putuhex(n, flags);
	flags->count += ft_slots(flags->width - len, flags->zero);
}

void	ft_print_ux(unsigned int n, t_flags *flags)
{
	int	len;

	len = ft_count_x(n);
	if (flags->precision == 0)
	{
		flags->count += ft_slots(flags->width, flags->zero);
		return ;
	}
	if (flags->precision != -1)
		return (ft_precixion_vis(n, flags, len));
	if (flags->width > 0 && flags->minus == 1)
		return (ft_minux_vis(n, flags, len));
	if (flags->width > 0 && flags->minus == -1)
		flags->count += ft_slots(flags->width - len, flags->zero);
	ft_putuhex(n, flags);
}
