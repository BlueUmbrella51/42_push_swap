# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lravier <lravier@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/20 09:31:34 by lravier        #+#    #+#                 #
#    Updated: 2020/02/17 17:29:21 by lravier       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
IFLAGS = -Wall -Werror -Wextra
RAWFILES = ft_putchar ft_putstr ft_error ft_memset ft_bzero ft_strlen \
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
CSRCS := $(addsuffix .c, $(RAWFILES))
OSRCS := $(addsuffix .o, $(RAWFILES))
HEADER_LIBFT = libft.h
HEADER_GNL = get_next_line.h

all: $(NAME)

$(NAME): $(OSRCS)
	@ar rcs $(NAME) $(OSRCS)

%.o: %.c $(HEADER_LIBFT)
	@$(CC) -c $< -o $@

get_next_line.o: get_next_line.c $(HEADER_GNL)
	@$(CC) $(IFLAGS) -c $< -o $@

clean:
	@rm -f *.o *~
	@rm -f libft.h.gch get_next_line.h.gch

fclean: clean
	@rm -f $(NAME)

re: fclean all