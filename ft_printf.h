/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:09:51 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/02/24 13:08:50 by cruiz-de         ###   ########.fr       */
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

void	ft_putchar(va_list args);
void	ft_puthex(int n);
void	ft_putHex(int n);
void	ft_putnbr(int n);
void	ft_putunbr(unsigned int n);
void	ft_putstr(va_list args);

#endif
