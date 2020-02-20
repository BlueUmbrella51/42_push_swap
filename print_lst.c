/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:39:38 by lravier        #+#    #+#                */
/*   Updated: 2020/02/20 13:40:03 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void		print_lst(t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp)
	{
		ft_putstr(ft_itoa(*(int *)tmp->content));
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
