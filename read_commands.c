/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_commands.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 15:18:46 by lravier        #+#    #+#                */
/*   Updated: 2020/02/14 15:18:46 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int			read_commands(t_sort **stacks)
{
	char	*instr;
	int		res;

	res = 1;
	instr = NULL;
	while (res > 0)
	{
		res = get_next_line(0, &instr);
		if (res > 0)
		{
			if (instr)
			{
				if (!do_op(instr, stacks))
				{
					free (instr);
					return (0);
				}
				free (instr);
			}
		}
	}
	if (res < 0)
		return (0);
	return (1);
}