/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <lravier@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:58:15 by lravier        #+#    #+#                */
/*   Updated: 2020/02/21 20:28:56 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct	s_instruction
{
	char* instr;
	int len;
}				t_instruction;

typedef struct	s_sort
{
	t_list		*a;
	int			len_a;
	int			high_a;
	int			low_a;
	t_list		*b;
	int			len_b;
	int			high_b;
	int			low_b;
}				t_sort;

typedef struct	s_path
{
	int	data;
	int	src_r;
	int	src_rr;
	int	dst_r;
	int dst_rr;
	int	moves;
	int	type;
}				t_path;

int				initialize_stacks(t_sort **stacks);
int				get_input(t_sort **stacks, int argc, char *argv[], int i);
int				validate_input(char *arg);
int				check_duplicates(t_list **lst, int len);
int				read_commands(t_sort **stacks, t_list **solution);
int				doop(char *instr, t_sort **stacks);
void			find_high_low(t_sort **stacks, char st);
int				do_op(char *instr, t_sort **stacks);
int				sort(t_sort **stacks, t_list **solution);
int				get_distances(t_list **distances, t_sort **stacks,
char src);
int				get_distances_dest(t_list **distances, t_sort **stacks,
char src);
int				add_instruction(char *s, t_sort **stacks,
t_list **solution);
void			calculate_path(t_list **elem);
int				find_target(t_sort **stacks, t_list **distances,
char st, t_list **solution);
int				src_r_dst_r(t_sort **stacks, t_path *target,
char src, t_list **solution);
int				src_r_dst_rr(t_sort **stacks, t_path *target, char src,
t_list **solution);
int				src_rr_dst_r(t_sort **stacks, t_path *target, char src,
t_list **solution);
int				src_rr_dst_rr(t_sort **stacks, t_path *target, char src,
t_list **solution);
int				sort_short(t_sort **stacks, t_list **solution);
int				sort_short_halves(t_sort **stacks, t_list **solution);
int				sort_three(t_sort **stacks, t_list **solution);
int				rev_sort_three(t_sort **stacks, t_list **solution);
int				distance_low(t_sort **stacks, int low, char st);
int				rotate_lowest_to_top(t_sort **stacks, t_list **solution);
void			print_solution(t_list **solution);
int				ft_sa(t_sort **stacks);
int				ft_sb(t_sort **stacks);
int				ft_ss(t_sort **stacks);
int				ft_ra(t_sort **stacks);
int				ft_rb(t_sort **stacks);
int				ft_rr(t_sort **stacks);
int				ft_rra(t_sort **stacks);
int				ft_rrb(t_sort **stacks);
int				ft_rrr(t_sort **stacks);
int				ft_pa(t_sort **stacks);
int				ft_pb(t_sort **stacks);
int				check_sorted(t_sort **stacks);
void			free_memory(t_sort **stacks, t_list **solution);
void			check_flags(int *flags, char *argv[]);
int				skip_flags(char *argv[]);
void			do_flags(int *flags, t_list **solution,
t_sort **stacks);
void			print_lst(t_list **lst);
#endif
