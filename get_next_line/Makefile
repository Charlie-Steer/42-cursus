# VARS #
# Set mode to "ft" or "test"
ifndef MODE
	MODE = ft
endif

SOURCES = \
	get_next_line.c

ELF = get_next_line


# RULES #
$(ELF): clean $(SOURCES)
ifeq ($(MODE), ft)
	@$(CC) -Wall -Wextra -Werror -o $(ELF) $(SOURCES)
	@echo "\"$(ELF)\" compiled in $(shell echo $(MODE) | tr 'a-z' 'A-Z') mode."
else ifeq ($(MODE), test)
	@$(CC) -o $(ELF) $(SOURCES) -g -Og
	@echo "\"$(ELF)\" compiled in $(shell echo $(MODE) | tr 'a-z' 'A-Z') mode."
else
	@echo "error: Invalid compilation mode. Set MODE to a valid value."
endif

all: $(ELF)

test: $(ELF)
	@./$(ELF)

clean:
	@$(RM) $(ELF)

re: clean all

.PHONY: all test clean re
