/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rrb.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:30:38 by lravier        #+#    #+#                */
/*   Updated: 2020/02/21 20:06:56 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		ft_rrb(t_sort **stacks)
{
	t_list	*head;
	t_list	*tail;

	if (stacks == NULL)
		return (0);
	if (!*stacks)
		return (0);
	tail = (*stacks)->b;
	if (!tail)
		return (1);
	if (!tail->next)
		return (1);
	while (tail->next->next != NULL)
		tail = tail->next;
	head = tail->next;
	tail->next = NULL;
	head->next = (*stacks)->b;
	(*stacks)->b = head;
	return (1);
}
