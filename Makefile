NAME = my_libc.a

CC        = cc
CFLAGS        = -Wall -Wextra -Werror
AR        = ar
ARFLAGS        = rcs
RM        = rm -f

SRCS        = my_strlen.c
HDRS        = my_libc.h

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
    $(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c my_libc.h
    $(CC) $(CFLAGS) -c $< -o $@

format:
    clang-format --style=file -i $(SRCS) $(HDRS)

clean:
    $(RM) $(OBJS)

fclean: clean
    $(RM) $(NAME)

re: fclean all

.PHONY: all format clean fclean re
