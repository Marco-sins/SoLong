/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:34:42 by mmembril          #+#    #+#             */
/*   Updated: 2025/07/14 19:58:04 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

static void	print_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->str_map[y] != NULL)
	{
		x = 0;
		while (game->map->str_map[y][x] != '\0')
		{
			if (game->map->str_map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->map->image->i_wall, x * 64,
					y * 64);
			else
				mlx_image_to_window(game->mlx, game->map->image->i_floor, x
					* 64, y * 64);
			x++;
		}
		y++;
	}
}

int	set_map_images(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	print_floor(game);
	while (game->map->str_map[y] != NULL)
	{
		x = 0;
		while (game->map->str_map[y][x] != '\0')
		{
			if (game->map->str_map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->map->image->i_player, x
					* 64, y * 64);
			else if (game->map->str_map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->map->image->i_coin, x * 64,
					y * 64);
			else if (game->map->str_map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->map->image->i_exit, x * 64,
					y * 64);
			x++;
		}
		y++;
	}
	return (0);
}

static void	ft_texture_to_image(t_game *game)
{
	game->map->image->i_coin = mlx_texture_to_image(game->mlx,
			game->map->image->t_coin);
	game->map->image->i_exit = mlx_texture_to_image(game->mlx,
			game->map->image->t_exit);
	game->map->image->i_floor = mlx_texture_to_image(game->mlx,
			game->map->image->t_floor);
	game->map->image->i_player = mlx_texture_to_image(game->mlx,
			game->map->image->t_player);
	game->map->image->i_wall = mlx_texture_to_image(game->mlx,
			game->map->image->t_wall);
}

void	clear_img(t_game *game)
{
	mlx_delete_texture(game->map->image->t_coin);
	mlx_delete_texture(game->map->image->t_exit);
	mlx_delete_texture(game->map->image->t_floor);
	mlx_delete_texture(game->map->image->t_player);
	mlx_delete_texture(game->map->image->t_wall);
	mlx_delete_image(game->mlx, game->map->image->i_coin);
	mlx_delete_image(game->mlx, game->map->image->i_exit);
	mlx_delete_image(game->mlx, game->map->image->i_floor);
	mlx_delete_image(game->mlx, game->map->image->i_player);
	mlx_delete_image(game->mlx, game->map->image->i_wall);
}

int	load_images(t_game *game)
{
	game->map->image = (t_image *)malloc(sizeof(t_image));
	if (!game->map->image)
		return (1);
	game->map->image = game->map->image;
	game->map->image->t_coin = mlx_load_png("./sources/coin.png");
	game->map->image->t_exit = mlx_load_png("./sources/exit.png");
	game->map->image->t_floor = mlx_load_png("./sources/floor.png");
	game->map->image->t_player = mlx_load_png("./sources/player.png");
	game->map->image->t_wall = mlx_load_png("./sources/wall.png");
	if (!game->map->image->t_coin || !game->map->image->t_coin
		|| !game->map->image->t_floor || !game->map->image->t_player
		|| !game->map->image->t_wall)
		return (ft_printf("ERROR\n"), 1);
	ft_texture_to_image(game);
	if (!game->map->image->i_coin || !game->map->image->i_exit
		|| !game->map->image->i_floor || !game->map->image->i_player
		|| !game->map->image->i_wall)
		return (ft_printf("ERROR\n"), 1);
	return (0);
}
