# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rciera <rciera@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/01 08:43:18 by rciera            #+#    #+#              #
#    Updated: 2020/09/14 18:00:58 by rciera           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LOG_GREEN = \033[32m
LOG_NOCOLOR = \033[0m

ARCHIVE = libftlemin.a

NAME = lem-in

LIB = ./libft/

LIB_A = libft/libft.a

INCLUDES = -I ./includes/ -I libft/includes/


SOURCES = input_validator.c \
		init.c \
		temp_helpful.c \
		checkers.c \
		bin_search.c \
		qsort.c \
		bfs.c \
		edmonds_karp.c \
		t_paths_functions.c \
		error.c \
		print_output.c \
		t_neighbors.c \
		file_to_debug.c

SRCDIR = srcs
OBJDIR = obj

SRC = $(addprefix $(SRCDIR)/, $(SOURCES))

OBJ = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

CCFL = -Wall -Wextra -Werror -g



all: obj_dir library $(ARCHIVE) $(NAME)

obj_dir:
	@mkdir -p $(OBJDIR)

library:
	@make -C $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	gcc $(CCFL) -o $@ -c $< $(INCLUDES)

$(ARCHIVE): $(OBJ)
	@ar rc $(ARCHIVE) $(OBJ)
	@ranlib $(ARCHIVE)

$(NAME): $(OBJ)
	gcc $(CCFL) -o $(NAME) $(ARCHIVE) $(LIB_A)
	@echo "$(LOG_GREEN)Lem_in has compiled successfully!$(LOG_NOCOLOR)"

clean:
	@make clean -sC $(LIB)
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(ARCHIVE)
	/bin/rm -f $(NAME)
	@make fclean -C $(LIB)

re: fclean all

.PHONY: all clean fclean re
