SRCS = ft_printf.c ft_printf_hex.c ft_printf_dec.c ft_printf_chrstr.c ft_convert_specifier.c ft_printf_aux.c
OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rfc $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH) all

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
