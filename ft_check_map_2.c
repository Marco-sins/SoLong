/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:51:49 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/29 13:08:28 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

static void    flood_fill(char **map, int x, int y)
{
    if (map[y][x] == '1' || map[y][x] == 'F')
        return ;
    else if (map[y][x] == 'C' || map[y][x] == 'P' || map[y][x] == 'E' 
        || map[y][x] == '0')
        map[y][x] = 'F';
    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}

static char    **copy_map(char **map, int rows)
{
    char    **map_copy;
    int i;

    map_copy = ft_calloc(sizeof(char *), rows + 1);
    i = 0;
    while (i < rows)
    {
        map_copy[i] = ft_strdup(map[i]);
        i++;
    }
    map_copy[i] = NULL;
    return (map_copy);
}

static void get_pos_player(char **map, int *y, int *x)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                *y = i;
                *x = j;
                return ;
            }
            j++;
        }
        i++;
    }
}

int is_valid_map(char **map, int rows)
{
    int i;
    int j;
    int x;
    int y;
    char    **cpy_map;

    i = 0;
    cpy_map = copy_map(map, rows);
    get_pos_player(cpy_map, &y, &x);
    flood_fill(cpy_map, y, x);
    while (cpy_map[i] != NULL)
    {
        j = 0;
        while (cpy_map[i][j] != '\0')
        {
            if (cpy_map[i][j] != '1' && cpy_map[i][j] != 'F' && cpy_map[i][j] != '0')
                return (FALSE);
            j++;       
        }
        i++;
    }
    ft_free_map(cpy_map);
    return (TRUE);
}
