# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 01:01:07 by lmazzi            #+#    #+#              #
#    Updated: 2017/05/25 02:16:28 by lmazzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lmazzi.filler

FILE_LIST	=	filler.c ft_algo.c ft_cord.c ft_score.c vivaldi.c
OBJ_FILES	=	$(FILE_LIST:.c=.o)

LIB_FT		=	./libft
LIB_FT_INC	=	-I $(LIB_FT)

LIB_FT_LINK	=	$(LIB_FT)/libft.a

INCLUDES	=	$(LIB_FT_INC)
LINK		=	$(LIB_FT_LINK)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

libs:
	@make -C $(LIB_FT)

$(NAME): libs $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LINK) $(OBJ_FILES) -o $(NAME)

$(OBJ_FILES):
	$(CC) $(CFLAGS) $(INCLUDES) -c $(FILE_LIST)

clean:
	@make -C $(LIB_FT) clean
	rm -f $(OBJ_FILES)

fclean: clean 
	@make -C $(LIB_FT) fclean
	rm -f $(NAME)

relibs:
	@make -C $(LIB_FT) re
	@make re --no-print-directory

re: fclean all

.PHONY: all clean fclean re
