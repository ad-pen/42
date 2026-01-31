GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Werror -Wextra -O3

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
LIBFT_PATH = include/libft
MLX_PATH = include/minilibx

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lbsd
else
	MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
endif

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -L$(LIBFT_PATH) -lft $(MLX_FLAGS) -o $@
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_PATH) -I$(MLX_PATH) -c -o $@ $<

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) > /dev/null
	@echo "$(NAME): $(GREEN)Libft compiled$(RESET)"

$(MLX):
	@$(MAKE) -C $(MLX_PATH) > /dev/null
	@echo "$(NAME): $(GREEN)MiniLibX compiled$(RESET)"

bonus: all

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean > /dev/null
	@$(MAKE) -C $(MLX_PATH) clean > /dev/null
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)Object files deleted$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean > /dev/null
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)Executable deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus