/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:47:14 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/03/02 06:04:24 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_s(va_list args, t_flags *flags)
{
	char	*tmp;
	char	*str;
	int		len;

	str = ft_strdup(va_arg(args, char *));
	if (str == NULL)
		str = ft_strdup("(null)");
	if (flags->precision != -1)
	{
		tmp = str;
		str = ft_substr(tmp, 0, flags->precision);
		free(tmp);
	}
	len = ft_strlen(str);
	if (flags->width > 0 && flags->minus == -1)
		flags->count += ft_print_space(flags->width - len, flags->zero);
	flags->count += write(1, str, len);
	if (flags->width > 0 && flags->minus == 1)
		flags->count += ft_print_space(flags->width - len, flags->zero);
	free(str);
}
