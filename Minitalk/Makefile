# FLAGS
CC = clang
INCLUDES = -I. -Ilibft -Ilibft/src/printf -Ilibft/src/get_next_line
RELEASE_FLAGS = -Wall -Wextra -Werror $(INCLUDES)
DEBUG_FLAGS = -g -O0 $(INCLUDES)
CFLAGS = $(if $(filter "Release", $(MODE)), $(RELEASE_FLAGS), $(DEBUG_FLAGS))
RM = rm -rf
LIBFT = libft/libft.a

MODE ?= $(RELEASE_MODE)
RELEASE_MODE = RELEASE
TESTING_MODE = TESTING

CLIENT_NAME = client
SERVER_NAME = server

CLIENT_SOURCES = \
	client.c
SERVER_SOURCES = \
	server.c
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)

# BONUS
#! INCOMPLETE
B_SOURCES = 
B_OBJECTS = $(B_SOURCES:.c=.o)

# RULES
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "Compiled $@ ($(MODE) mode)"

all: $(CLIENT_NAME) $(SERVER_NAME) $(LIBFT)

$(CLIENT_NAME): $(CLIENT_OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJECTS) $(LIBFT)
	@echo "Linked $(CLIENT_NAME) ($(MODE) mode)"

$(SERVER_NAME): $(SERVER_OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJECTS) $(LIBFT)
	@echo "Linked $(SERVER_NAME) ($(MODE) mode)"

$(LIBFT):
	@make -C libft all

clean:
	@$(RM) $(CLIENT_OBJECTS) $(SERVER_OBJECTS) $(BONUS_CLIENT_OBJECTS) $(BONUS_SERVER_OBJECTS)
	@echo "Cleaned: OBJECT files."

fclean: clean
	@$(RM) $(CLIENT_NAME) $(SERVER_NAME)
	@echo "Cleaned: OBJECT and ELF files."

re: fclean all

test: all
	@./server

bonus: 


PHONY: all clean fclean re test bonus
