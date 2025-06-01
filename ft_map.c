/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:27:38 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/01 20:27:51 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

int ft_count_rows(char *name_file)
{
    int fd;
    int i;
    char *line;
    char *aux;

    fd = open(name_file, O_RDONLY);
    if (fd < 0)
        error ("Can't open the file");
    i = -1;
    line = ".";
    while (line)
    {
        aux = line;
        line = get_next_line(fd);
        free (aux);
        i++;
    }
    free (line);
    close (fd);
    if (i < 3)
        error ("Invalid map size");
    return (i);
}

int ft_check_column(char *name_file, int cant_rows)
{
    int fd;
    int i;
    char *line;
    char *aux;

    fd = open(name_file, O_RDONLY);
    if (fd < 0)
        error ("Can't open the file");
    line = get_next_line(fd);
    i = ft_strlen(line);
    if (i < 3)
        error ("Invaldid map size");
    cant_rows--;
    while (cant_rows > 0)
    {
        aux = line;
        line = get_next_line(fd);
        free (aux);
        if (ft_strlen(line) != i)
            error("Invalid map size");
        cant_rows--;
    }
    free (line);
    close (fd);
    return (i);
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

char **ft_map(char *name_file, t_game *game)
{
    char **map;
    t_map *maps;

    maps->row = ft_count_rows(name_file);
    maps->column = ft_check_column(name_file, maps->row);
    map = ft_mount_map(name_file, maps->row);
    
}