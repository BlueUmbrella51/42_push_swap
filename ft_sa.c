/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sa.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:31:47 by lravier        #+#    #+#                */
/*   Updated: 2020/02/21 20:07:07 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		ft_sa(t_sort **stacks)
{
	t_list	*curr;
	void	*tmp;

	if (!stacks)
		return (0);
	if (!*stacks)
		return (0);
	curr = (*stacks)->a;
	if (!curr)
		return (1);
	if (!curr->next)
		return (1);
	tmp = curr->content;
	curr->content = curr->next->content;
	curr->next->content = tmp;
	return (1);
}
