/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_target.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 15:28:41 by lravier        #+#    #+#                */
/*   Updated: 2020/02/16 15:28:41 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*	Path types:
	1: src_r && dst_r
	2: src_r && dst_rr
	3: src_rr && dst_r
	4: src_rr && dst_rr
*/

static t_path	*least_moves(t_list **distances)
{
	t_list	*tmp;
	t_path	*iter;
	t_path	*target;

	tmp = *distances;
	target = (t_path *)tmp->content;
	iter = (t_path *)tmp->content;
	while (tmp)
	{
		if (iter->moves < target->moves)
			target = iter;
		tmp = tmp->next;
		if (tmp)
			iter = (t_path *)tmp->content;
	}
	return (target);
}

int			find_target(t_sort **stacks, t_list **distances, char src, t_list **solution)
{
	t_path *target;

	target = least_moves(distances);
	if (target->type == 1)
		return (src_r_dst_r(stacks, target, src, solution));
	else if (target->type == 2)
		return (src_r_dst_rr(stacks, target, src, solution));
	else if (target->type == 3)
		return (src_rr_dst_r(stacks, target, src, solution));
	else
		return (src_rr_dst_rr(stacks, target, src, solution));
}