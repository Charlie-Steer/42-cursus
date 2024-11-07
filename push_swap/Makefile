# FLAGS
CC = clang
INCLUDES = -I. -Ilibft -Ilibft/src/printf -Ilibft/src/get_next_line
RELEASE_FLAGS = -Wall -Wextra -Werror -g
DEBUG_FLAGS = -g -O0
CFLAGS = $(if $(filter "Release", $(MODE)), $(RELEASE_FLAGS), $(DEBUG_FLAGS))
RM = rm -rf
LIBFT = libft/libft.a

MODE ?= $(RELEASE_MODE)
RELEASE_MODE = RELEASE
TESTING_MODE = TESTING

NAME = push_swap

SOURCES = \
	push_swap.c \
	utils.c \
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
	set_costs.c \
	rotate_and_push.c \
	debug.c 
	#! Delete debug.c

OBJECTS = $(SOURCES:.c=.o)

# RULES
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "Compiled $@ ($(MODE) mode)"

all: $(NAME) $(LIBFT)

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJECTS) $(LIBFT)
	@echo "Linked $(NAME) ($(MODE) mode)"

$(LIBFT):
	@make -C libft all

clean:
	@$(RM) $(OBJECTS) $(OBJECTS)
	@make -C libft clean
	@echo "Cleaned: OBJECT files."

fclean: clean
	@$(RM) $(NAME) $(NAME)
	@make -C libft fclean
	@echo "Cleaned: OBJECT and ELF files."

re: fclean all

test: all
	@./$(NAME)

PHONY: all clean fclean re test
