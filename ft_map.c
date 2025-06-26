/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:27:38 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/26 11:05:55 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

static int ft_count_rows(char **map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}

static int ft_check_column(char **map, int cant_rows)
{
    int i;
    size_t j;

    j = ft_strlen(map[0]);
    i = 1;
    while (i < cant_rows)
    {
        if (j != ft_strlen(map[i]))
            return (0);
        i++;
    }
    return (j);
}

static char **ft_mount_map(char *name_file, int rows)
{
    int fd;
    int i;
    char **map;

    fd = open(name_file, O_RDONLY);
    if (fd < 0)
        return (NULL);
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

int ft_map(char *name_file, t_game *game)
{
    game->map->str_map = ft_mount_map(name_file, game->map->row);
    if (!game->map->str_map)
        return (error("ERROR\n", game));
    game->map->row = ft_count_rows(game->map->str_map);
    game->map->column = ft_check_column(game->map->str_map, game->map->row);
    if (game->map->column <= 0)
        return (error("ERROR\n", game));
    if (!check_map(game))
        return (error("ERROR\n", game));
    return (0);
}