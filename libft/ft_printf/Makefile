# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rciera <rciera@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 20:27:55 by rciera            #+#    #+#              #
#    Updated: 2020/08/31 09:06:12 by rciera           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

LIB_DIR = ../

LIBFT_A = $(LIB_DIR)$(NAME)

HEADERS_DIR = includes/

HEADERS_LIST = ft_printf.h hidden.h

HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_DIR = src/

SRC_LIST =	ft_printf.c\
			field_width.c\
			precision.c\
			flag_managment.c\
			format_parser.c\
			length_modifiers.c\
			arg_functions.c\
			skips.c\
			print_all.c\
			print_c.c\
			print_s.c\
			print_p.c\
			print_di.c\
			print_o.c\
			print_u.c\
			print_x.c\
			print_f.c\
			ft_dtoa.c\
			nan_inf.c\
			functions_pts.c\
			errors.c\
			free_all.c

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