CC = clang
FLAGS = -Wall -Wextra -Werror
T_FLAGS = -g -O0
NAME = pipex

#! ENSURE YOU ARE DOING THE EXPECTED THINGS WITH EVERY COMMAND!
#! Is $(NAME) the right file?
#! What are clean and fclean supposed to clean?
#! Can I use "*" in the clean commands?
#! How would bonus be handled? Although I'd probably rather skip this one.
#! Things might be different now that we are making a program instead of a library file. Make sure it is right.

%.o: %.c
	$(CC) $(FLAGS) -o $@ $<

all: $(NAME)

test: $(NAME)
	@./$(NAME)
	@echo "running $(NAME)..."

clean:
	@rm -rf $(NAME)

fclean: clean
	@rm -rf $(OBJECTS)


Phony: all clean fclean bonus re test btest