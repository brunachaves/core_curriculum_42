SRCS = push_swap.c error_handling.c populate_list.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = push_swap

RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
RESET := \033[0m

all:		${NAME}

%.o:	%.c
		@echo "$(YELLOW)Compiling $<...$(RESET)"
		${CC} ${CFLAGS} -Ilibft -c $? -o $@

$(NAME): program check_norm
	@echo "$(GREEN)Build complete: $(NAME).$(RESET)"

program: $(OBJS_S) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS_S) -Llibft -lft -o ${NAME}

libft/libft.a:
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make -C libft

clean:
	@make clean -C libft
	@echo "$(YELLOW)Cleaning up...$(RESET)"
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft
	$(RM) program
	@echo "$(YELLOW)Removing executables...$(RESET)"

re:			fclean all

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

.PHONY: all clean fclean re libft check_norm push_swap program