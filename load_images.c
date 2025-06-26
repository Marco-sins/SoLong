/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:34:42 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/26 11:07:59 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

int set_map_images(t_game *game)
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
                mlx_image_to_window(game->mlx, game->map->image->i_wall, x, y);
            else if (game->map->str_map[y][x] == '0')
                mlx_image_to_window(game->mlx, game->map->image->i_floor, x, y);
            else if (game->map->str_map[y][x] == 'P')
                mlx_image_to_window(game->mlx, game->map->image->i_player, x, y);
            else if (game->map->str_map[y][x] == 'C')
                mlx_image_to_window(game->mlx, game->map->image->i_coin, x, y);
            else if (game->map->str_map[y][x] == 'E')
                mlx_image_to_window(game->mlx, game->map->image->i_exit, x, y);
            x++;
        }
        y++;
    }
    return (0);
}

static void    clear_texture(t_image *image)
{
    mlx_delete_texture(image->t_coin);
    mlx_delete_texture(image->t_exit);
    mlx_delete_texture(image->t_floor);
    mlx_delete_texture(image->t_player);
    mlx_delete_texture(image->t_wall);
}

int load_images(t_game *game)
{
    t_image *image;

    image = game->map->image;
    image->t_coin = mlx_load_png("source/coin.png");
    image->t_exit = mlx_load_png("source/exit.png");
    image->t_floor = mlx_load_png("source/floor.png");
    image->t_player = mlx_load_png("source/player.png");
    image->t_wall = mlx_load_png("source/wall.png");
    if (!image->t_coin || !image->t_coin || !image->t_floor || !image->t_player || !image->t_wall)
        return (1);
    image->i_coin = mlx_texture_to_image(game->mlx, image->t_coin);
    image->i_exit = mlx_texture_to_image(game->mlx, image->t_exit);
    image->i_floor = mlx_texture_to_image(game->mlx, image->t_floor);
    image->i_player = mlx_texture_to_image(game->mlx, image->t_player);
    image->i_wall = mlx_texture_to_image(game->mlx, image->t_wall);
    clear_texture(image);
    if (!image->i_coin || !image->i_exit || !image->i_floor || !image->i_player || !image->i_wall)
        return (1);
    return (0);
}
