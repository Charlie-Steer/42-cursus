# FLAGS
CC = clang
RELEASE_FLAGS = -Wall -Wextra -Werror -I. -Ilibft/src/printf -Ilibft/src/get_next_line
DEBUG_FLAGS = -g -O0
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

$(CLIENT_NAME): $(CLIENT_OBJECTS)
	@$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJECTS) $(LIBFT)
	@echo "Linked $(CLIENT_NAME) ($(MODE) mode)"

$(SERVER_NAME): $(SERVER_OBJECTS)
	@$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SERVER_OBJECTS) $(LIBFT)
	@echo "Linked $(SERVER_NAME) ($(MODE) mode)"

$(LIBFT):
	@make -C libft

all: $(LIBFT) $(CLIENT_NAME) $(SERVER_NAME)

clean:
	@$(RM) $(CLIENT_OBJECTS) $(SERVER_OBJECTS) $(BONUS_CLIENT_OBJECTS) $(BONUS_SERVER_OBJECTS)
	@echo "Cleaned: OBJECT files."

fclean: clean
	@$(RM) $(CLIENT_NAME) $(SERVER_NAME)
	@echo "Cleaned: OBJECT and ELF files."

re: fclean all

#test: $(CLIENT_NAME) $(SERVER_NAME)

bonus: 


PHONY: all clean fclean re test bonus
