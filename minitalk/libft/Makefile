SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strrchr.c ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_printf_hex.c ft_printf_dec.c ft_printf_chrstr.c ft_printf_ptr.c ft_convert_specifier.c get_next_line.c get_next_line_utils.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 

OBJS_S = $(SRCS:.c=.o)

OBJS_B = $(BONUS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

bonus: $(OBJS_B) $(OBJS_S)
	ar rfc $(NAME) $(OBJS_B) $(OBJS_S)

$(NAME): $(OBJS_S)
	ar rfc $(NAME) $(OBJS_S)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_S) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re