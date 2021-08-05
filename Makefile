# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asebrech <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 16:13:10 by asebrech          #+#    #+#              #
#    Updated: 2021/08/05 16:40:24 by asebrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lmlx -framework OpenGL -framework AppKit
HEADER = includes
NAME = so_long
RM = rm -rf
SRC =	srcs/so_long.c\
		srcs/parsing.c\
		srcs/utiles.c\
		srcs/print_map.c\
		srcs/print_map1.c\
		srcs/move.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c
SRCB =	bonus/so_long_bonus.c\
		bonus/parsing_bonus.c\
		bonus/utiles_bonus.c\
		bonus/print_map_bonus.c\
		bonus/print_map1_bonus.c\
		bonus/move_S_bonus.c\
		bonus/move_S1_bonus.c\
		bonus/move_bonus.c\
		bonus/animation_bonus.c\
		bonus/animation1_bonus.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c

ifdef WHITH_BONUS
	OBJ = $(SRCB:.c=.o)
else
	OBJ = $(SRC:.c=.o)
endif

.c.o :
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

all : $(NAME)

bonus :
	@make WHITH_BONUS=1 all

$(NAME) : $(OBJ)
	@make -C libft bonus
	$(CC) $(CFLAGS) $(LFLAGS) -I$(HEADER) -Llibft -lft $(OBJ) -o $(NAME)

clean :
	@make -C libft clean
	$(RM) */*.o

fclean : clean
	$(RM) libft/libft.a
	$(RM) $(NAME)


re : fclean all

.PHONY : all clean fclean re bonus
