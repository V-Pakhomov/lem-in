# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rciera <rciera@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 20:27:55 by rciera            #+#    #+#              #
#    Updated: 2020/09/01 08:55:24 by rciera           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

LIB_DIR = ../

LIBFT_A = $(LIB_DIR)$(NAME)

HEADERS_DIR = includes/

HEADERS_LIST = array_int.h

HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_DIR = src/

SRC_LIST = 	arr_add.c\
			arr_cat.c\
			arr_del.c\
			arr_get.c\
			arr_len.c\
			arr_new.c\
			arr_print.c\
			arr_set.c\
			check_arr_input.c

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = obj/

OBJ_LIST = $(subst .c,.o,$(SRC_LIST))

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	mv $(LIBFT_A) .
	ar rc $(NAME) $(OBJ)	
	ranlib $(NAME)
	mv $(NAME) $(LIB_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -Rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all