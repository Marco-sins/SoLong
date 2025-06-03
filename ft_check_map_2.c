/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:51:49 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/03 19:40:05 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

void    flood_fill(char **map, int x, int y)
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

int is_valid_map(char **map, int rows)
{
    int i;
    int j;

    i = 0;
    flood_fill(copy_map(map, rows), 0, 0);
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != NULL)
        {
            if (map[i][j] != '1' && map[i][j] != 'F')
                return (FALSE);
            j++;       
        }
        i++;
    }
    return (TRUE);
}

char    **copy_map(char **map, int rows)
{
    char    **map_copy;
    int i;

    map_copy = ft_calloc(sizeof(char *), rows + 1);
    while (i < rows)
    {
        map_copy[i] = ft_strdup(map[i]);
        i++;
    }
    map_copy[i] = NULL;
    return (map_copy);
}
