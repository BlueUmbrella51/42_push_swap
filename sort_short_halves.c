/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_short_halves.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:43:16 by lravier        #+#    #+#                */
/*   Updated: 2020/02/25 16:46:27 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	sort_a(t_sort **stacks, t_list **solution)
{
	if ((*stacks)->len_a == 3)
	{
		if (!sort_three(stacks, solution))
			return (0);
	}
	else if ((*stacks)->len_a == 2)
	{
		if ((*(int *)(*stacks)->a->content) >
		(*(int *)(*stacks)->a->next->content))
		{
			if (!add_instruction(SA, stacks, solution))
				return (0);
		}
	}
	return (1);
}

static int	sort_b(t_sort **stacks, t_list **solution)
{
	if ((*stacks)->len_b == 3)
	{
		if (!rev_sort_three(stacks, solution))
			return (0);
	}
	else if ((*stacks)->len_b == 2)
	{
		if ((*(int *)(*stacks)->b->content) <
		(*(int *)(*stacks)->b->next->content))
		{
			if (!add_instruction(SB, stacks, solution))
				return (0);
		}
	}
	return (1);
}

int			sort_short_halves(t_sort **stacks, t_list **solution)
{
	if (!sort_a(stacks, solution) || !sort_b(stacks, solution))
		return (0);
	while ((*stacks)->b)
	{
		if (!add_instruction(PA, stacks, solution))
			return (0);
	}
	return (1);
}
