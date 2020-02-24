/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:09:51 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/02/24 21:17:29 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int precision;
	int width;
	int minus;
	int zero;
}				t_flags;

int		ft_print_c(va_args, int);
int		ft_print_space(int n, int type);
void	ft_puthex(unsigned int n);
void	ft_putHex(unsigned int n);
void	ft_putnbr(int n);
void	ft_putunbr(unsigned int n);
void	ft_putstr(va_list args);

#endif
