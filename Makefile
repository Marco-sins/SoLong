CC = gcc

CFLAGS  := -g -Wall -Wextra -Werror

MLX_DIR = ./MLX42
MLX := $(MLX_DIR)/build/libmlx42.a

LIBFT := libft/libft.a

GNL_DIR := ./gnl

INC := -I libft/includes

HEADERS := -I$(MLX)
SRCS := 	error.c \
			ft_check_map.c \
			ft_check_map_2.c \
			ft_map.c \
			load_images.c \
			move_player.c \
			SoLong_utils.c \
			SoLong.c \
			$(GNL_DIR)/get_next_line.c \
			$(GNL_DIR)/get_next_line_utils.c

OBJS := ${SRCS:.c=.o}

NAME := so_long

all: $(MLX) $(LIBFT) $(NAME)

$(MLX):
	cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4
	@echo 🔥 🔥 Making MLX ✅ ✅

$(LIBFT):
	@make -C libft	
	@echo 🔥 🔥 Making Executables ✅ ✅

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(HEADERS) -lglfw -o $(NAME) -lm

clean:
	@rm -fr $(OBJS)
	make -C libft clean
	make -C $(MLX_DIR)/build clean
	@echo 🔥 🔥 Deleting all .o Files 🗑️ 🗑️

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(MLX_DIR)/build
	make -C libft fclean
	@echo  🔥 🔥 Deleting executables files 🗑️ 🗑️

re: clean all

.PHONY: all, clean, fclean, re