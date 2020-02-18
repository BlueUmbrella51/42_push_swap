/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_highest.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 14:52:40 by lravier        #+#    #+#                */
/*   Updated: 2020/02/14 14:52:40 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	set_high_low(t_sort **stacks, int high, int low, char st)
{
	if (st == 'a')
	{
		(*stacks)->high_a = high;
		(*stacks)->low_a = low;
	}
	else
	{
		(*stacks)->high_b = high;
		(*stacks)->low_b = low;
	}
}

void		find_high_low(t_sort **stacks, char st)
{
	int		high;
	int		low;
	t_list	*tmp;

	if (st == 'a')
		tmp = (*stacks)->a;
	else
		tmp = (*stacks)->b;
	high = (*(int *)(tmp->content));
	low = (*(int *)(tmp->content));
	tmp = tmp->next;
	while (tmp)
	{
		if ((*(int *)(tmp->content)) > high)
			high = (*(int *)(tmp->content));
		if ((*(int *)(tmp->content)) < low)
			low = ((*(int *)tmp->content));
		tmp = tmp->next;
	}
	set_high_low(stacks, high, low, st);
}
