/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:57:32 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/03 19:18:12 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

void    error(const char *str, t_game *game)
{
    ft_printf("Error: %s\n", str);
    ft_free(game);
    exit(EXIT_FAILURE);
}

void    ft_free(t_game *game)
{
    int i;
    
    i = 0;
    while (game->map.str_map[i])
    {
        free(game->map.str_map[i]);
        i++;
    }
    free(game->map.str_map);
}