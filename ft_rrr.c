/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rrr.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 16:25:26 by lravier        #+#    #+#                */
/*   Updated: 2020/02/14 16:25:26 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int		ft_rrr(t_sort **stacks)
{
	if (!ft_rra(stacks) || !ft_rrb(stacks))
		return (0);
	return (1);
}
