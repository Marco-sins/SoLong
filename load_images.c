/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:34:42 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/06 19:53:47 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

void    set_map_images(t_game *game)
{
    int x;
    int y;

    y = 0;
    load_images(game);
    while (game->map->str_map[y])
    {
        x = 0;
        while (game->map->str_map[y][x])
        {
            if (game->map->str_map[y][x] == '1')
                mlx_image_to_window(game->mlx, game->map->image->wall, x, y);
            else if (game->map->str_map[y][x] == '0')
                mlx_image_to_window(game->mlx, game->map->image->floor, x, y);
            else if (game->map->str_map[y][x] == 'P')
                mlx_image_to_window(game->mlx, game->map->image->player, x, y);
            else if (game->map->str_map[y][x] == 'C')
                mlx_image_to_window(game->mlx, game->map->image->coin, x, y);
            else if (game->map->str_map[y][x] == 'E')
                mlx_image_to_window(game->mlx, game->map->image->exit, x, y);
            x++;
        }
        y++;
    }
}

void    load_images(t_game *game)
{
    game->map->image->coin = mlx_load_png("source/coin.png");
    game->map->image->exit = mlx_load_png("source/exit.png");
    game->map->image->floor = mlx_load_png("source/floor.png");
    game->map->image->player = mlx_load_png("source/player.png");
    game->map->image->wall = mlx_load_png("source/wall.png");
}
