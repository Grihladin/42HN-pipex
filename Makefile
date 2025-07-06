# Variables
CC = cc
NAME = pipex
CFLAGS = -Wall -Wextra -Werror -g

# Directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

# Submodules
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a

# Source files
SRC = main.c \
	cmd_parse_ft.c \
	ft.c

# Include flags
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)/inc -I$(FT_PRINTF_DIR)/inc

# Object files
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))

# Rules
all: $(NAME)
	@echo "\033[0;32m$(NAME) built successfully!\033[0m"

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

submodules:
	@git submodule init
	@git submodule update

.PHONY: all clean fclean re submodules
