/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:54:32 by lravier        #+#    #+#                */
/*   Updated: 2020/02/20 13:54:56 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int		src_rr_dst_r_a(t_sort **stacks, t_path *target,
t_list **solution)
{
	while (target->src_rr != 0)
	{
		if (!add_instruction(RRA, stacks, solution))
			return (0);
		target->src_rr -= 1;
	}
	while (target->dst_r != 0)
	{
		if (!add_instruction(RB, stacks, solution))
			return (0);
		target->dst_r -= 1;
	}
	return (1);
}

static int		src_rr_dst_r_b(t_sort **stacks, t_path *target,
t_list **solution)
{
	while (target->src_rr != 0)
	{
		if (!add_instruction(RRB, stacks, solution))
			return (0);
		target->src_rr -= 1;
	}
	while (target->dst_r != 0)
	{
		if (!add_instruction(RA, stacks, solution))
			return (0);
		target->dst_r -= 1;
	}
	return (1);
}

int				src_rr_dst_r(t_sort **stacks, t_path *target, char src,
t_list **solution)
{
	if (src == 'a')
		return (src_rr_dst_r_a(stacks, target, solution));
	else
		return (src_rr_dst_r_b(stacks, target, solution));
}
