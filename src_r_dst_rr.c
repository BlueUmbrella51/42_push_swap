/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:53:25 by lravier        #+#    #+#                */
/*   Updated: 2020/02/20 13:54:02 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int		src_r_dst_rr_a(t_sort **stacks, t_path *target,
t_list **solution)
{
	while (target->src_r != 0)
	{
		if (!add_instruction(RA, stacks, solution))
			return (0);
		target->src_r -= 1;
	}
	while (target->dst_rr != 0)
	{
		if (!add_instruction(RRB, stacks, solution))
			return (0);
		target->dst_rr -= 1;
	}
	return (1);
}

static int		src_r_dst_rr_b(t_sort **stacks, t_path *target,
t_list **solution)
{
	while (target->src_r != 0)
	{
		if (!add_instruction(RB, stacks, solution))
			return (0);
		target->src_r -= 1;
	}
	while (target->dst_rr != 0)
	{
		if (!add_instruction(RRA, stacks, solution))
			return (0);
		target->dst_rr -= 1;
	}
	return (1);
}

int				src_r_dst_rr(t_sort **stacks, t_path *target, char src,
t_list **solution)
{
	if (src == 'a')
		return (src_r_dst_rr_a(stacks, target, solution));
	else
		return (src_r_dst_rr_b(stacks, target, solution));
}
