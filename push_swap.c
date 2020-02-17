/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 17:01:15 by lravier        #+#    #+#                */
/*   Updated: 2020/02/14 17:01:15 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void		print_solution(t_list **solution)
{
	t_list			*tmp;
	t_instruction	*val;

	tmp = *solution;
	while (tmp)
	{
		val = (t_instruction *)tmp->content;
		write(1, val->instr, val->len);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

static void		free_memory(t_sort **stacks, t_list **solution)
{
	ft_lstdel(&(*stacks)->a, &ft_del);
	ft_lstdel(&(*stacks)->b, &ft_del);
	ft_lstdel(solution, &ft_del);
	free (*stacks);
}

int				main(int argc, char *argv[])
{
	t_sort		*stacks;
	t_list		*solution;
	int			res;

	stacks = NULL;
	solution = NULL;
	if (argc < 2)
		return (ft_error("Error\n", 0));
	if (!initialize_stacks(&stacks))
		return (ft_error("Error\n", 0));
	if (!get_input(&stacks, argc, argv))
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
	if (stacks->len_a <= 6)
		res = sort_short(&stacks, &solution);
	else 
		res = sort(&stacks, &solution);
	if (res == 1)
		print_solution(&solution);
	free_memory(&stacks, &solution);
	return (res);
}