/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:56:28 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/03/02 16:37:51 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_negative(int n, t_flags *flags, int len)
{
	flags->count += write(1, "-", 1);
	flags->count += ft_slots(flags->precision - len + 1, 1);
	ft_putnbr(-n, flags);
}

void	ft_neg_precision(int n, t_flags *flags, int len)
{
	if (flags->width < 0)
	{
		ft_fill_negative(n, flags, len);
	}
	else if (flags->width > 0 && flags->minus == -1)
	{
		if (flags->precision < len)
			flags->count += ft_slots(flags->width - len, flags->zero);
		else
			flags->count += ft_slots(flags->width - flags->precision - 1, -1);
		ft_fill_negative(n, flags, len);
	}
	else if (flags->width > 0 && flags->minus == 1)
	{
		ft_fill_negative(n, flags, len);
		if (flags->precision < len)
			flags->count += ft_slots(flags->width - len, flags->zero);
		else
			flags->count += ft_slots(flags->width - flags->precision - 1, -1);
	}
}

void	ft_precision(int n, t_flags *flags, int len)
{
	if (flags->width > 0 && flags->minus == -1)
	{
		if (flags->precision < len)
			flags->count += ft_slots(flags->width - len, flags->zero);
		else
			flags->count += ft_slots(flags->width - flags->precision,
					flags->zero);
		flags->count += ft_slots(flags->precision - len, 1);
		ft_putnbr(n, flags);
	}
	else if (flags->width > 0 && flags->minus == 1)
	{
		flags->count += ft_slots(flags->precision - len, 1);
		ft_putnbr(n, flags);
		if (flags->precision < len)
			flags->count += ft_slots(flags->width - len, flags->zero);
		else
			flags->count += ft_slots(flags->width - flags->precision,
					flags->zero);
	}
	else
	{
		flags->count += ft_slots(flags->precision - len, 1);
		ft_putnbr(n, flags);
	}
}

void	ft_minus(int n, t_flags *flags, int len)
{
	if (flags->width > 0)
	{
		ft_putnbr(n, flags);
		flags->count += ft_slots(flags->width - len, flags->zero);
	}
}

void	ft_print_d(int n, t_flags *flags)
{
	int	len;
	int zero;

	len = ft_count(n);
	if (flags->precision == 0)
	{
		flags->count += ft_slots(flags->width, flags->zero);
		return ;
	}
	if (flags->precision != -1 && n < 0)
		return (ft_neg_precision(n, flags, len));
	if (flags->precision != -1 && n >= 0)
		return (ft_precision(n, flags, len));
	if (flags->width > 0 && flags->minus == 1)
		return (ft_minus(n, flags, len));
	if (flags->width > 0 && flags->minus == -1)
	{
		if (flags->zero != -1 && n < 0)
		{
			flags->count += write(1, "-", 1);
			zero = 1;
		}
		flags->count += ft_slots(flags->width - len, flags->zero);
	}
	zero == 1 ? ft_putnbr(-n, flags) : ft_putnbr(n, flags);
}
