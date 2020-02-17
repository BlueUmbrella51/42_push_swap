/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_lst.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 14:43:24 by lravier        #+#    #+#                */
/*   Updated: 2020/02/14 14:43:24 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void        print_lst(t_list **lst)
{
    t_list *tmp;

    tmp = *lst;
    while (tmp)
    {
        printf("data: %d\n", (*(int *)(tmp->content)));
        tmp = tmp->next;
    }
}

void        print_lst_dist(t_list **lst)
{
    t_list *tmp;

    tmp = *lst;
    while (tmp)
    {
        printf("value: %d\nsrc_r: %d\nsrc_rr %d\ndst_r %d\ndst_rr %d\n",((t_path *)tmp->content)->data, ((t_path *)tmp->content)->src_r, ((t_path *)tmp->content)->src_rr, ((t_path *)tmp->content)->dst_r, ((t_path *)tmp->content)->dst_rr);
        printf("type: %d\npath: %d\n\n", ((t_path *)tmp->content)->type, ((t_path *)tmp->content)->moves);
        tmp = tmp->next;
    }
}