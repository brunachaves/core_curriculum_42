SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = minitalk

all:		${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -Ilibft -c $? -o $@

${NAME}:	 server client

server:		server.o
		@make -C libft
		${CC} ${CFLAGS} $? -Llibft -lft -o server

client:		client.o
		@make -C libft
		${CC} ${CFLAGS} $? -Llibft -lft -o client

libft:
		make -C libft

clean:
			make clean -C libft
			${RM} ${OBJS}

fclean:		clean
			${RM} server client libft/libft.a

re:			fclean all

.PHONY: all clean fclean re libft minitalk server client