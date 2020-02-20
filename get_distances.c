/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:36:38 by lravier        #+#    #+#                */
/*   Updated: 2020/02/20 13:37:04 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static t_path	initialize_data(t_sort **stacks, int ind, char src, int n)
{
	t_path	tmp;

	tmp.src_r = ind;
	tmp.data = n;
	if (src == 'a')
		tmp.src_rr = (*stacks)->len_a - ind;
	else
		tmp.src_rr = (*stacks)->len_b - ind;
	tmp.dst_r = 0;
	tmp.dst_rr = 0;
	tmp.type = 0;
	tmp.moves = 0;
	return (tmp);
}

static int		get_distances_a(t_list **distances, t_sort **stacks, char src)
{
	int		ind;
	t_list	*curr;
	t_path	tmp;

	ind = 0;
	curr = (*stacks)->a;
	while (curr)
	{
		tmp = initialize_data(stacks, ind, src, (*(int *)(curr->content)));
		if (!ft_lstaddend(distances, &tmp, sizeof(t_path)))
			return (0);
		ind++;
		curr = curr->next;
	}
	return (1);
}

static int		get_distances_b(t_list **distances, t_sort **stacks, char src)
{
	int		ind;
	t_list	*curr;
	t_path	tmp;

	ind = 0;
	curr = (*stacks)->b;
	while (curr)
	{
		tmp = initialize_data(stacks, ind, src, (*(int *)(curr->content)));
		if (!ft_lstaddend(distances, &tmp, sizeof(t_path)))
			return (0);
		ind++;
		curr = curr->next;
	}
	return (1);
}

int				get_distances(t_list **distances, t_sort **stacks, char src)
{
	int		ind;
	t_path	*tmp;

	ind = 0;
	if (*distances != NULL)
		ft_lstedel(distances);
	if (src == 'a')
	{
		if (!(get_distances_a(distances, stacks, src)))
			return (0);
	}
	else
	{
		if (!(get_distances_b(distances, stacks, src)))
			return (0);
	}
	if (!(get_distances_dest(distances, stacks, src)))
		return (0);
	return (1);
}
