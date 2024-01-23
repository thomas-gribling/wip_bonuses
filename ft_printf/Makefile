NAME = libftprintf.a

SRCS = srcs/
INCLUDE = include/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c core.c
OBJECTS = $(addprefix $(SRCS), $(FILES:.c=.o))

B_FILES = ft_printf_bonus.c flags_bonus.c utils_bonus.c core.c
B_OBJECTS = $(addprefix $(SRCS), $(B_FILES:.c=.o))

HEADERS = ft_printf.h
HEADERS_PREFIX = $(addprefix $(INCLUDE), $(HEADERS))

%.o: %c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

$(NAME): $(OBJECTS)
	ar -rc $@ $(OBJECTS) $(HEADERS_PREFIX)

bonus: $(B_OBJECTS)
	ar -rc $(NAME) $(B_OBJECTS) $(HEADERS_PREFIX)

all: $(NAME)

clean:
	rm -rf $(OBJECTS) $(B_OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all