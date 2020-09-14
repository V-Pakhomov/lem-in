# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rciera <rciera@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 20:27:55 by rciera            #+#    #+#              #
#    Updated: 2020/09/14 17:53:45 by rciera           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LOG_GREEN = \033[32m
LOG_NOCOLOR = \033[0m

NAME = ft_printf.a

CC = gcc

HEADERS_DIR = includes/

HEADERS_LIST = ft_printf.h hidden.h

HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

INCLUDES = -I $(HEADERS_DIR)

SRC_DIR = srcs/

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
	ar rc $(NAME) $(OBJ)	
	ranlib $(NAME)
	@echo "$(LOG_GREEN)Ft_printf has compiled successfully!$(LOG_NOCOLOR)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	$(CC) $(FLAGS) $< $(INCLUDES) -o $@

clean:
	rm -Rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all