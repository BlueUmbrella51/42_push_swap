/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:28:59 by lravier        #+#    #+#                */
/*   Updated: 2020/02/20 13:29:09 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		ft_rb(t_sort **stacks)
{
	t_list	*head;
	t_list	*tail;
	t_list	*tmp;

	if (stacks == NULL)
		return (0);
	if (!*stacks)
		return (0);
	tail = (*stacks)->b;
	if (!tail)
		return (0);
	if (!tail->next)
		return (0);
	head = tail->next;
	tmp = head;
	tail->next = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = tail;
	(*stacks)->b = head;
	return (1);
}
