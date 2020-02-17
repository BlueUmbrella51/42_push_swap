/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 15:38:13 by lravier        #+#    #+#                */
/*   Updated: 2020/02/14 15:38:13 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int			do_op(char *instr, t_sort **stacks)
{
	int res;

	res = 0;
	if (ft_strcmp(SA, instr) == 0)
		res = ft_sa(stacks);
	else if (ft_strcmp(SB, instr) == 0)
		res = ft_sb(stacks);
	else if (ft_strcmp(SS, instr) == 0)
		res = ft_ss(stacks);
	else if (ft_strcmp(PA, instr) == 0)
		res = ft_pa(stacks);
	else if (ft_strcmp(PB, instr) == 0)
		res = ft_pb(stacks);
	else if (ft_strcmp(RA, instr) == 0)
		res = ft_ra(stacks);
	else if (ft_strcmp(RB, instr) == 0)
		res = ft_rb(stacks);
	else if (ft_strcmp(RR, instr) == 0)
		res = ft_rr(stacks);
	else if (ft_strcmp(RRA, instr) == 0)
		res = ft_rra(stacks);
	else if (ft_strcmp(RRB, instr) == 0)
		res = ft_rrb(stacks);
	else if (ft_strcmp(RRR, instr) == 0)
		res = ft_rrr(stacks);
	return (res);
}