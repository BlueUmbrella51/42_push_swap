/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pb.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 16:36:07 by lravier        #+#    #+#                */
/*   Updated: 2020/02/14 16:36:07 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		ft_pb(t_sort **stacks)
{
	t_list	*tmp;

	if (stacks == NULL)
		return (0);
	if (*stacks == NULL)
		return (0);
	if (!(*stacks)->a)
		return (0);
	tmp = ft_lstpop(&(*stacks)->a);
	ft_lstadd(&(*stacks)->b, tmp);
	(*stacks)->len_b += 1;
	(*stacks)->len_a -= 1;
	return (1);
}