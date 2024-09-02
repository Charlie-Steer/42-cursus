#! BE CAREFUL.
#! THIS FILE IS NOT ACTUALLY MEANT TO BE DELIVERED.
#! THIS IS JUST TO EASE DEVELOPEMENT

# VARS #
# Set mode to "ft" or "test"
ifndef MODE
	MODE = ft
endif

CC = gcc

HEADER =  \
	get_next_line.h

SOURCES = \
	get_next_line.c \
	get_next_line_utils.c \
	tests.c

OBJECTS = $(SOURCES:.c=.o)

ELF = get_next_line

RELEASE_FLAGS = -Wall -Wextra -Werror
DEV_FLAGS = -g -Og


# RULES #

%.o: %.c
	@$(CC) -c $< -o $@ $(DEV_FLAGS)
	@echo "successfully compiled $@."

$(ELF): $(OBJECTS)
ifeq ($(MODE), ft)
	@$(CC) $(RELEASE_FLAGS) -o $(ELF) $(OBJECTS)
	@echo "\"$(ELF)\" compiled in $(shell echo $(MODE) | tr 'a-z' 'A-Z') mode."
else ifeq ($(MODE), test)
	@$(CC) $(DEV_FLAGS) -o $(ELF) $(OBJECTS)
	@echo "\"$(ELF)\" compiled in $(shell echo $(MODE) | tr 'a-z' 'A-Z') mode."
else
	@echo "error: Invalid compilation mode. Set MODE to a valid value."
endif

all: $(ELF)

test: $(ELF)
	@./$(ELF)

clean:
	@$(RM) $(OBJECTS) $(ELF)

re: clean all

.PHONY: all test clean re
