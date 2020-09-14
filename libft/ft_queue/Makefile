# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rciera <rciera@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 20:27:55 by rciera            #+#    #+#              #
#    Updated: 2020/09/14 17:53:33 by rciera           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LOG_GREEN = \033[32m
LOG_NOCOLOR = \033[0m

NAME = ft_queue.a

CC = gcc

HEADERS_DIR = includes/

HEADERS_LIST = ft_queue.h

HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

INCLUDES = -I $(HEADERS_DIR)

SRC_DIR = srcs/

SRC_LIST =	push_queue.c\
			pop_queue.c\
			front_queue.c\
			back_queue.c\
			empty_queue.c\
			size_queue.c\

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = obj/

OBJ_LIST = $(subst .c,.o,$(SRC_LIST))

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rc $(NAME) $(OBJ)	
	ranlib $(NAME)
	@echo "$(LOG_GREEN)Ft_queue has compiled successfully!$(LOG_NOCOLOR)"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	$(CC) $(FLAGS) $< $(INCLUDES) -o $@

clean:
	rm -Rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all