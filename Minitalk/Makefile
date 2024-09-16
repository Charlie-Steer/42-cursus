# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 12:25:12 by cargonz2          #+#    #+#              #
#    Updated: 2024/09/16 13:23:45 by cargonz2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
RELEASE_FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -O0
RM = rm -rf

DEFAULT_MODE = $(RELEASE_MODE)
RELEASE_MODE = RELEASE
TESTING_MODE = TESTING

CLIENT_NAME = client
SERVER_NAME = server

CLIENT_SOURCES = \
	client.c \
	client.h \
	client_tests.c
SERVER_SOURCES = \
	server.c \
	server.h \
	server_tests.c
CLIENT_OBJECTS = $(SOURCES:.c=.o)
SERVER_OBJECTS = $(SOURCES:.c=.o)

#BONUS
#! INCOMPLETE
B_SOURCES = 
B_OBJECTS = $(B_SOURCES:.c=.o)

%.o: %.c
	@$(CC) $(RELEASE_FLAGS) -o $@ $<
	@echo "successfully compiled $@"

$(CLIENT_NAME): $(CLIENT_OBJECTS)
ifeq ($(MODE), $(RELEASE_MODE))
	@$(CC) $(RELEASE_FLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJECTS)
	@echo "$(CLIENT_NAME) compiled in $(RELEASE_MODE)"
else ifeq ($(MODE), $(TESTING_MODE))
	@$(CC) $(DEBUG_FLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJECTS)
	@echo "$(CLIENT_NAME) compiled in $(TESTING_MODE)"
end

$(SERVER_NAME): $(SERVER_OBJECTS)
 	@$(CC) $(RELEASE_FLAGS) -o $(SERVER_NAME) $(SERVER_OBJECTS)

all: $(CLIENT_NAME) $(SERVER_NAME)

clean:
	@$(RM) $(CLIENT_OBJECTS) $(SERVER_OBJECTS) $(BONUS_CLIENT_OBJECTS) $(BONUS_SERVER_OBJECTS)
	@echo "Cleaned: OBJECT files."

fclean: clean
	@$(RM) $(CLIENT_NAME) $(SERVER_NAME)
	@echo "Cleaned: OBJECT and ELF files."

bonus: 


PHONY: all clean fclean re bonus
