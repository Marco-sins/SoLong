/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:27:38 by mmembril          #+#    #+#             */
/*   Updated: 2025/07/21 17:29:25 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count_rows(char *map_name)
{
	int		fd;
	int		i;
	char	*read_line;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	read_line = get_next_line(fd);
	while (read_line)
	{
		free(read_line);
		read_line = get_next_line(fd);
		i++;
	}
	free(read_line);
	close(fd);
	return (i);
}

static int	ft_check_column(char **map, int cant_rows)
{
	int		i;
	size_t	j;
	size_t	y;

	j = ft_strlen(map[0]);
	i = 1;
	if (map[0][j - 1] == '\n')
		j--;
	while (i < cant_rows)
	{
		y = ft_strlen(map[i]);
		if (map[i][y - 1] == '\n')
			y--;
		if (j != y)
			return (0);
		i++;
	}
	return (j);
}

static char	**ft_mount_map(char *name_file, int rows)
{
	int		fd;
	int		i;
	char	**map;

	fd = open(name_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = (char **)ft_calloc(sizeof(char *), rows + 1);
	i = 0;
	while (rows > 0)
	{
		map[i] = get_next_line(fd);
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		rows--;
		i++;
	}
	get_next_line(-1);
	close(fd);
	map[i] = NULL;
	return (map);
}

int	ft_map(char *name_file, t_game *game)
{
	game->map->row = ft_count_rows(name_file);
	if (game->map->row == -1)
		return (error("ERROR", game), 1);
	game->map->str_map = ft_mount_map(name_file, game->map->row);
	if (!game->map->str_map)
		return (error("ERROR", game));
	game->map->column = ft_check_column(game->map->str_map, game->map->row);
	if (game->map->column == 0)
		return (error("ERROR", game));
	if (!check_map(game))
		return (error("ERROR", game));
	return (0);
}
