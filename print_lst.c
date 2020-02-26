/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_lst.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:39:38 by lravier        #+#    #+#                */
/*   Updated: 2020/02/26 11:30:50 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void		print_lst(t_list **lst)
{
	t_list	*tmp;
	char	*s;

	s = NULL;
	tmp = *lst;
	while (tmp)
	{
		s = ft_itoa(*(int *)tmp->content);
		ft_putstr(s);
		free(s);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
