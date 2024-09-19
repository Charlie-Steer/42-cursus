# VARIABLES
CC = clang
CFLAGS = -Wall -Wextra -Werror -I. -Isrc/printf -Isrc/get_next_line
NAME = libft.a
VPATH = src/basic src/lists src/printf src/printf/libft_funcs src/get_next_line

BASE_LIBFT_SOURCES = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c
LISTS_SOURCES = \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
PRINTF_SOURCES = \
	ft_printf.c \
	printf_determine_print_len.c \
	printf_parse_conversion_specification.c \
	printf_print_char.c \
	printf_print_hexadecimal.c \
	printf_print_hexadecimal_helper.c \
	printf_print_int.c \
	printf_print_int_helper.c \
	printf_print_pointer.c \
	printf_print_pointer_helper.c \
	printf_print_str.c \
	printf_print_str_helper.c \
	printf_print_unsigned_int.c \
	printf_ft_atoi.c \
	printf_ft_bzero.c \
	printf_ft_isdigit.c \
	printf_ft_itoa_base.c \
	printf_ft_itoa.c \
	printf_ft_itoa_unsigned.c \
	printf_ft_max.c \
	printf_ft_memcmp.c \
	printf_ft_memcpy.c \
	printf_ft_memmove.c \
	printf_ft_numlen_base_unsigned.c \
	printf_ft_numlen.c \
	printf_ft_putchar_fd.c \
	printf_ft_putstr_fd.c \
	printf_ft_strchr.c \
	printf_ft_strlen.c \
	printf_ft_strncmp.c \
	printf_ft_toupper.c
GET_NEXT_LINE_SOURCES = \
	get_next_line.c \
	get_next_line_utils.c


SOURCES = $(BASE_LIBFT_SOURCES) $(LISTS_SOURCES) $(PRINTF_SOURCES) $(GET_NEXT_LINE_SOURCES)
OBJECTS = $(addprefix obj/, $(SOURCES:.c=.o))

# RULES
obj/%.o: %.c
	@mkdir -p obj/
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ compiled."

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	@echo "$(NAME) created."

all: $(NAME)

clean:
	@rm -f $(OBJECTS)
	@echo "Clean performed."

fclean: clean
	@rm -f $(NAME)
	@echo "Full clean performed."

re: fclean all
	@echo "Library re-built."

.PHONY: all clean fclean re
