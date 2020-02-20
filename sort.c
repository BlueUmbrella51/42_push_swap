/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:46:10 by lravier        #+#    #+#                */
/*   Updated: 2020/02/20 13:51:01 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void		setup(t_sort **stacks, t_list **distances, t_list **solution)
{
	add_instruction(PB, stacks, solution);
	add_instruction(PB, stacks, solution);
	if ((*(int *)(*stacks)->b->content) < (*(int *)(*stacks)->b->next->content))
		add_instruction(SB, stacks, solution);
}

static int		sort_to_b(t_sort **stacks, t_list **distances,
t_list **solution)
{
	find_high_low(stacks, 'b');
	if (!get_distances(distances, stacks, 'a'))
		return (0);
	if (((t_path *)(*distances)->content)->moves == 0)
	{
		if (!add_instruction(PB, stacks, solution))
			return (0);
	}
	else
	{
		if (!find_target(stacks, distances, 'a', solution))
			return (0);
		if (!add_instruction(PB, stacks, solution))
			return (0);
	}
	return (1);
}

static int		sort_to_a(t_sort **stacks, t_list **distances,
t_list **solution)
{
	find_high_low(stacks, 'a');
	if (!get_distances(distances, stacks, 'b'))
		return (0);
	if (((t_path *)(*distances)->content)->moves == 0)
	{
		if (!add_instruction(PA, stacks, solution))
			return (0);
	}
	else
	{
		if (!find_target(stacks, distances, 'b', solution))
			return (0);
		if (!add_instruction(PA, stacks, solution))
			return (0);
	}
	return (1);
}

static int		find_start(t_sort **stacks, t_list **solution,
t_list **distances)
{
	int res;

	res = rotate_lowest_to_top(stacks, solution);
	ft_lstdel(distances, &ft_del);
	return (res);
}

int				sort(t_sort **stacks, t_list **solution)
{
	t_list		*distances;

	distances = NULL;
	setup(stacks, &distances, solution);
	while ((*stacks)->len_a > 3)
	{
		if (!sort_to_b(stacks, &distances, solution))
		{
			ft_lstdel(&distances, &ft_del);
			return (0);
		}
	}
	sort_three(stacks, solution);
	while ((*stacks)->b)
	{
		if (!sort_to_a(stacks, &distances, solution))
		{
			ft_lstdel(&distances, &ft_del);
			return (0);
		}
	}
	return (find_start(stacks, solution, &distances));
}
