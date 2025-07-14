/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:27:40 by marco             #+#    #+#             */
/*   Updated: 2025/07/14 19:53:53 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

static void	reprint_images(t_game *game, int x, int y, t_image *image)
{
	if (game->map->str_map[y][x] == 'E')
	{
		mlx_image_to_window(game->mlx, image->i_floor, game->map->x_player * 64,
			game->map->y_player * 64);
		mlx_image_to_window(game->mlx, image->i_exit, game->map->x_player * 64,
			game->map->y_player * 64);
	}
	else
	{
		mlx_image_to_window(game->mlx, image->i_floor, game->map->x_exit * 64,
			game->map->y_exit * 64);
		mlx_image_to_window(game->mlx, image->i_exit, game->map->x_exit * 64,
			game->map->y_exit * 64);
	}
	if (game->map->str_map[game->map->y_player][game->map->x_player] != 'E'
		&& game->map->str_map[game->map->y_player][game->map->x_player] != '1')
		mlx_image_to_window(game->mlx, image->i_floor, game->map->x_player * 64,
			game->map->y_player * 64);
	game->map->x_player = x;
	game->map->y_player = y;
	if (game->map->str_map[game->map->y_player][game->map->x_player] == 'C')
	{
		mlx_image_to_window(game->mlx, image->i_floor, game->map->x_player * 64,
			game->map->y_player * 64);
		game->map->str_map[game->map->y_player][game->map->x_player] = '0';
		game->map->coin--;
	}
	mlx_image_to_window(game->mlx, image->i_player, game->map->x_player * 64,
		game->map->y_player * 64);
}

static void	key_action(t_game *game, int x, int y)
{
	if (game->map->str_map[y][x] == 'E' && game->map->coin == 0)
	{
		mlx_close_window(game->mlx);
		ft_printf("\nYou have won\n");
	}
	else if (game->map->str_map[y][x] != '1')
	{
		reprint_images(game, x, y, game->map->image);
		game->moves++;
		ft_printf("Number of movements: %d\n", game->moves);
	}
}

void	move_player(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		key_action(game, game->map->x_player, game->map->y_player - 1);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		key_action(game, game->map->x_player + 1, game->map->y_player);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		key_action(game, game->map->x_player, game->map->y_player + 1);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		key_action(game, game->map->x_player - 1, game->map->y_player);
}
