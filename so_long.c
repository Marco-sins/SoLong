/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:48:54 by mmembril          #+#    #+#             */
/*   Updated: 2025/07/21 18:21:16 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_images(t_game *game)
{
	game->map->image = malloc(sizeof(t_image));
	if (!game->map->image)
		return (1);
	game->map->image->i_coin = NULL;
	game->map->image->i_exit = NULL;
	game->map->image->i_floor = NULL;
	game->map->image->i_player = NULL;
	game->map->image->i_wall = NULL;
	game->map->image->t_coin = NULL;
	game->map->image->t_exit = NULL;
	game->map->image->t_floor = NULL;
	game->map->image->t_coin = NULL;
	game->map->image->t_player = NULL;
	return (0);
}

static t_game	*init_game(void)
{
	t_game	*game;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->x_player = 0;
	map->y_player = 0;
	map->coin = 0;
	map->column = 0;
	map->y_exit = 0;
	map->x_exit = 0;
	map->mov = 0;
	map->row = 0;
	map->str_map = NULL;
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (free(map), NULL);
	game->map = map;
	game->moves = 0;
	if (init_images(game))
		return (NULL);
	return (game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (ft_printf("ERROR\n"), 1);
	else if (!check_name(av[1]))
		return (ft_printf("ERROR\n"), 1);
	game = init_game();
	if (ft_map(av[1], game))
		return (1);
	game->mlx = mlx_init(64 * game->map->column, 64 * game->map->row, "SoLong",
			FALSE);
	if (!game->mlx)
		return (ft_free(game), 1);
	if (load_images(game) || set_map_images(game))
		return (ft_free_all(game), 1);
	mlx_key_hook(game->mlx, &move_player, game);
	mlx_loop(game->mlx);
	ft_free_all(game);
	return (0);
}
