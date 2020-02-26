# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lravier <lravier@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/26 11:25:26 by lravier        #+#    #+#                 #
#    Updated: 2020/02/26 12:04:31 by lravier       ########   odam.nl          #
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
LIB_RAW = ft_putchar ft_putstr ft_error ft_memset ft_bzero ft_strlen \
ft_isupper ft_islower ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
ft_toupper ft_tolower ft_isspace ft_atoi ft_strcpy ft_strncpy ft_strcmp \
ft_strncmp ft_strcat ft_strstr ft_memcpy ft_strchr ft_strrchr ft_strnstr \
ft_memalloc ft_strnew ft_strclr ft_striter ft_striteri ft_memdel ft_strdel \
ft_strdup ft_strlcat ft_strnlen ft_memccpy ft_memmove ft_memchr ft_memcmp \
ft_strncat ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strjoin ft_strsub \
ft_strtrim ft_strsplit ft_itoa ft_putendl ft_putnbr ft_putchar_fd \
ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstdelone ft_lstdel \
ft_lstaddend ft_lstadd ft_lstiter ft_lstmap ft_mempcpy ft_itoabase \
ft_swap ft_sqrt ft_rot ft_rotr ft_atoibase ft_pow ft_strtolower ft_lstpop \
ft_lstpopend ft_lstlen ft_strtoupper ft_memrealloc ft_lstremove ft_lstsearch \
ft_strplen ft_strtrunc ft_strndup ft_memdup ft_memplen ftd_memalloc \
ft_memtrunc ft_lsteremove ft_lsttoarr ft_lstedel get_next_line ft_del
LIB_SRC = $(addprefix libft/,$(addsuffix .c,$(LIB_RAW)))
LIB_OBJ = $(addprefix libft/,$(addsuffix .o,$(LIB_RAW)))
CHK_CSRCS = $(addsuffix .c, $(CHK_RAW))
PS_CSRCS = $(addsuffix .c, $(PS_RAW))
SH_CSRCS = $(addsuffix .c, $(SH_RAW))
CHK_OBJ = $(addsuffix .o, $(CHK_RAW))
PS_OBJ = $(addsuffix .o, $(PS_RAW))
SH_OBJ = $(addsuffix .o, $(SH_RAW))
HEADER_LIBFT = libft.h
HEADER_GNL = get_next_line.h
LIBF = -L libft/ -lft
LIB = libft/libft.a
HEADER = includes/push_swap.h

.PHONY: all clean fclean re

all: $(CHK_NAME) $(PS_NAME)

$(LIB): $(LIB_OBJ)
	make -C libft/

$(CHK_NAME): $(CHK_OBJ) $(SH_OBJ) $(LIB)
	$(CC) -o $(CHK_NAME) $(IFLAGS) $(CHK_OBJ) $(SH_OBJ) -I $(HEADER) $(LIBF)

$(PS_NAME): $(PS_OBJ) $(SH_OBJ) $(LIB)
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
