/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_instruction.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 15:20:38 by lravier        #+#    #+#                */
/*   Updated: 2020/02/16 15:20:38 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		add_instruction(char *s, t_sort **stacks, t_list **solution)
{
	t_instruction tmp;

	tmp.instr = ft_strdup(s);
	if (ft_strcmp(s, RRA) == 0 || ft_strcmp(s, RRB) == 0 ||
	ft_strcmp(s, RRR) == 0)
		tmp.len = 3;
	else
		tmp.len = 2;
	if (!ft_lstaddend(solution, &tmp, sizeof(t_instruction)))
		return (0);
	if (!do_op(s, stacks))
		return (0);
	return (1);
}
