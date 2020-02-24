/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:38:01 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/02/24 21:17:23 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_start_flags(t_flags *flags)
{
	flags->precision = -1;
	flags->width = -1;
	flags->minus = -1;
	flags->zero = -1;
	flags->count = 0;
}

void	ft_print_basic(const char *str, int *i, va_list args)
{
	while (str[*i] == '\0')
	{
		if (str[*i] == 'c')
			ft_print_c(va_arg(args, int));
		else if (str[*i] == 's')
			ft_putstr(args);
		else if (str[*i] == 'd' || str[*i] == 'i')
			ft_putnbr(va_arg(args, int));
		else if (str[*i] == 'u')
			ft_putunbr(va_arg(args, unsigned int));
		else if (str[*i] == 'x')
			ft_puthex(va_arg(args, int));
		else if (str[*i] == 'X')
			ft_putHex(va_arg(args, int));
		else if (str[*i] == '%')
			write(1, "%", 1);
		*i += *i + 1;
	}
}

static void	ft_minus_zero(char *str, int *i, t_flags *flags)
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
		*i += *i + 1;
	}
}

static void	ft_numbers_and(char *str, int *i, t_flags *flags, va_list args)
{
	if (str[*i] == '*')
	{
		flags->width = va_arg(args, int);
		*i += *i + 1;
	}
	if (str[*i] > '0' && str[*i] <= '9')
	{
		flags->width = ft_atoi(&str[*i]);
		while (str[*i] >= '0' && str[*i] <= '9')
			*i += *i + 1;
	}
}

int		ft_printf(char *str, ...)
{
	va_list	args;
	t_flags flags;
	va_start(args, str);
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_minus_zero(str, &i, &flags);
			ft_numbers_and(str, &i, &flags, args);
			ft_print_basic(str, &i, args);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

int main()
{
	ft_printf("string: %s, caracter: %c, %% numero: %d, unsigned int: %u, hexadecimal: %x, Hex: %X", "hola", 'c', -1, 9, 255, 255);
	printf("string: %s, caracter: %c, %% numero: %d, unsigned int: %u, hexadecimal: %x, Hex: %X", "hola", 'c',-1, 9, 255, 255);
}
