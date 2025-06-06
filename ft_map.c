/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:27:38 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/06 19:28:50 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

int ft_count_rows(char **map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}

int ft_check_column(char **map, int cant_rows)
{
    int i;
    int j;

    j = ft_strlen(map[0]);
    i = 1;
    while (i < cant_rows)
    {
        if (j != ft_strlen(map[i]))
            error("Invalid map");
        i++;
    }
    return (j);
}

char **ft_mount_map(char *name_file, int rows)
{
    int fd;
    int i;
    char **map;

    fd = open(name_file, O_RDONLY);
    if (fd < 0)
        error ("Can't open the file");
    map = (char **)ft_calloc(sizeof(char *), rows);
    i = 0;
    while (rows > 0)
    {
        map[i] = get_next_line(fd);
        rows--;
    }
    close (fd);
    return (map);
}

void    ft_map(char *name_file, t_game *game)
{
    game->map->str_map = ft_mount_map(name_file, game->map->row);
    game->map->row = ft_count_rows(game->map->str_map);
    game->map->column = ft_check_column(game->map->str_map, game->map->row);
    if (!check_map(game))
        error("Invalid map");
}