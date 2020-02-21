/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:56:41 by lravier        #+#    #+#                */
/*   Updated: 2020/02/21 20:17:52 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int				validate_input(char *arg)
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
		&& (arg[i + space] == '-' || arg[i + space] == '+'))))
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
