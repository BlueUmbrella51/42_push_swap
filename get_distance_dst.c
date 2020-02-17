/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_distance_dst.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/15 14:13:05 by lravier        #+#    #+#                */
/*   Updated: 2020/02/15 14:13:05 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/* Length of destination is always two or bigger */

static int	distance_high(t_sort **stacks, int high, char st)
{
	int		dst;
	t_list	*tmp;

	if (st == 'a')
	{
		dst = 0;
		tmp = (*stacks)->b;
	}
	else
	{
		dst = 1;
		tmp = (*stacks)->a;
	}
	while (tmp && (*(int *)(tmp->content)) != high)
	{
		tmp = tmp->next;
		dst++;
	}
	return (dst);
}

int			distance_low(t_sort **stacks, int low, char st)
{
	int		dst;
	t_list	*tmp;

	if (st == 'a')
	{
		dst = 1;
		tmp = (*stacks)->b;
	}
	else
	{
		dst = 0;
		tmp = (*stacks)->a;
	}
	while (tmp && (*(int *)(tmp->content)) != low)
	{
		tmp = tmp->next;
		dst++;
	}
	return (dst);
}

static int	get_dist_dst_a(t_sort **stacks, t_list **distances, char st)
{
	t_list	*tmp;
	t_list	*tmp_dest;
	int		dist;
	int		n;

	tmp = *distances;
	tmp_dest = (*stacks)->a;
	n = ((t_path *)(tmp->content))->data;
	if (n > (*stacks)->high_a)
		return (distance_high(stacks, (*stacks)->high_a, st));
	if (n < (*stacks)->low_a)
		return (distance_low(stacks, (*stacks)->low_a, st));
	else
	{
		dist = 1;
		while (tmp_dest->next)
		{
			if ((*(int *)(tmp_dest->content)) < n &&
			(*(int *)(tmp_dest->next->content)) > n)
				return (dist);
			dist++;
			tmp_dest = tmp_dest->next;
		}
	}
	return (0);
}

static int	get_dist_dst_b(t_sort **stacks, t_list **distances, char st)
{
	t_list	*tmp;
	t_list	*tmp_dest;
	int		dist;
	int		n;

	tmp = *distances;
	tmp_dest = (*stacks)->b;
	n = ((t_path *)(tmp->content))->data;
	if (n > (*stacks)->high_b)
		return (distance_high(stacks, (*stacks)->high_b, st));
	if (n < (*stacks)->low_b)
		return (distance_low(stacks, (*stacks)->low_b, st));
	else
	{
		dist = 1;
		while (tmp_dest->next)
		{
			if ((*(int *)(tmp_dest->content)) > n &&
			(*(int *)(tmp_dest->next->content)) < n)
				return (dist);
			dist++;
			tmp_dest = tmp_dest->next;
		}
	}
	return (0);
}

int			get_distances_dest(t_list **distances, t_sort **stacks, char src)
{
	t_list *tmp;

	tmp = *distances;
	while (tmp)
	{
		if (src == 'a')
			((t_path *)(tmp->content))->dst_r = get_dist_dst_b(stacks, &tmp, src);
		else
			((t_path *)(tmp->content))->dst_r = get_dist_dst_a(stacks, distances, src);
		if (src == 'a')
			((t_path *)(tmp->content))->dst_rr = (*stacks)->len_b - ((t_path *)(tmp->content))->dst_r;
		else
			((t_path *)(tmp->content))->dst_rr = (*stacks)->len_a - ((t_path *)(tmp->content))->dst_r;
		calculate_path(&tmp);
		tmp = tmp->next;
	}
	return (1);
}