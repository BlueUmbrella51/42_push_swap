/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 10:10:58 by lravier       #+#    #+#                 */
/*   Updated: 2019/04/18 09:52:38 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 16
# include "libft.h"

typedef struct		s_fd
{
	void	*rest;
	size_t	len;
	int		fd;
}					t_fd;

typedef	struct		s_params
{
	t_list	**buff;
	char	**line;
	t_list	**data;
	t_list	*curr;
	size_t	*len;
	int		fd;
	int		nbr;
}					t_params;

int					get_next_line(const int fd, char **line);

#endif
