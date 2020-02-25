/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:47:14 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/02/25 21:14:27 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_s(va_list args, t_flags *flags)
{
	char *str;

	str = va_arg(args, char *);
	if (flags->width > 0 && flags->minus == -1)
		flags->count += ft_printf_space(flags->width - ft_strlen(str), flags->zero);
	flags->count += write(1, &str[i], 1);
	if (flags->width > 0 && flags->minus == 1)
		flags->count += ft_print_space(flags->width - ft_strlen(str), flags->zero );
}
