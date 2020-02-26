/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:56:41 by lravier        #+#    #+#                */
/*   Updated: 2020/02/26 14:03:24 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int				validate_argument(char *arg)
{
	int i;
	int space;

	i = 0;
	space = 0;
	while (arg[space] && ft_isspace(arg[space]))
		space++;
	while (arg[i + space] && !ft_isspace(arg[i + space]))
	{
		if (!(ft_isdigit(arg[i + space]) || (i == 0
		&& (arg[i + space] == '-' || arg[i + space] == '+')
		&& ft_isdigit(arg[i + space + 1]))))
			return (0);
		i++;
	}
	while (arg[i + space] && ft_isspace(arg[i + space]))
		space++;
	i += space;
	if (i != ft_strlen(arg) || (i - space) > 11)
		return (0);
	return (1);
}

int				validate_input(int argc, char *argv[], t_sort **stacks, int i)
{
	t_list *solution;

	solution = NULL;
	if (!initialize_stacks(stacks))
		return (ft_error("Error\n", 0));
	if (!get_input(stacks, argc, argv, i))
	{
		free_memory(stacks, &solution);
		return (ft_error("Error\n", 0));
	}
	if ((*stacks)->len_a == 0)
	{
		free_memory(stacks, &solution);
		return (0);
	}
	return (1);
}
