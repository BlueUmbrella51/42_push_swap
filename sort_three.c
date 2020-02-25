/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:45:01 by lravier        #+#    #+#                */
/*   Updated: 2020/02/25 16:44:25 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void		set_data(int *a, int *b, int *c, t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	*a = ((t_path *)(tmp->content))->data;
	tmp = tmp->next;
	*b = ((t_path *)(tmp->content))->data;
	tmp = tmp->next;
	*c = ((t_path *)(tmp->content))->data;
}

int				sort_three(t_sort **stacks, t_list **solution)
{
	int	a;
	int	b;
	int	c;

	set_data(&a, &b, &c, &(*stacks)->a);
	if (a <= b && b <= c)
		return (1);
	if (a <= b && b >= c && c >= a)
	{
		return (add_instruction(SA, stacks, solution)
		&& add_instruction(RA, stacks, solution));
	}
	if (a >= b && b <= c && c >= a)
		return (add_instruction(SA, stacks, solution));
	if (a <= b && b >= c && a >= c)
		return (add_instruction(RRA, stacks, solution));
	if (a >= b && b <= c && a >= c)
		return (add_instruction(RA, stacks, solution));
	if (a >= b && b >= c)
	{
		return (add_instruction(SA, stacks, solution) &&
		add_instruction(RRA, stacks, solution));
	}
	return (0);
}

int				rev_sort_three(t_sort **stacks, t_list **solution)
{
	int	a;
	int	b;
	int	c;

	set_data(&a, &b, &c, &(*stacks)->b);
	if (a >= b && b >= c)
		return (1);
	if (a <= b && b <= c)
	{
		return (add_instruction(SB, stacks, solution)
		&& add_instruction(RRB, stacks, solution));
	}
	if (a <= b && b >= c && a <= c)
		return (add_instruction(RB, stacks, solution));
	if (a >= b && b <= c && a <= c)
		return (add_instruction(RRB, stacks, solution));
	if (a <= b && b >= c && a >= c)
		return (add_instruction(SB, stacks, solution));
	if (a >= b && b <= c && a >= c)
	{
		return (add_instruction(SB, stacks, solution)
		&& add_instruction(RB, stacks, solution));
	}
	return (0);
}
