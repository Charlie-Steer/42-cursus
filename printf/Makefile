CC = clang
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c print_int.c print_unsigned_int.c print_char_and_str.c \
		  print_hexadecimal.c print_pointer.c determine_print_len.c \
		  parse_conversion_specification.c
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
LIBFT_PATH = libft
LIBFT_ARCH_PATH = libft/lib
LIBFT_SHORT_NAME = ft
LIBFT_NAME = lib$(LIBFT_SHORT_NAME).a
LIBFT = $(LIBFT_ARCH_PATH)/$(LIBFT_NAME)

# Testing
MAIN = tests.c
EXENAME = $(PROJECT_FULL_NAME).test
DEV_EXTENSION = .dev
DEV_EXENAME = $(EXENAME)$(DEV_EXTENSION)
DEV_CFLAGS = -Wno-unused-variable \
	-Wno-unused-parameter  -Wno-unused-function \
	#-Wno-unused-but-set-variable

HEADERS = -I libft/include

# LIBRARY CREATION

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "$@ compiled."

all: $(NAME) $(LIBFT)

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
	@$(CC) $(CFLAGS) $(MAIN) $(NAME) $(LIBFT) $(HEADERS) -o $(EXENAME)
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
