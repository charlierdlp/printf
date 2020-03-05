/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:38:01 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/03/05 20:38:32 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_basic(const char *str, int *i, va_list args, t_flags *flags)
{
	if (str[*i] == 'c')
		ft_print_c((char)va_arg(args, int), flags);
	else if (str[*i] == 's')
		ft_print_s(args, flags);
	else if (str[*i] == 'd' || str[*i] == 'i')
		ft_print_d(va_arg(args, int), flags);
	else if (str[*i] == 'u')
		ft_print_u(va_arg(args, unsigned int), flags);
	else if (str[*i] == 'x')
		ft_print_x(va_arg(args, unsigned int), flags);
	else if (str[*i] == 'X')
		ft_print_ux(va_arg(args, unsigned int), flags);
	else if (str[*i] == '%')
		ft_print_c('%', flags);
	*i = *i + 1;
}

void	ft_minus_zero(char *str, int *i, t_flags *flags)
{
	while (str[*i] == '0' || str[*i] == '-')
	{
		if (str[*i] == '-')
		{
			flags->minus = 1;
			flags->zero = -1;
		}
		if (str[*i] == '0' && flags->minus == -1)
			flags->zero = 1;
		*i = *i + 1;
	}
}

void	ft_numbers(char *str, int *i, t_flags *flags, va_list args)
{
	if (str[*i] > '0' && str[*i] <= '9')
	{
		flags->width = ft_atoi(&str[*i]);
		while (str[*i] >= '0' && str[*i] <= '9')
			*i = *i + 1;
	}
}

void	ft_check_precision(char *str, int *i, t_flags *flags, va_list args)
{
	if (str[*i] == '*')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width = -flags->width;
		}
		*i = *i + 1;
	}
	ft_numbers(str, i, flags, args);
	if (str[*i] == '.')
	{
		flags->precision = 0;
		flags->zero = -1;
		*i = *i + 1;
		if (str[*i] == '*')
			flags->precision = va_arg(args, int);
		else
		{
			flags->precision = ft_atoi(&str[*i]);
			while (str[*i] >= '0' && str[*i] <= '9')
				*i = *i + 1;
		}
	}
}

int		ft_printf(char *str, ...)
{
	va_list		args;
	int			i;
	t_flags		flags;

	va_start(args, str);
	flags.count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			ft_start_flags(&flags);
			ft_minus_zero(str, &i, &flags);
			ft_check_precision(str, &i, &flags, args);
			ft_print_basic(str, &i, args, &flags);
		}
		else
		{
			flags.count += write(1, &str[i], 1);
			i++;
		}
	}
	va_end(args);
	return (flags.count);
}
