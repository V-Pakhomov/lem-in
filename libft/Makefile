# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rciera <rciera@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 20:27:55 by rciera            #+#    #+#              #
#    Updated: 2020/09/01 09:02:54 by rciera           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FT_PRINTF = ft_printf/

FT_QUEUE = ft_queue/

ARR_INT = array_int/

HEADERS_DIR = includes/

HEADERS_LIST = libft.h

HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_DIR = src/

SRC_LIST =	ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_strlen.c\
			ft_strdup.c\
			ft_strcpy.c\
			ft_strncpy.c\
			ft_strcat.c\
			ft_strncat.c\
			ft_strlcat.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strstr.c\
			ft_strnstr.c\
			ft_strcmp.c\
			ft_strncmp.c\
			ft_atoi.c\
			ft_atoll.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isnum.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_memalloc.c\
			ft_memdel.c\
			ft_strnew.c\
			ft_strdel.c\
			ft_strclr.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strequ.c\
			ft_strnequ.c\
			ft_strsub.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_strsplit.c\
			ft_itoa.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putendl.c\
			ft_putnbr.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_strrev.c\
			ft_lstnew.c\
			ft_lstdelone.c\
			ft_lstdel.c\
			ft_lstadd.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_lst_push_back.c\
			ft_swap.c\
			ft_lstrev.c\
			ft_lstsize.c\
			ft_sqrt.c\
			get_next_line.c\
			ft_abs.c\
			ft_min.c\
			ft_max.c\
			ft_pow.c\
			ft_arrsize.c\
			ft_itoa_base.c\
			ft_ulltoa.c\
			ft_isinteger.c\
			ft_arrays.c

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = obj/

OBJ_LIST = $(subst .c,.o,$(SRC_LIST))

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rc $(NAME) $(OBJ)	
	ranlib $(NAME)
	make -C $(FT_PRINTF)
	make -C $(FT_QUEUE)
	make -C $(ARR_INT)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -Rf $(OBJ_DIR)
	make -C $(FT_PRINTF) clean
	make -C $(FT_QUEUE) clean
	make -C $(ARR_INT) clean

fclean: clean
	rm -f $(NAME)

re: fclean all