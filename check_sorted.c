/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sorted.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/15 12:31:25 by lravier        #+#    #+#                */
/*   Updated: 2020/02/15 12:31:25 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		check_sorted(t_sort **stacks)
{
	t_list	*curr;
	t_list	*prev;

	prev = (*stacks)->a;
	curr = prev->next;
	while (curr)
	{
		if ((*(int *)prev->content) > (*(int *)curr->content))
			return (0);
		prev = curr;
		curr = curr->next;
	}
	return (1);
}

int		check_rev_sorted(t_sort **stacks)
{
	t_list	*curr;
	t_list	*prev;

	prev = (*stacks)->a;
	curr = prev->next;
	while (curr)
	{
		if ((*(int *)prev->content) < (*(int *)curr->content))
			return (0);
		prev = curr;
		curr = curr->next;
	}
	return (1);	
}