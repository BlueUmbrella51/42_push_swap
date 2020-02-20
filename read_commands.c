/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:42:03 by lravier        #+#    #+#                */
/*   Updated: 2020/02/20 13:42:19 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int			read_commands(t_sort **stacks, t_list **solution)
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
				if (!add_instruction(instr, stacks, solution))
				{
					free(instr);
					return (0);
				}
				free(instr);
				instr = NULL;
			}
		}
	}
	if (res < 0)
		return (0);
	return (1);
}
