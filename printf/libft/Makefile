CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_ORIG_DIR = src/original
SRC_ADD_DIR = src/charlie
BUILD_DIR = build
LIB_DIR = lib

ORIG_SRCS = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

ADD_SRCS = \
	ft_itoa_base.c ft_numlen_base.c ft_numlen.c ft_pow.c ft_itoa_unsigned.c \
	ft_max.c ft_numlen_base_unsigned.c

OBJECTS = $(ORIG_OBJECTS) $(ADD_OBJECTS)
ORIG_OBJECTS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(ORIG_SRCS))
ADD_OBJECTS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(ADD_SRCS))

NAME = $(LIB_DIR)/$(LONG_NAME).a
LONG_NAME = lib$(SHORT_NAME)
SHORT_NAME = ft

INCLUDE = -Iinclude

# Testing
MAIN = tests.c
EXE_NAME = $(LONG_NAME)_tester


# LIBRARY CREATION

all: $(NAME)

$(NAME): $(OBJECTS)
	@mkdir -p $(LIB_DIR)
	@echo "Creating library $@"
	@ar rcs $@ $^
	@echo "$@ created."

$(BUILD_DIR)/%.o: $(SRC_ORIG_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling $< to $@"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$@ compiled."

$(BUILD_DIR)/%.o: $(SRC_ADD_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling $< to $@"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$@ compiled."

clean:
	@rm -f $(OBJECTS)
	@echo "Clean performed."

fclean: clean
	@rm -f $(NAME) $(EXE_NAME)
	@echo "Full clean performed."

re: fclean all
	@echo "Library re-built."


# TESTING

$(EXE_NAME): $(NAME) $(MAIN)
	@echo "Compiling tests"
	@$(CC) $(MAIN) $(INCLUDE) -L$(LIB_DIR) -l$(SHORT_NAME) -o $@
	@chmod +x $@
	@echo "Tests compiled."

tcomp: $(EXE_NAME)

test: tcomp
	@./$(EXE_NAME)

.PHONY: all clean fclean re tcomp test
