# FLAGS
CC = clang
INCLUDES = -I. -Ilibft -Ilibft/src/printf -Ilibft/src/get_next_line
# CFLAGS = -g
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
LIBFT = libft/libft.a

NAME = push_swap
BNAME = checker

SOURCES = \
	push_swap.c \
	utils_1.c \
	utils_2.c \
	list_utils.c \
	actions_base_functions.c \
	actions_swap.c \
	actions_push.c \
	actions_rotate.c \
	actions_reverse_rotate.c \
	checks.c \
	free.c \
	split_stacks.c \
	split_stacks_helper.c \
	push_swap_subroutines_1.c \
	core_algo.c \
	set_costs.c \
	rotate_and_push.c \
	debug.c 
	#! Delete debug.c

BSOURCES = \
	checker_bonus.c \
	checks_bonus.c \
	free_bonus.c \
	utils_bonus.c \
	actions_base_functions_bonus.c \
	actions_swap_bonus.c \
	actions_push_bonus.c \
	actions_rotate_bonus.c \
	actions_reverse_rotate_bonus.c \
	debug.c
	#! Delete debug.c

OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)


# RULES
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "Compiled $@."

all: $(NAME) $(LIBFT)

bonus: $(BNAME) $(LIBFT)

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJECTS) $(LIBFT)
	@echo $(CFLAGS)
	@echo "Linked $(NAME)."

$(BNAME): $(BOBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(BNAME) $(BOBJECTS) $(LIBFT)
	@echo "Linked $(BNAME)."



$(LIBFT):
	@make -C libft all

clean:
	@$(RM) $(OBJECTS) $(BOBJECTS)
	@make -C libft clean
	@echo "Cleaned: OBJECT files."

fclean: clean
	@$(RM) $(NAME) $(BNAME)
	@make -C libft fclean
	@echo "Cleaned: OBJECT and ELF files."

re: fclean all

test: all
	@./$(NAME)

PHONY: all bonus clean fclean re test