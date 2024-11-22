# Variables
CC = cc
NAME = pipex
CFLAGS = -Wall -Wextra -Werror
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a
GET_NEXT_LINE_DIR = get_next_line
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/get_next_line.a
SRC = main.c \
	ft_split.c \
	string_tools.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)
	@echo "\033[0;32m$(NAME) built successfully!\033[0m"

$(NAME): $(OBJ) $(FT_PRINTF) $(GET_NEXT_LINE)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FT_PRINTF) $(GET_NEXT_LINE)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(GET_NEXT_LINE):
	@$(MAKE) -C $(GET_NEXT_LINE_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	@rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
