CC = cc

CFLAGS  := -g -Wall -Wextra -Werror

MLX_DIR = ./MLX42
MLX := $(MLX_DIR)/build/libmlx42.a

LIBFT := libft/libft.a

INC := -I libft/includes

HEADERS := -I$(MLX)
SRCS := 	error.c \
			ft_check_map.c \
			ft_check_map_2.c \
			ft_map.c \
			load_images.c \
			move_player.c \
			so_long_utils.c \
			so_long.c \

OBJDIR			= objs
OBJS			= $(SRCS:%.c=$(OBJDIR)/%.o)

NAME := so_long

all: $(MLX) $(LIBFT) $(NAME)

$(MLX):
	cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4
	@echo 🔥 🔥 Making MLX ✅ ✅

$(LIBFT):
	@make -C libft	
	@echo 🔥 🔥 Making Executables ✅ ✅

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(HEADERS) -lglfw -o $(NAME) -lm

clean:
	@rm -fr $(OBJDIR)
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