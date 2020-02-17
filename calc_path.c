/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 14:25:58 by lravier        #+#    #+#                */
/*   Updated: 2020/02/16 14:25:58 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/*	Path types:
	1: src_r && dst_r
	2: src_r && dst_rr
	3: src_rr && dst_r
	4: src_rr && dst_rr
*/

static int	find_shortest(int *moves, int len)
{
	int	i;
	int index;
	int	smallest;

	i = 0;
	index = 0;
	smallest = moves[i];  
	while (i < len)
	{
		if (moves[i] < smallest)
		{
			smallest = moves[i];
			index = i;
		}
		i++;
	}
	return (index + 1);
}

void		calculate_path(t_list **elem)
{
	t_path	*tmp;
	int		moves[4];

	tmp = (t_path *)((*elem)->content);
	if (tmp->src_r > tmp->dst_r)
		moves[0] = tmp->src_r;
	else
		moves[0] = tmp->dst_r;
	moves[1] = tmp->src_r + tmp->dst_rr;
	moves[2] = tmp->src_rr + tmp->dst_r;
	if (tmp->src_rr > tmp->dst_rr)
		moves[3] = tmp->src_rr;
	else
		moves[3] = tmp->dst_rr;
	tmp->type = find_shortest(moves, 4);
	tmp->moves = moves[tmp->type - 1];
}