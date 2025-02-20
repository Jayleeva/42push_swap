NAME = push_swap
LIBFT       = libft.a
LIBFT_DIR := ./libft
LIBFT_LIB := $(LIBFT_DIR)/$(LIBFT)

SRC_DIR = ./src
SRC = push_swap.c write_output.c check_for_errors.c action_swap.c action_push.c action_rotate.c get_stack_size.c sort.c sort_five_or_less.c sort_more_than_five.c compute_cost_to_top.c compute_cost_to_push.c is_greater_smaller.c find_min_max.c find_cheapest_target.c to_top.c push_back_to_a.c free_all.c
OBJ = $(SRC:.c=.o)

SRC := $(addprefix $(SRC_DIR)/, $(SRC))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./inc -I ./libft/inc

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
    @${CC} ${CFLAGS} ${OBJ} $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
    @${MAKE} -C libft

clean:
    @${MAKE} -C libft fclean
    rm -f $(OBJ)
fclean: clean
    rm -f $(NAME)
re: fclean all

.PHONY : all clean fclean re
