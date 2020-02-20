/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:27:23 by lravier        #+#    #+#                */
/*   Updated: 2020/02/20 13:27:30 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		ft_pa(t_sort **stacks)
{
	t_list	*tmp;

	if (stacks == NULL)
		return (0);
	if (*stacks == NULL)
		return (0);
	if (!(*stacks)->b)
		return (0);
	tmp = ft_lstpop(&(*stacks)->b);
	ft_lstadd(&(*stacks)->a, tmp);
	(*stacks)->len_b -= 1;
	(*stacks)->len_a += 1;
	return (1);
}
