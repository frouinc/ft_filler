# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/12 18:08:53 by cfrouin           #+#    #+#              #
#    Updated: 2017/10/19 17:02:47 by cfrouin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -I./includes

NAME		=	cfrouin.filler

NAME_GRAPH	=	cfrouin.filler.graph

SRC_DIR		=	src/

FILE		=	read_info.c read_table.c read_piece.c read_piece2.c check_error.c \
			play_game.c get_goal.c check_case.c  delete.c

SRC			=	$(addprefix $(SRC_DIR), $(FILE)) src/main.c

SRC_GRAPH	=	$(addprefix $(SRC_DIR), $(FILE)) src/main_graph.c

OBJ			=	$(SRC:.c=.o)

OBJ_GRAPH	=	$(SRC_GRAPH:.c=.o)

all:			$(NAME) $(NAME_GRAPH)

$(NAME):		$(OBJ)
				@cd libft && make
				$(CC) $(OBJ) -o $(NAME) -Llibft -lft
				@cp -f $(NAME) resources/players/

$(NAME_GRAPH):	$(OBJ_GRAPH)
				@cd libft && make
				$(CC) $(OBJ_GRAPH) -o $(NAME_GRAPH) -Llibft -lft
				@cp -f $(NAME_GRAPH) resources/players/

clean:
				@cd libft && make clean
				$(RM) $(OBJ)
				$(RM) $(OBJ_GRAPH)

fclean:			clean
				$(RM) libft/libft.a
				$(RM) $(NAME)
				$(RM) $(NAME_GRAPH)
				$(RM) resources/players/$(NAME)
				$(RM) resources/players/$(NAME_GRAPH)

re:			fclean all

.PHONY:		all clean fclean re
