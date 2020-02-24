/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:20:05 by cruiz-de          #+#    #+#             */
/*   Updated: 2020/01/31 12:23:04 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *aux;

	if (new)
	{
		aux = *lst;
		if (!*lst)
		{
			*lst = new;
			new->next = NULL;
		}
		else
		{
			aux = ft_lstlast(*lst);
			aux->next = new;
		}
	}
}
