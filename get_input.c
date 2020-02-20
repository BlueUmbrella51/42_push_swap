/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:37:38 by lravier        #+#    #+#                */
/*   Updated: 2020/02/20 13:38:18 by lravier       ########   odam.nl         */
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

static int		is_flag(char *s)
{
	if (ft_strcmp(s, "-n") == 0
	|| ft_strcmp(s, "-r") == 0
	|| ft_strcmp(s, "-i") == 0)
		return (1);
	return (0);
}

static int		skip_flags(char *argv[])
{
	int		i;

	i = 1;
	while (is_flag(argv[i]))
		i++;
	return (i);
}

int				get_input(t_sort **stacks, int argc, char *argv[])
{
	int		i;
	long	n;

	i = skip_flags(argv);
	while (i < argc)
	{
		if (!validate_input(argv[i]))
			return (0);
		n = ft_strtol(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			return (0);
		if (!ft_lstaddend(&(*stacks)->a, &n, sizeof(int)))
		{
			ft_lstdel(&(*stacks)->a, &ft_del);
			return (0);
		}
		i++;
	}
	if (!check_duplicates(&(*stacks)->a, argc - 1))
	{
		ft_lstdel(&(*stacks)->a, &ft_del);
		return (0);
	}
	return (1);
}
