# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lravier <lravier@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/26 11:25:26 by lravier        #+#    #+#                 #
#    Updated: 2020/02/26 11:45:11 by lravier       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CHK_NAME = checker
PS_NAME = push_swap
CC = gcc
IFLAGS = -Wall -Werror -Wextra
CHK_RAW = checker read_commands flags
SH_RAW = get_input init_stack validate_input check_duplicates \
doop ft_sa ft_sb ft_ss ft_ra ft_rb ft_rr ft_rra ft_rrb \
ft_rrr ft_pa ft_pb print_lst check_sorted print_solution \
free_memory add_instruction free_args
PS_RAW = push_swap sort get_distances get_distance_dst \
find_high_low calc_path find_target sort_short_halves \
src_r_dst_r src_rr_dst_rr src_r_dst_rr src_rr_dst_r \
sort_three rotate_lowest_to_top sort_short
CHK_CSRCS = $(addsuffix .c, $(CHK_RAW))
PS_CSRCS = $(addsuffix .c, $(PS_RAW))
SH_CSRCS = $(addsuffix .c, $(SH_RAW))
CHK_OBJ = $(addsuffix .o, $(CHK_RAW))
PS_OBJ = $(addsuffix .o, $(PS_RAW))
SH_OBJ = $(addsuffix .o, $(SH_RAW))
LIBF = -L libft/ -lft
HEADER = includes/push_swap.h

.PHONY: all clean fclean re

all: $(CHK_NAME) $(PS_NAME)
	@make -C libft

$(CHK_NAME): $(CHK_OBJ) $(SH_OBJ)
	$(CC) -o $(CHK_NAME) $(IFLAGS) $(CHK_OBJ) $(SH_OBJ) -I $(HEADER) $(LIBF)

$(PS_NAME): $(PS_OBJ) $(SH_OBJ)
	$(CC) -o $(PS_NAME) $(IFLAGS) $(PS_OBJ) $(SH_OBJ) -I $(HEADER) $(LIBF)

%.o:%.c $(HEADER)
	@$(CC) -o $@ -c $<

clean:
	@make clean -C libft/
	@rm -f *.o *~

fclean: clean
	@make fclean -C libft/
	@rm -f $(CHK_NAME) $(PS_NAME)

re: fclean all
