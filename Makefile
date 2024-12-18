CC = gcc

CFLAGS  := -g -Wall -Wextra -Werror	-Wunreachable-code

MLX_DIR = ./MLX42
MLX := $(MLX_DIR)/libmlx42.a

LIBFT := libft/libft.a

INC := -I libft/includes

HEADERS := -I$(MLX)
SRCS := so_long 

OBJS := ${SRCS:.c=.o}

NAME := so_long

all: $(NAME)

libmlx:
	@make -C $(MLX_DIR)
	@echo 🔥 🔥 Making MLX ✅ ✅

$(LIBFT):
	@make -C libft
	@echo 🔥 🔥 Making Executables ✅ ✅

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX) $(HEADERS) -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ -o $(NAME)

clean:
	@rm -fr $(OBJS)
	@echo 🔥 🔥 Deleting all .o Files 🗑️ 🗑️

fclean: clean
	@rm -rf $(NAME)
	@echo  🔥 🔥 Deleting executables files 🗑️ 🗑️

re: clean all

.PHONY: all, clean, fclean, re, libmlx