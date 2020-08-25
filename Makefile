NAME = lemin
FLAG = -Wall -Wextra -Werror -g


LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

HEADER_DIR = ./includes/
HEADER = -I $(HEADER_DIR) -I ./libft/libft.h

SRC_DIR = ./srcs/
SRC_LIST = input_validator.c \
init.c \
temp_helpful.c \
bin_search \
qsort

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = ./obj/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make re -C $(LIBFT_DIR)
	@gcc -o $(NAME) $(HEADER) $(OBJ) $(LIBFT)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER_DIR)*.h
	@mkdir -p $(OBJ_DIR)
	@gcc -c $(HEADER) $< -o $@ $(FLAG)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
