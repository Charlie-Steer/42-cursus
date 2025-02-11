CC = clang
RM = rm -rf

# DIRS
SRC_DIR = src
BUILD_DIR = build

# LIBS
LIBMLX = ./MLX42/build/libmlx42.a
LIBFT = ./libft/libft.a
LIBS = $(LIBFT) $(LIBMLX)

# FLAGS
HEADERS = -I. -Iheaders -Ilibft -I./MLX42/include/MLX42/ -Ilibft/src/printf -Ilibft/src/get_next_line

MODE ?= dev
DLVL ?= 0
LDFLAGS = -ldl -lglfw -pthread -lm
CFLAGS_dev = -Wall -Wextra -Wunreachable-code -g -DDEBUG=$(DLVL)
CFLAGS_prod = -Wall -Wextra -Werror -Wunreachable-code -DNDEBUG
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

OBJECTS = $(addprefix $(BUILD_DIR)/, $(SOURCES:.c=.o))
BOBJECTS = $(addprefix $(BUILD_DIR)/, $(BSOURCES:.c=.o))

# RULES
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<
	@echo "$@ compiled."

all: info $(NAME)

bonus: info $(BNAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(LDFLAGS) -o $(NAME) $(OBJECTS) $(LIBS)
	@echo "Linked $(NAME)."

$(BNAME): $(BOBJECTS) $(LIBFT)
	@$(CC) $(LDFLAGS) -o $(BNAME) $(BOBJECTS) $(LIBS)
	@echo "Linked $(BNAME)."

$(LIBFT):
	@$(MAKE) -C libft all

clean:
	@$(RM) $(OBJECTS) $(BOBJECTS)
	@echo "Cleaned: OBJECT files."

fclean:
	@$(RM) $(NAME) $(BNAME) $(OBJECTS) $(BOBJECTS)
	@$(MAKE) -C libft fclean
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
	@echo LDFLAGS= $(LDFLAGS)
	@echo ------------------------

.PHONY: all bonus clean fclean re test bear info
