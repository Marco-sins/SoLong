/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:48:54 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/06 19:53:56 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

t_game  *init_game()
{
    t_game *game;
    t_map   *map;
    
    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
        error("Malloc");
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
        error("Malloc");
    game->map = map;
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
    game->mlx = mlx_init(game->map->column, game->map->row, "SoLong", FALSE);

}