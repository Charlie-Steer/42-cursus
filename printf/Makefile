CC = clang
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c
BSOURCES =
OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)
DEV_OBJECTS = $(SOURCES:.c=.dev.o)
DEV_BOBJECTS = $(BSOURCES:.c=.dev.o)

# printf
NAME = libftprintf.a
PROJECT_PATH = .
PROJECT_SHORT_NAME = ftprintf
PROJECT_FULL_NAME = lib$(PROJECT_SHORT_NAME)
DEV_NAME = $(PROJECT_FULL_NAME).dev.a

# libft
LIBFT_PATH = libft/lib
LIBFT_SHORT_NAME = ft
LIBFT_NAME = lib$(LIBFT_SHORT_NAME).a
LIBFT = $(LIBFT_PATH)/$(LIBFT_NAME)

# Testing
MAIN = tests.c
EXENAME = $(PROJECT_FULL_NAME).test
DEV_EXTENSION = .dev
DEV_EXENAME = $(EXENAME)$(DEV_EXTENSION)
DEV_CFLAGS = -Wno-unused-variable -Wno-unused-but-set-variable \
			 -Wno-unused-parameter -Wno-unused-function

HEADERS = -I$(LIBFT_PATH)

# LIBRARY CREATION

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "$@ compiled."

all: $(LIBFT) $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $^
	@echo "$@ created."

bonus: $(NAME) $(BOBJECTS)
	@ar rcs $(NAME) $(BOBJECTS)
	@echo "Bonus objects added to $(NAME)."

clean:
	@rm -f $(OBJECTS) $(BOBJECTS) $(DEV_OBJECTS) $(DEV_BOBJECTS)
	@make -C $(LIBFT_PATH) clean
	@echo "Clean performed."

fclean: clean
	@rm -f $(NAME) $(DEV_NAME) $(EXENAME) $(DEV_EXENAME)
	@make -C $(LIBFT_PATH) fclean
	@echo "Full clean performed."

re: fclean all
	@echo "Library re-built."


# DEV LIBRARY CREATION

%.dev.o: %.c
	@$(CC) $(CFLAGS) $(DEV_CFLAGS) $(HEADERS) -c $< -o $@
	@echo "$@ compiled."

$(DEV_NAME): $(DEV_OBJECTS) $(DEV_BOBJECTS)
	@ar rcs $(DEV_NAME) $^

dev_all: $(LIBFT) $(DEV_NAME)


# LIBFT COMPILATION

$(LIBFT):
	@echo Compiling libft...
	@make -C $(LIBFT_PATH) all
	@echo Libft compiled.

libft: $(LIBFT)


# TESTING FULL
#! This rule is untested.
$(EXENAME): $(MAIN) $(NAME) $(LIBFT)
	@$(CC) $(MAIN) $(DEV_NAME) $(LIBFT) $(HEADERS) -o $(EXENAME)
	@chmod +x $(EXENAME)
	@echo "Tests compiled."

tcomp: $(EXENAME)

test: tcomp
	@./$(EXENAME)


# TESTING DEV
$(DEV_EXENAME): $(MAIN) $(DEV_NAME) $(LIBFT)
	@$(CC) $(DEV_CFLAGS) $(MAIN) $(DEV_NAME) $(LIBFT) $(HEADERS) -o $(DEV_EXENAME)
	@chmod +x $(DEV_EXENAME)
	@echo "Tests compiled."

dev_tcomp: $(DEV_EXENAME)

dev_test: dev_tcomp
	@echo "TESTS: \n"
	@./$(DEV_EXENAME)


.PHONY: all bonus clean fclean re dev_all libft tcomp test dev_tcomp dev_test
