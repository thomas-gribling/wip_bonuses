NAME = push_swap
BONUS = checker

SRCS = srcs/
INCLUDE = include/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES = main.c push_swap.c ft_split.c utils.c tab_utils.c \
		stack.c ps_functions.c small_sort.c sort.c path_finder.c
OBJECTS = $(addprefix $(SRCS), $(FILES:.c=.o))

FILES_B =  push_swap.c stack.c ps_functions.c utils.c tab_utils.c \
			ft_split.c  small_sort.c checker/checker.c checker/gnl.c checker/gnl_utils.c
OBJECTS_B = $(addprefix $(SRCS), $(FILES_B:.c=.o))

%.o: %.c
	@echo $@
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ -I $(INCLUDE)

bonus: $(OBJECTS_B)
	$(CC) $(CFLAGS) $(OBJECTS_B) -o $(BONUS) -I $(INCLUDE)

clean:
	rm -rf $(OBJECTS) $(OBJECTS_B)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all