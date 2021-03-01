NAME = philo_three

FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

CC = gcc $(FLAGS)

FILES = srcs/main.c srcs/utils.c srcs/actions.c \
		srcs/initer.c srcs/debug.c

INC = includes/

all: $(NAME)

$(NAME): $(INC)
	$(CC) $(FILES) -o $(NAME) -I$(INC)

fclean:
	rm -f $(NAME)

re : fclean all

m : $(NAME)
	./$(NAME) 3 5000 6000 7000

m2 : $(NAME)
	./$(NAME) 3 5000 6000 7000 6

.PHONY: all fclean re $(NAME)

