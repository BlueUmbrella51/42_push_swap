/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_init_stack.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 13:01:40 by lravier        #+#    #+#                */
/*   Updated: 2020/02/14 13:01:40 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int     initialize_stacks(t_sort **stacks)
{
    *stacks = (t_sort *)malloc(sizeof(t_sort));
    if (!*stacks)
        return (0);
    (*stacks)->a = NULL;
    (*stacks)->b = NULL;
    (*stacks)->len_a = 0;
    (*stacks)->len_b = 0;
    (*stacks)->high_a = 0;
    (*stacks)->high_b = 0;
    (*stacks)->low_a = 0;
    (*stacks)->low_b = 0;
    return (1);
}