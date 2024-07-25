CC = clang
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c print_int.c print_unsigned_int.c print_char_and_str.c \
		  print_hexadecimal.c print_pointer.c determine_print_len.c \
		  parse_conversion_specification.c print_int_helper.c \
		  print_hexadecimal_helper.c print_pointer_helper.c \
		  libft_funcs/ft_toupper.c libft_funcs/ft_putchar_fd.c \
		  libft_funcs/ft_strchr.c libft_funcs/ft_itoa.c \
		  libft_funcs/ft_putstr_fd.c libft_funcs/ft_memmove.c \
		  libft_funcs/ft_itoa_unsigned.c libft_funcs/ft_strlen.c \
		  libft_funcs/ft_max.c libft_funcs/ft_memmove.c \
		  libft_funcs/ft_itoa_base.c libft_funcs/ft_isdigit.c \
		  libft_funcs/ft_memcmp.c libft_funcs/ft_atoi.c \
		  libft_funcs/ft_numlen.c libft_funcs/ft_numlen_base_unsigned.c \
		  libft_funcs/ft_memcpy.c libft_funcs/ft_bzero.c \
		  libft_funcs/ft_strncmp.c

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

# Testing
MAIN = tests.c
EXENAME = $(PROJECT_FULL_NAME).test
DEV_EXTENSION = .dev
DEV_EXENAME = $(EXENAME)$(DEV_EXTENSION)
DEV_CFLAGS = -Wno-unused-variable \
	-Wno-unused-parameter  -Wno-unused-function \
	-g #-fsanitize=address
	#-Wno-unused-but-set-variable

HEADERS = -I .


# LIBRARY CREATION

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "$@ compiled."

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $^
	@echo "$@ created."

bonus: $(NAME) $(BOBJECTS)
	@ar rcs $(NAME) $(BOBJECTS)
	@echo "Bonus objects added to $(NAME)."

clean:
	@rm -f $(OBJECTS) $(BOBJECTS) $(DEV_OBJECTS) $(DEV_BOBJECTS)
	@echo "Clean performed."

fclean: clean
	@rm -f $(NAME) $(DEV_NAME) $(EXENAME) $(DEV_EXENAME)
	@echo "Full clean performed."

re: fclean all
	@echo "Library re-built."


# DEV LIBRARY CREATION

%.dev.o: %.c
	@$(CC) $(CFLAGS) $(DEV_CFLAGS) $(HEADERS) -c $< -o $@
	@echo "$@ compiled."

$(DEV_NAME): $(DEV_OBJECTS) $(DEV_BOBJECTS)
	@ar rcs $(DEV_NAME) $^

dev_all: $(DEV_NAME)


# TESTING FULL

$(EXENAME): $(MAIN) $(NAME)
	@$(CC) $(CFLAGS) $(MAIN) $(NAME) $(HEADERS) -o $(EXENAME)
	@chmod +x $(EXENAME)
	@echo "Tests compiled."

tcomp: $(EXENAME)

test: tcomp
	@./$(EXENAME)


# TESTING DEV

$(DEV_EXENAME): $(MAIN) $(DEV_NAME)
	@$(CC) $(DEV_CFLAGS) $(MAIN) $(DEV_NAME) $(HEADERS) -o $(DEV_EXENAME)
	@chmod +x $(DEV_EXENAME)
	@echo "Tests compiled."

dev_tcomp: $(DEV_EXENAME)

dev_test: dev_tcomp
	@echo "TESTS: \n"
	@./$(DEV_EXENAME)


.PHONY: all bonus clean fclean re dev_all tcomp test dev_tcomp dev_test