/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   1.c                                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 12:31:27 by lravier        #+#    #+#                */
/*   Updated: 2020/02/20 12:31:52 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_del(void *content, size_t size)
{
	if (content && size)
		free(content);
}
