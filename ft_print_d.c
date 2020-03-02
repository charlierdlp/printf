/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:56:28 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/03/02 09:38:14 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_neg_precision(int n, t_flags *flags, int len)
{
	if (flags->width < 0)
	{
		flags->count += write(1, "-", 1);
		flags->count += ft_print_space(flags->precision - len + 1, 1);
		ft_putnbr(-n, flags);
	}
	else if (flags->width > 0 && flags->minus == -1)
	{
		if (flags->precision < len)
			flags->count += ft_print_space(flags->width - len, flags->zero);
		else
			flags->count += ft_print_space(flags->width - flags->precision - 1, -1);
		flags->count += write(1, "-", 1);
		flags->count += ft_print_space(flags->precision - len + 1, 1);
		ft_putnbr(-n, flags);
	}
	else if (flags->width > 0 && flags->minus == 1)
	{
		flags->count += write(1, "-", 1);
		flags->count += ft_print_space(flags->precision - len + 1, 1);
		ft_putnbr(-n, flags);
		if (flags->precision < len)
			flags->count += ft_print_space(flags->width - len, flags->zero);
		else
			flags->count += ft_print_space(flags->width - flags->precision - 1, -1);
	}
}

void	ft_precision(int n, t_flags *flags, int len)
{
	if (flags->width > 0 && flags->minus == -1)
	{
		if (flags->precision < len)
			flags->count += ft_print_space(flags->width - len, flags->zero);
		else
			flags->count += ft_print_space(flags->width - flags->precision,
					flags->zero);
		flags->count += ft_print_space(flags->precision - len, 1);
		ft_putnbr(n, flags);
	}
	else if (flags->width > 0 && flags->minus == 1)
	{
		flags->count += ft_print_space(flags->precision - len, 1);
		ft_putnbr(n, flags);
		if (flags->precision < len)
			flags->count += ft_print_space(flags->width - len, flags->zero);
		else
			flags->count += ft_print_space(flags->width - flags->precision,
					flags->zero);
	}
	else
	{
		flags->count += ft_print_space(flags->precision - len, 1);
		ft_putnbr(n, flags);
	}
}

void	ft_minus(int n, t_flags *flags, int len)
{
	if (flags->width > 0)
	{
		ft_putnbr(n, flags);
		flags->count += ft_print_space(flags->width - len, flags->zero);
	}
}

void	ft_print_d(int n, t_flags *flags)
{
	int	len;
	int zero;

	zero = 0;
	len = ft_count(n);
	if (flags->precision == 0)
	{
		flags->count += ft_print_space(flags->width, flags->zero);
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
		flags->count += ft_print_space(flags->width - len, flags->zero);
	}
	if (zero == 1)
		ft_putnbr(-n, flags);
	else
		ft_putnbr(n, flags);
}
