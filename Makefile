# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asebrech <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 16:13:10 by asebrech          #+#    #+#              #
#    Updated: 2021/07/27 11:10:03 by asebrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lmlx -framework OpenGL -framework AppKit
HEADER = includes
DLIB = libft
PLIB = libft/libft.a
NAME = libso_long.a
EXEC = so_long
SRC =	srcs/so_long.c\
		srcs/parsing.c\
		srcs/utiles.c\
		srcs/print_map.c\
		srcs/move.c\
		srcs/get_next_line.c
SRCB =
RM = rm -rf

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
	make -C $(DLIB) bonus
	cp $(PLIB) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	$(CC) $(CFLAGS) -I$(HEADER) -L. -lso_long -o $(EXEC) $(LFLAGS) 
	$(RM) $(NAME)

clean :
	make -C $(DLIB) clean
	$(RM) */*.o

fclean : clean
	$(RM) $(PLIB)
	$(RM) $(EXEC)


re : fclean all

.PHONY : all clean fclean re bonus
