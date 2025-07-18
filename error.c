/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:57:32 by mmembril          #+#    #+#             */
/*   Updated: 2025/07/17 19:06:15 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all(t_game *game)
{
	clear_img(game);
	if (game->map->image)
		free(game->map->image);
	mlx_terminate((game->mlx));
	ft_free(game);
}

void	ft_free(t_game *game)
{
	ft_free_map(game->map->str_map);
	free(game->map);
	free(game);
}

void	ft_free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	error(const char *str, t_game *game)
{
	ft_printf("%s\n", str);
	ft_free(game);
	return (1);
}
