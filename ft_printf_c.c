/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:52:06 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/02/24 21:17:26 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(char c, t_flags *flags)
{
	if (flags->width > 0 && flags->minus == -1)
		flags->count += ft_print_space(flags->width - sizeof(char), flags->zero);
	ft_putchar(c);
	if (flags->width > 0 && flags->minus == 1)
		flags->count += ft_print_space(flags->width - sizeof(char), flags->zero);
}
