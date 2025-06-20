/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:57:32 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/14 11:12:58 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

int error(const char *str, t_game *game)
{
    ft_printf("Error: %s\n", str);
    ft_free(game);
    return (1);
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