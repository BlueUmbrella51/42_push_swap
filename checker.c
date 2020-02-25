/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 12:51:24 by lravier        #+#    #+#                */
/*   Updated: 2020/02/25 16:22:35 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void		create_output(int *flags, t_sort **stacks, t_list **solution)
{
	do_flags(flags, solution, stacks);
	if (!check_sorted(stacks) || (*stacks)->len_b != 0)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	free_memory(stacks, solution);
}

static int		check_input(int argc, char *argv[], int *flags, int *i)
{
	ft_memset(flags, 0, sizeof(int) * 3);
	if (argc == 1)
		return (0);
	*i = skip_flags(argv);
	if (*i != 1)
		check_flags(flags, argv);
	if (*i == argc)
		return (0);
	return (1);
}

int				main(int argc, char *argv[])
{
	t_sort		*stacks;
	int			flags[3];
	t_list		*solution;
	int			i;

	stacks = NULL;
	solution = NULL;
	if (!check_input(argc, argv, flags, &i))
		return (ft_error("Error\n", 0));
	if (!initialize_stacks(&stacks))
		return (0);
	if (!get_input(&stacks, argc, argv, i))
	{
		free_memory(&stacks, &solution);
		return (ft_error("Error\n", 0));
	}
	if (!read_commands(&stacks, &solution))
	{
		free_memory(&stacks, &solution);
		return (ft_error("Error\n", 0));
	}
	create_output(flags, &stacks, &solution);
	return (1);
}
