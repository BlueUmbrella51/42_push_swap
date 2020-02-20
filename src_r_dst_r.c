/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:52:22 by lravier        #+#    #+#                */
/*   Updated: 2020/02/20 13:52:41 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	src_r_dst_r_a(t_sort **stacks, t_path *target,
char src, t_list **solution)
{
	while (target->src_r != 0)
	{
		if (!add_instruction(RA, stacks, solution))
			return (0);
		target->src_r -= 1;
	}
	while (target->dst_r != 0)
	{
		if (!add_instruction(RB, stacks, solution))
			return (0);
		target->dst_r -= 1;
	}
	return (1);
}

static int	src_r_dst_r_b(t_sort **stacks, t_path *target,
char src, t_list **solution)
{
	while (target->src_r != 0)
	{
		if (!add_instruction(RB, stacks, solution))
			return (0);
		target->src_r -= 1;
	}
	while (target->dst_r != 0)
	{
		if (!add_instruction(RA, stacks, solution))
			return (0);
		target->dst_r -= 1;
	}
	return (1);
}

int			src_r_dst_r(t_sort **stacks, t_path *target, char src,
t_list **solution)
{
	while (target->src_r != 0 && target->dst_r != 0)
	{
		if (!add_instruction(RR, stacks, solution))
			return (0);
		target->src_r -= 1;
		target->dst_r -= 1;
	}
	if (src == 'a')
		return (src_r_dst_r_a(stacks, target, src, solution));
	else
		return (src_r_dst_r_b(stacks, target, src, solution));
}
