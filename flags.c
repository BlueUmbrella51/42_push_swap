/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 11:29:14 by lravier        #+#    #+#                */
/*   Updated: 2020/02/26 11:29:26 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int			skip_flags(char *argv[])
{
	int		i;

	i = 1;
	while (argv[i] && (ft_strcmp(argv[i], "-n") == 0 ||
	ft_strcmp(argv[i], "-r") == 0
	|| ft_strcmp(argv[i], "-i") == 0))
		i++;
	return (i);
}

void		check_flags(int *flags, char *argv[])
{
	int i;

	i = 1;
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
}

void		do_flags(int *flags, t_list **solution,
t_sort **stacks)
{
	char *s;

	s = NULL;
	if (flags[2])
	{
		ft_putstr("Operations:\n");
		print_solution(solution);
	}
	if (flags[0])
	{
		ft_putstr("Number of operations: ");
		s = ft_itoa(ft_lstlen(solution));
		ft_putstr(s);
		free(s);
		ft_putchar('\n');
	}
	if (flags[1])
	{
		ft_putstr("Result:\n");
		print_lst(&(*stacks)->a);
	}
}
