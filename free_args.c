/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_args.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 19:27:07 by lravier        #+#    #+#                */
/*   Updated: 2020/02/25 19:27:07 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void		free_args(char **args)
{
	int i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free (args[i]);
		i++;
	}
	free (args);
	args = NULL;
}