/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:37:08 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/01 20:30:21 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

int ft_count_exit(char **map)
{
    int i;
    int j;
    int exit;

    i = 0;
    exit = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'E')
                exit++;
            j++;
        }
        i++;
    }
    if (exit != 1)
        error ("Exit");
    return (TRUE);
}

int ft_count_player(char **map)
{
    int i;
    int j;
    int player;

    i = 0;
    player = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                player++;
            j++;
        }
        i++;
    }
    if (player != 1)
        error ("Player");
    return (TRUE);
}

int ft_count_coin(char **map)
{
    int i;
    int j;
    int coin;

    i = 0;
    coin = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                coin++;
            j++;
        }
        i++;
    }
    if (coin < 1)
        error ("Coin");
    return (TRUE);
}

int check_map(char **map)
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
                error("Invalid character");
            j++;
        }
        i++;
    }
    return (TRUE);
}

