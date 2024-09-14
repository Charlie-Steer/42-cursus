#! BE CAREFUL.
#! THIS FILE IS NOT ACTUALLY MEANT TO BE DELIVERED.
#! THIS IS JUST TO EASE DEVELOPEMENT

# VARS #
# Set mode to "ft" or "test"
ifndef MODE
	MODE = test
endif

CC = gcc

HEADER =  \
	get_next_line.h

SOURCES = \
	get_next_line.c \
	get_next_line_utils.c \
	tests.c

B_HEADER = \
	get_next_line_bonus.h

B_SOURCES = \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \
	test_b.c

OBJECTS = $(SOURCES:.c=.o)

B_OBJECTS = $(B_SOURCES:.c=.o)

ELF = get_next_line
B_ELF = get_next_line_bonus

RELEASE_FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
DEV_FLAGS = -g -O0


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

$(B_ELF): $(B_OBJECTS)
ifeq ($(MODE), ft)
	@$(CC) $(RELEASE_FLAGS) -o $(B_ELF) $(B_OBJECTS)
	@echo "\"$(B_ELF)\" compiled in $(shell echo $(MODE) | tr 'a-z' 'A-Z') mode."
else ifeq ($(MODE), test)
	@$(CC) $(DEV_FLAGS) -o $(B_ELF) $(B_OBJECTS)
	@echo "\"$(B_ELF)\" compiled in $(shell echo $(MODE) | tr 'a-z' 'A-Z') mode."
else
	@echo "error: Invalid compilation mode. Set MODE to a valid value."
endif

all: $(ELF)

test: $(ELF)
	@./$(ELF)

bonus: $(B_ELF)

b_test: $(B_ELF)
	@./$(B_ELF)

clean:
	@$(RM) $(OBJECTS) $(B_OBJECTS) $(B_ELF) $(ELF)

re: clean all

.PHONY: all bonus test clean re
