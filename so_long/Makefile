CC = clang
RM = rm -rf

# LIBS
LIBMLX = ./MLX42/build/libmlx42.a
LIBFT = ./libft/libft.a

# FLAGS
HEADERS = -I. -Ilibft -I./MLX42/include/MLX42/ -Ilibft/src/printf -Ilibft/src/get_next_line

MODE ?= dev
DLVL ?= 0
CFLAGS_MLX = -ldl -lglfw -pthread -lm
CFLAGS_dev = -Wall -Wextra -Wunreachable-code -g -DDEBUG=$(DLVL) $(CFLAGS_MLX)
CFLAGS_prod = -Wall -Wextra -Werror -Wunreachable-code -DNDEBUG $(CFLAGS_MLX)
CFLAGS = $(CFLAGS_$(MODE))

NAME = so_long
BNAME =

# WARNING: REMOVE debug.c
SOURCES = \
	create_game_data.c \
	debug.c \
	error_handling_1.c \
	error_handling_2.c \
	input_validation.c \
	map_parsing.c \
	read_map.c \
	setup.c \
	drawing.c \
	hooks.c \
	so_long.c

BSOURCES = 

OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

# RULES
%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

all: info $(NAME) $(LIBFT)

bonus: $(BNAME) $(LIBFT)

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(HEADERS) -o $(NAME) $(OBJECTS) $(LIBFT) $(LIBMLX)
	@echo "Linked $(NAME)."

$(BNAME): $(BOBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(HEADERS) -o $(BNAME) $(BOBJECTS) $(LIBFT) $(LIBMLX)
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

bear: fclean
	@bear -- make

info:
	@echo --INFO------------------
	@echo MODE=$(MODE)
	@echo DEBUG=$(DLVL)
	@echo CFLAGS= $(CFLAGS)
	@echo ------------------------

.PHONY: all bonus clean fclean re test bear info
