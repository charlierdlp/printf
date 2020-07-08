/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:09:51 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/07/07 11:04:03 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int			precision;
	int			width;
	int			minus;
	int			zero;
	int			count;
}				t_flags;

int				ft_printf(const char *str, ...);
void			ft_start_flags(t_flags *flags);
void			ft_print_d(int n, t_flags *flags);
void			ft_print_s(va_list args, t_flags *flags);
void			ft_print_c(char c, t_flags *flags);
void			ft_print_x(unsigned int n, t_flags *flags);
void			ft_print_ux(unsigned int n, t_flags *flags);
void			ft_print_u(unsigned int n, t_flags *flags);
void			ft_print_p(unsigned long n, t_flags *flags);
int				ft_slots(int n, int type);
void			ft_puthex(unsigned long n, t_flags *flags);
void			ft_putuhex(unsigned int n, t_flags *flags);
void			ft_putnbr(int n, t_flags *flags);
void			ft_putunbr(unsigned int n, t_flags *flags);
void			ft_putstr(va_list args);
int				ft_count(int n);
int				ft_count_x(unsigned long x);
void			ft_precision(unsigned int n, t_flags *flags, int len);
void			ft_minus(unsigned int n, t_flags *flags, int len);

#endif
