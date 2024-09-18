SRCS = server.c client.c error_handling.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f

NAME = minitalk

RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
RESET := \033[0m

all: check_norm server client

server: server.o libft/libft.a
	@echo "$(YELLOW)Building server...$(RESET)"
	$(CC) $(CFLAGS) server.o -Llibft -lft -o server

client: client.o error_handling.o libft/libft.a
	@echo "$(YELLOW)Building client...$(RESET)"
	$(CC) $(CFLAGS) client.o error_handling.o -Llibft -lft -o client

server.o: server.c
	@echo "$(YELLOW)Compiling server.o...$(RESET)"
	$(CC) $(CFLAGS) -c server.c -o server.o

client.o: client.c
	@echo "$(YELLOW)Compiling client.o...$(RESET)"
	$(CC) $(CFLAGS) -c client.c -o client.o

error_handling.o: error_handling.c
	@echo "$(YELLOW)Compiling error_handling.o...$(RESET)"
	$(CC) $(CFLAGS) -c error_handling.c -o error_handling.o

libft/libft.a:
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make -C libft

clean:
	@make clean -C libft
	@echo "$(YELLOW)Cleaning up...$(RESET)"
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft
	$(RM) server client
	@echo "$(YELLOW)Removing executables...$(RESET)"

re: fclean all

check_norm:
	@echo "$(YELLOW)Running norminette...$(RESET)"
	@OUTPUT=$$(norminette $(SRCS)); \
	ERRORS=$$(echo "$$OUTPUT" | grep -v ": OK!"); \
	if [ -z "$$ERRORS" ]; then \
		echo "$(GREEN)Norminette success: All files passed!$(RESET)"; \
	else \
		echo "$(RED)Norminette errors found:$(RESET)"; \
		echo "$$ERRORS"; \
	fi

.PHONY: all clean fclean re libft check_norm
