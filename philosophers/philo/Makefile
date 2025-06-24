CC = clang
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS =

NAME = philosophers

SOURCES = philosophers.c

OBJECTS = $(SOURCES:.c=.o)

ifneq ($(SANITIZE),)
	CFLAGS += -fsanitize=$(SANITIZE)
	LDFLAGS += -fsanitize=$(SANITIZE)
endif

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJECTS)

re: fclean all

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean