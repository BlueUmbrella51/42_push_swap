/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_memory.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:26:31 by lravier        #+#    #+#                */
/*   Updated: 2020/02/25 20:53:48 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void			free_solution(t_list **solution)
{
	t_list			*curr;
	t_list			*next;
	t_instruction	*val;

	next = *solution;
	while (next)
	{
		curr = next;
		val = (t_instruction *)curr->content;
		if (val->instr)
			free(val->instr);
		free(curr->content);
		next = curr->next;
		free(curr);
	}
	*solution = NULL;
}

void				free_memory(t_sort **stacks, t_list **solution)
{
	ft_lstdel(&(*stacks)->a, &ft_del);
	ft_lstdel(&(*stacks)->b, &ft_del);
	free_solution(solution);
	free(*stacks);
	*stacks = NULL;
}
