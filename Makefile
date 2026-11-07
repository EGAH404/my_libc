NAME = my_libc.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f

SRCS = my_strlen.c my_strcpy.c my_strncpy.c my_strcat.c my_strncat.c my_strcmp.c my_strncmp.c my_strchr.c my_strrchr.c my_strstr.c my_memset.c my_memcpy.c my_memmove.c my_memcmp.c my_memchr.c my_strdup.c my_strtok.c my_strlcpy.c my_strlcat.c my_explicit_bzero.c my_reallocarray.c my_isalpha.c my_isdigit.c my_isalnum.c
HDRS = my_libc.h

OBJS = $(SRCS:.c=.o)

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