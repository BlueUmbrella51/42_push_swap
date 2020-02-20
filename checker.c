/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 12:51:24 by lravier        #+#    #+#                */
/*   Updated: 2020/02/20 15:19:43 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int		skip_flags(char *argv[])
{
	int		i;

	i = 1;
	while (argv[i] && (ft_strcmp(argv[i], "-n") == 0 ||
	ft_strcmp(argv[i], "-r") == 0
	|| ft_strcmp(argv[i], "-i") == 0))
		i++;
	return (i);
}

static int		check_flags(int *flags, char *argv[])
{
	int i;

	i = 1;
	ft_memset(flags, 0, sizeof(int) * 3);
	while (i < 4 && argv[i])
	{
		if (ft_strcmp("-n", argv[i]) == 0)
			flags[0] = 1;
		if (ft_strcmp("-r", argv[i]) == 0)
			flags[1] = 1;
		if (ft_strcmp("-i", argv[i]) == 0)
			flags[2] = 1;
		i++;
	}
	return (skip_flags(argv));
}

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

static void		create_output(int *flags, t_sort **stacks, t_list **solution)
{
	do_flags(flags, solution, stacks);
	if (!check_sorted(stacks) || (*stacks)->len_b != 0)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	free_memory(stacks, solution);
}

int				main(int argc, char *argv[])
{
	t_sort		*stacks;
	int			flags[3];
	t_list		*solution;
	int			i;

	stacks = NULL;
	solution = NULL;
	if (argc < 2)
		return (0);
	i = check_flags(flags, argv);
	if (i == argc)
		return (ft_error("Error\n", 0));
	if (i + 1 == argc)
		return (1);
	if (!initialize_stacks(&stacks))
		return (ft_error("Error\n", 0));
	if (!get_input(&stacks, argc, argv, i))
		return (ft_error("Error\n", 0));
	if (!read_commands(&stacks, &solution))
	{
		free_memory(&stacks, &solution);
		return (ft_error("Error\n", 0));
	}
	create_output(flags, &stacks, &solution);
	return (1);
}
