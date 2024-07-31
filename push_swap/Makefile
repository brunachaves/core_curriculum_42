SRCS = push_swap.c error_handling.c populate_list.c swap_operations.c rotate_operations.c push_operations.c reverse_rot_operations.c sort.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = push_swap

RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
RESET := \033[0m

all: $(NAME)

%.o: %.c push_swap.h
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): libft/libft.a $(OBJS) check_norm
	@echo "$(YELLOW)Linking...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
	@echo "$(GREEN)Build complete: $(NAME)$(RESET)"

libft/libft.a:
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make bonus -C libft

clean:
	@make clean -C libft
	@echo "$(YELLOW)Cleaning up...$(RESET)"
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft
	$(RM) $(NAME)
	@echo "$(YELLOW)Removing executables...$(RESET)"

re: fclean all

check_norm:
	@echo "$(YELLOW)Running norminette...$(RESET)"
	@OUTPUT=$$(norminette $(SRCS) push_swap.h); \
	ERRORS=$$(echo "$$OUTPUT" | grep -v ": OK!"); \
	if [ -z "$$ERRORS" ]; then \
		echo "$(GREEN)Norminette success: All files passed!$(RESET)"; \
	else \
		echo "$(RED)Norminette errors found:$(RESET)"; \
		echo "$$ERRORS"; \
	fi

.PHONY: all clean fclean re libft check_norm push_swap
