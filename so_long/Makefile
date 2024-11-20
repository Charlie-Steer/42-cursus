# FLAGS
CC = clang

LIBMLX = ./MLX42/include/MLX42
# LIBFT = ./libft
LIBFT = ./libft/libft.a
INCLUDES = -I. -Ilibft -I./MLX42/include/MLX42/ -Ilibft/src/printf -Ilibft/src/get_next_line

MODE ?= dev
DLVL ?= 0
CFLAGS_MLX = -ldl -lglfw -pthread -lm
CFLAGS_dev = -Wall -Wextra -Wunreachable-code -g -DDEBUG=$(DLVL) $(CFLAGS_MLX)
CFLAGS_prod = -Wall -Wextra -Werror -Wunreachable-code -DNDEBUG $(CFLAGS_MLX)
CFLAGS = $(CFLAGS_$(MODE))

RM = rm -rf
LIBS := \
	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm \
	$(lIBFT)/libft.a

NAME = so_long
BNAME =

SOURCES = \
	so_long.c \
	input_validation.c \
	map_parsing.c \
	error_handling.c \
	debug.c #! DELETE

BSOURCES = \

OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

$(info Compiling with DEBUG=$(DLVL))

# RULES
%.o: %.c
	echo $(CFLAGS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

all: $(NAME) $(LIBFT)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4	@echo "Compiled $@."

bonus: $(BNAME) $(LIBFT)

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJECTS) $(LIBFT)
	@echo "Linked $(NAME)."

$(BNAME): $(BOBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(BNAME) $(BOBJECTS)
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