/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sorted.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 12:50:34 by lravier        #+#    #+#                */
/*   Updated: 2020/02/21 21:14:01 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		check_sorted(t_sort **stacks)
{
	t_list	*curr;
	t_list	*prev;

	if (!stacks)
		return (1);
	if (!*stacks)
		return (1);
	prev = (*stacks)->a;
	if (!prev)
		return (1);
	curr = prev->next;
	while (curr)
	{
		if ((*(int *)prev->content) > (*(int *)curr->content))
			return (0);
		prev = curr;
		curr = curr->next;
	}
	return (1);
}
