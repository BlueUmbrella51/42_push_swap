/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_duplicates.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 14:50:58 by lravier        #+#    #+#                */
/*   Updated: 2020/02/14 14:50:58 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		check_duplicates(t_list **lst, int len)
{
	t_list	*curr;
	t_list	*next;
	int		i;
	int		j;

	curr = *lst;
	i = 0;
	j = 1;
	while (curr->next)
	{
		next = curr->next;
		while (next)
		{
			if ((*(int *)(curr->content)) == (*(int *)(next->content)))
				return (0);
			next = next->next;
		}
		curr = curr->next;
	}
	return (1);
}