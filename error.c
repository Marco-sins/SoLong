/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:57:32 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/06 19:27:25 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

void    error(const char *str, t_game *game)
{
    ft_printf("Error: %s\n", str);
    ft_free(game);
    exit(1);
}

void    ft_free(t_game *game)
{
    int i;
    
    i = 0;
    while (game->map->str_map[i])
    {
        free(game->map->str_map[i]);
        i++;
    }
    free(game->map->str_map);
}