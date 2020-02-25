/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:41:16 by lravier        #+#    #+#                */
/*   Updated: 2020/02/25 16:25:21 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int		choose_sort(t_sort **stacks, t_list **solution)
{
	int			res;

	res = 0;
	if ((*stacks)->len_a <= 6)
		res = sort_short(stacks, solution);
	else
		res = sort(stacks, solution);
	if (res == 1)
		print_solution(solution);
	return (res);
}

int				main(int argc, char *argv[])
{
	t_sort		*stacks;
	t_list		*solution;
	int			res;

	res = 0;
	stacks = NULL;
	solution = NULL;
	if (argc == 1)
		return (0);
	if (!initialize_stacks(&stacks))
		return (ft_error("Error\n", 0));
	if (!get_input(&stacks, argc, argv, 1))
	{
		free_memory(&stacks, &solution);
		return (ft_error("Error\n", 0));
	}
	stacks->len_a = argc - 1;
	if (check_sorted(&stacks))
	{
		free_memory(&stacks, &solution);
		return (1);
	}
	res = choose_sort(&stacks, &solution);
	free_memory(&stacks, &solution);
	return (res);
}
