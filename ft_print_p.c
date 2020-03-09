/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 21:27:57 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/03/09 18:06:45 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write(unsigned long n, t_flags *flags, int len)
{
	flags->count += write(1, "0x", 2);
	flags->count += ft_slots(flags->precision - len, 1);
	ft_puthex(n, flags);
}

void	ft_precision_p(unsigned long n, t_flags *flags, int len)
{
	if (flags->width > 0 && flags->minus == -1)
	{
		if (flags->precision < len)
			flags->count += ft_slots(flags->width - len - 2, -1);
		else
			flags->count += ft_slots(flags->width - flags->precision - 2, -1);
		ft_write(n, flags, len);
	}
	else if (flags->width > 0 && flags->minus == 1)
	{
		ft_write(n, flags, len);
		if (flags->precision < len - 2)
			flags->count += ft_slots(flags->width - len - 2, -1);
		else
			flags->count += ft_slots(flags->width - flags->precision - 2, -1);
	}
	else
		ft_write(n, flags, len);
}

void	ft_print_p(unsigned long address, t_flags *flags)
{
	int				len;

	len = ft_count_x(address);
	if (flags->precision == 0)
	{
		if (flags->width != -1)
			flags->count += ft_slots(flags->width - 2, -1);
		flags->count += write(1, "0x", 2);
		return ;
	}
	if (flags->precision != -1)
		return (ft_precision_p(address, flags, len));
	if (flags->width > 0 && flags->minus == -1)
		flags->count += ft_slots(flags->width - len - 2, -1);
	flags->count += write(1, "0x", 2);
	ft_puthex(address, flags);
	if (flags->width > 0 && flags->minus == 1)
		flags->count += ft_slots(flags->width - len - 2, -1);
}
