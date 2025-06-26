/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:37:08 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/26 10:20:30 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

static int ft_count_exit(t_game *game)
{
    int i;
    int j;
    int exit;

    i = 0;
    exit = 0;
    while (game->map->str_map[i])
    {
        j = 0;
        while (game->map->str_map[i][j])
        {
            if (game->map->str_map[i][j] == 'E')
            {
                exit++;
                game->map->exit_column = j;
                game->map->exit_row = i;
            }
            j++;
        }
        i++;
    }
    if (exit != 1)
        return (FALSE);
    return (TRUE);
}

static int ft_count_player(t_game *game)
{
    int i;
    int j;
    int player;

    i = 0;
    player = 0;
    while (game->map->str_map[i])
    {
        j = 0;
        while (game->map->str_map[i][j])
        {
            if (game->map->str_map[i][j] == 'P')
            {
                player++;
                game->map->x_player = j;
                game->map->y_player = i;
            }
            j++;
        }
        i++;
    }
    if (player != 1)
        return (FALSE);
    return (TRUE);
}

static int ft_count_coin(t_game *game)
{
    int i;
    int j;
    int coin;

    i = 0;
    coin = 0;
    while (game->map->str_map[i])
    {
        j = 0;
        while (game->map->str_map[i][j])
        {
            if (game->map->str_map[i][j] == 'C')
                coin++;
            j++;
        }
        i++;
    }
    if (coin < 1)
        return (FALSE);
    game->map->coin = coin;
    return (TRUE);
}

static int check_characters(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != 'C' || map[i][j] != 'E' || map[i][j] != '1' || map[i][j] != '0' || map[i][j] != 'P')
                return (FALSE);
            j++;
        }
        i++;
    }
    return (TRUE);
}

int check_map(t_game *game)
{
    if (!check_characters(game->map->str_map) || ft_count_coin(game) || 
        !ft_count_player(game) || !ft_count_exit(game))
        return (FALSE);
    if (!is_valid_map(game->map->str_map, game->map->row))
        return (FALSE);
    return (TRUE);
}