/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:40:50 by lravier        #+#    #+#                */
/*   Updated: 2020/02/20 13:40:58 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void		print_solution(t_list **solution)
{
	t_list			*tmp;
	t_instruction	*val;

	tmp = *solution;
	while (tmp)
	{
		val = (t_instruction *)tmp->content;
		write(1, val->instr, val->len);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
