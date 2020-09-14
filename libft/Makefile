# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rciera <rciera@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 20:27:55 by rciera            #+#    #+#              #
#    Updated: 2020/09/14 18:02:10 by rciera           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LOG_GREEN = \033[32m
LOG_NOCOLOR = \033[0m

NAME = libft.a

CC = gcc

FT_PRINTF_DIR = ./ft_printf/
FT_PRINTF = $(FT_PRINTF_DIR)ft_printf.a

FT_QUEUE_DIR = ./ft_queue/
FT_QUEUE = $(FT_QUEUE_DIR)ft_queue.a

ARR_INT_DIR = ./array_int/
ARR_INT = $(ARR_INT_DIR)array_int.a

HEADERS_DIR = includes/

HEADERS_LIST = libft.h

HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

INCLUDES = -I $(HEADERS_DIR)

SRC_DIR = srcs/

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

all: $(OBJ_DIR) $(FT_QUEUE) $(ARR_INT) $(FT_PRINTF) $(NAME)

$(ARR_INT):
	@make -C $(ARR_INT_DIR)
	@cd $(OBJ_DIR)$(ARR_INT_DIR); ar -x ../../$(ARR_INT)

$(FT_QUEUE):
	@make -C $(FT_QUEUE_DIR)
	@cd $(OBJ_DIR)$(FT_QUEUE_DIR); ar -x ../../$(FT_QUEUE)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)
	@cd $(OBJ_DIR)$(FT_PRINTF_DIR); ar -x ../../$(FT_PRINTF)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) $(OBJ_DIR)$(ARR_INT_DIR)*.o $(OBJ_DIR)$(FT_PRINTF_DIR)*.o $(OBJ_DIR)$(FT_QUEUE_DIR)*.o
	ranlib $(NAME)
	@echo "$(LOG_GREEN)Libft has compiled successfully!$(LOG_NOCOLOR)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(FT_PRINTF_DIR)
	@mkdir -p $(OBJ_DIR)$(FT_QUEUE_DIR)
	@mkdir -p $(OBJ_DIR)$(ARR_INT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	$(CC) $(FLAGS) $< $(INCLUDES) -o $@

clean:
	@rm -Rf $(OBJ_DIR)
	@make clean -sC $(ARR_INT_DIR)
	@make clean -sC $(FT_QUEUE_DIR)
	@make clean -sC $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(ARR_INT)
	rm -f $(FT_PRINTF)
	rm -f $(FT_QUEUE)

re: fclean all

.PHONY: all clean fclean re