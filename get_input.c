/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:37:38 by lravier        #+#    #+#                */
/*   Updated: 2020/02/26 11:36:00 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static long		ft_strtol(char *str)
{
	int		i;
	int		polar;
	long	result;

	result = 0;
	i = 0;
	polar = 1;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
	{
		if (str[i] == '-')
			polar = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * polar);
}

static int		get_part_input(t_sort **stacks, char *argv[], int i,
char **args)
{
	int			j;
	long		n;

	j = 0;
	while (args[j])
	{
		if (!validate_argument(args[j]))
			return (0);
		n = ft_strtol(args[j]);
		if (n < INT_MIN || n > INT_MAX)
			return (0);
		if (!ft_lstaddend(&(*stacks)->a, &n, sizeof(int)))
			return (0);
		j++;
	}
	return (1);
}

int				get_input(t_sort **stacks, int argc, char *argv[], int i)
{
	char **args;

	while (i < argc)
	{
		args = ft_strsplit(argv[i], ' ');
		if (!args)
			return (0);
		if (!get_part_input(stacks, argv, i, args))
		{
			free_args(args);
			return (0);
		}
		free_args(args);
		i++;
	}
	(*stacks)->len_a = ft_lstlen(&(*stacks)->a);
	if ((*stacks)->len_a <= 1)
		return (1);
	if (!check_duplicates(&(*stacks)->a, (*stacks)->len_a))
		return (0);
	return (1);
}
