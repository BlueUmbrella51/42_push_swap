/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:42:43 by lravier        #+#    #+#                */
/*   Updated: 2020/02/20 13:42:50 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	dist_low(t_sort **stacks)
{
	t_list	*tmp;
	int		i;
	int		dst;
	int		small;

	i = 0;
	dst = 0;
	tmp = (*stacks)->a;
	small = ((t_path *)(tmp->content))->data;
	while (tmp)
	{
		if (((t_path *)(tmp->content))->data < small)
		{
			dst = i;
			small = ((t_path *)(tmp->content))->data;
		}
		i++;
		tmp = tmp->next;
	}
	return (dst);
}

int			rotate_lowest_to_top(t_sort **stacks, t_list **solution)
{
	int		r;
	int		rr;

	r = dist_low(stacks);
	rr = (*stacks)->len_a - r;
	if (r < rr)
	{
		while (r != 0)
		{
			if (!add_instruction(RA, stacks, solution))
				return (0);
			r--;
		}
	}
	else
	{
		while (rr != 0)
		{
			if (!add_instruction(RRA, stacks, solution))
				return (0);
			rr--;
		}
	}
	return (1);
}
