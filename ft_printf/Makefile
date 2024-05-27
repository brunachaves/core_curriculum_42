SRCS = ft_printf.c ft_printf_hex.c ft_printf_dec.c ft_printf_chrstr.c ft_convert_specifier.c

OBJS_S = $(SRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = libftprinf.a

all: $(NAME)

$(NAME): $(OBJS_S)
	ar rfc $(NAME) $(OBJS_S)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_S)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

//include Makefile from libft!