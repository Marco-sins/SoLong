/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:51:49 by mmembril          #+#    #+#             */
/*   Updated: 2025/07/17 19:06:12 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	else if (map[y][x] == 'C' || map[y][x] == 'P' || map[y][x] == 'E'
		|| map[y][x] == '0')
		map[y][x] = 'F';
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
}

static char	**copy_map(char **map, int rows)
{
	char	**map_copy;
	int		i;

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

static void	get_pos_player(char **map, int *y, int *x)
{
	int	i;
	int	j;

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

static int	ft_is_close_map(char **map, int rows, int columns)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		if (i == 0 || i == rows - 1)
		{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] != '1')
					return (FALSE);
				j++;
			}
		}
		else if (map[i][0] != '1' || map[i][columns - 1] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_valid_map(char **map, int rows, int columns)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	**cpy_map;

	i = 0;
	if (!ft_is_close_map(map, rows, columns))
		return (FALSE);
	cpy_map = copy_map(map, rows);
	get_pos_player(cpy_map, &y, &x);
	flood_fill(cpy_map, y, x);
	while (cpy_map[i] != NULL)
	{
		j = 0;
		while (cpy_map[i][j] != '\0')
		{
			if (cpy_map[i][j] != '1' && cpy_map[i][j] != 'F'
				&& cpy_map[i][j] != '0')
				return (ft_free_map(cpy_map), FALSE);
			j++;
		}
		i++;
	}
	return (ft_free_map(cpy_map), TRUE);
}
