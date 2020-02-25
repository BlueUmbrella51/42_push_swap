/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:41:16 by lravier        #+#    #+#                */
/*   Updated: 2020/02/25 21:20:08 by lravier       ########   odam.nl         */
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
	if (!validate_input(argc, argv, &stacks, 1))
		return (0);
	if (check_sorted(&stacks))
	{
		free_memory(&stacks, &solution);
		return (1);
	}
	res = choose_sort(&stacks, &solution);
	free_memory(&stacks, &solution);
	return (res);
}
