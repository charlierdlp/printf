/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:07:17 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/03/02 15:46:51 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n)
{
	char	c;

	if (n > 16)
	{
		ft_puthex(n / 16);
		ft_puthex(n % 16);
	}
	else
	{
		if (n > 9)
			c = n + 87;
		else
			c = n + '0';
		write(1, &c, 1);
	}
}

void	ft_putuhex(unsigned int n)
{
	char	c;

	if (n > 16)
	{
		ft_puthex(n / 16);
		ft_puthex(n % 16);
	}
	else
	{
		if (n > 9)
			c = n + 55;
		else
			c = n + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbr(int n, t_flags *flags)
{
	char	tmp;
	long	nb;

	nb = n;
	if (nb < 0 && flags->zero == -1)
	{
		nb = nb * -1;
		flags->count += write(1, "-", 1);
	}
	if (nb > 9)
		ft_putnbr(nb / 10, flags);
	tmp = nb % 10 + '0';
	flags->count += write(1, &tmp, 1);
}

void	ft_putunbr(unsigned int n, t_flags *flags)
{
	char	tmp;

	if (n > 9)
		ft_putunbr(n / 10, flags);
	tmp = n % 10 + '0';
	flags->count += write(1, &tmp, 1);
}

void	ft_putstr(va_list args)
{
	char	*s;
	size_t	i;

	i = 0;
	s = va_arg(args, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}
