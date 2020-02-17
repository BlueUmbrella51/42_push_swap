/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_short.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 15:36:46 by lravier        #+#    #+#                */
/*   Updated: 2020/02/17 15:36:46 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/* Input can't already be sorted */

static int	rotate_a(t_sort **stacks, t_list **solution, int rot)
{
	int		i;

	i = 0;
	while (i < rot)
	{
		if (!add_instruction(RA, stacks, solution))
			return (0);
		i++;
	}
	if (!add_instruction(PB, stacks, solution))
		return (0);
	return (1);
}

static int	rev_rotate_a(t_sort **stacks, t_list **solution, int rot)
{
	int		i;

	i = 0;
	while (i < rot)
	{
		if (!add_instruction(RRA, stacks, solution))
			return (0);
		i++;
	}
	if (!add_instruction(PB, stacks, solution))
		return (0);
	return (1);
}

static int	push_lowest_half(t_sort **stacks, t_list **solution)
{
	int		len;
	int		i;
	int		rot;
	int		rev_rot;

	len = (*stacks)->len_a - 3;
	i = 0;
	while (i < len)
	{
		find_high_low(stacks, 'a');
		rot = distance_low(stacks, (*stacks)->low_a, 'b');
		rev_rot = (*stacks)->len_a - rot;
		if (rot < rev_rot)
		{
			if (!rotate_a(stacks, solution, rot))
				return (0);
		}
		else
		{
			if (!rev_rotate_a(stacks, solution, rev_rot))
				return (0);
		}
		i++;
	}
	return (1);
}

int			sort_short(t_sort **stacks, t_list **solution)
{
	if ((*stacks)->len_a == 2)
		return (add_instruction(SA, stacks, solution));
	if ((*stacks)->len_a == 3)
		return (sort_three(stacks, solution));
	else
	{
		if (!push_lowest_half(stacks, solution))
			return (0);
		if (!sort_short_halves(stacks, solution))
			return (0);
	}
	return (1);
}