/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 17:50:22 by lravier        #+#    #+#                */
/*   Updated: 2020/02/17 17:50:22 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void		check_flags(int *flags, char *argv[])
{
	int i;

	i = 1;
	ft_memset(flags, 0, sizeof(int) * 3);
	while (i < 4)
	{
		if (ft_strcmp("-n", argv[i]) == 0)
			flags[0] = 1;
		if (ft_strcmp("-r", argv[i]) == 0)
			flags[1] = 1;
		if (ft_strcmp("-i", argv[i]) == 0)
			flags[2] = 1;
		i++;
	}
}

/* Add printing:
	number of instructions flags[0], -n
	result flags[1], -r
	instructions flags[2], -i
*/

static void		do_flags(int *flags, t_list **solution,
t_sort **stacks)
{
	if (flags[2])
	{
		ft_putstr("Operations:\n");
		print_solution(solution);
	}
	if (flags[0])
	{
		ft_putstr("Number of operations: ");
		ft_putstr(ft_itoa(ft_lstlen(solution)));
		ft_putchar('\n');
	}
	if (flags[1])
	{
		ft_putstr("Result:\n");
		print_lst(&(*stacks)->a);
	}
}

int				main(int argc, char *argv[])
{
	t_sort		*stacks;
	int			flags[3];
	t_list		*solution;

	stacks = NULL;
	solution = NULL;
	check_flags(flags, argv);
	if (argc < 2)
		return (0);
	if (!initialize_stacks(&stacks))
		return (ft_error("Error\n", 0));
	if (!get_input(&stacks, argc, argv))
		return (ft_error("Error\n", 0));
	if (!read_commands(&stacks, &solution))
	{
		free_memory(&stacks, &solution);
		return (ft_error("Error\n", 0));
	}
	do_flags(flags, &solution, &stacks);
	if (!check_sorted(&stacks) || stacks->len_b != 0)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	free_memory(&stacks, &solution);
	return (1);
}