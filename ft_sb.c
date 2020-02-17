/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sb.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 15:53:00 by lravier        #+#    #+#                */
/*   Updated: 2020/02/14 15:53:00 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		ft_sb(t_sort **stacks)
{
	t_list	*curr;
	void	*tmp;

	if (!stacks)
		return (0);
	if (!*stacks)
		return (0);
	curr = (*stacks)->b;
	if (!curr)
		return (0);
	if (!curr->next)
		return (0);
	tmp = curr->content;
	curr->content = curr->next->content;
	curr->next->content = tmp;
	return (1);
}