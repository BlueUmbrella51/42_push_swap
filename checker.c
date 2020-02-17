/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 12:49:44 by lravier        #+#    #+#                */
/*   Updated: 2020/02/14 12:49:44 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void     free_memory(t_sort **stacks)
{
    ft_lstdel(&(*stacks)->a, &ft_del);
    ft_lstdel(&(*stacks)->b, &ft_del);
    free (*stacks);
}

int     main(int argc, char *argv[])
{
    t_sort  *stacks;

    stacks = NULL;
    if (argc < 2)
        return (0);
    if (!initialize_stacks(&stacks))
        return (ft_error("Error\n", 0));
    if (!get_input(&stacks, argc, argv))
        return (ft_error("Error\n", 0));
    if (!read_commands(&stacks))
    {
        free_memory(&stacks);
        return (ft_error("Error\n", 0));
    }
    if (!check_sorted(&stacks) || stacks->len_b != 0)
        ft_putstr("KO\n");
    else
        ft_putstr("OK\n");
    free_memory(&stacks);
    return (1);
}