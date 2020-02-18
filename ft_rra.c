/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rra.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 16:16:11 by lravier        #+#    #+#                */
/*   Updated: 2020/02/14 16:16:11 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		ft_rra(t_sort **stacks)
{
	t_list	*head;
	t_list	*tail;

	if (stacks == NULL)
		return (0);
	if (!*stacks)
		return (0);
	tail = (*stacks)->a;
	if (!tail)
		return (0);
	if (!tail->next)
		return (0);
	while (tail->next->next != NULL)
		tail = tail->next;
	head = tail->next;
	tail->next = NULL;
	head->next = (*stacks)->a;
	(*stacks)->a = head;
	return (1);
}
