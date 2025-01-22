NAME = push_swap

SRC = push_swap.h push_swap.c check_errors.c actions.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I. -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) push_swap.h
	ar rcs $(NAME) $(OBJ) 

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY : all clean fclean re