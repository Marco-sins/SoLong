/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:48:54 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/26 11:08:17 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

static t_game  *init_game()
{
    t_game *game;
    t_map   *map;
    
    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->x_player = 0;
    map->y_player = 0;
    map->coin = 0;
    map->column = 0;
    map->exit_column = 0;
    map->exit_row = 0;
    map->mov = 0;
    map->row = 0;
    map->str_map = NULL;
    game = (t_game *)malloc(sizeof(t_game));
    if (!game)
    {
        free(map);
        return (NULL);
    }
    game->map = map;
    return (game);
}

int main(int ac, char **av)
{
    t_game *game;

    if (ac != 2)
        return (ft_printf("ERROR\n"), 1);
    else if (!check_name(av[1]))
        return (ft_printf("ERROR\n"), 1);
    game = init_game();
    if (ft_map(av[1], game))
        return (1);
    game->mlx = mlx_init(64 * game->map->column, 64 * game->map->row, "SoLong", FALSE);
    if (!game->mlx)
        return (ft_free(game), 1);
    if (load_images(game) && set_map_images(game))
        return (ft_free(game), 1);
    mlx_key_hook(game->mlx, &move_player, game);
    mlx_loop(game->mlx);
    mlx_terminate(game->mlx);
    return (ft_free(game), 0);
}