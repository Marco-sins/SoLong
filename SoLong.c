/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:48:54 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/03 19:12:51 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

t_game  *init_game()
{
    t_game *game;
    t_map   map;
    t_player    player;

    player.x = 0;
    player.y = 0;
    map.coin = 0;
    map.column = 0;
    map.exit_column = 0;
    map.exit_row = 0;
    map.mov = 0;
    map.row = 0;
    map.player = player;
    map.str_map = NULL;
    game = (t_game *)malloc(sizeof(t_game));
    if (!game)
        error("Malloc");
    game->map = map;
    game->mlx = mlx_init();
    if (!game->mlx)
        error("MLX");
    return (game);
}

int main(int ac, char **av)
{
    t_game *game;

    if (ac != 2)
        error("Arguments");
    else if (!check_name(av[1]))
        error("Invalid map name");
    game = init_game();
    ft_map(av[1], game);
}