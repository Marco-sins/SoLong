/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:57:32 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/29 13:39:25 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

void    ft_free(t_game *game)
{
    ft_free_map(game->map->str_map);
    clear_img(game);
    free(game);
}

void    ft_free_map(char **str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

int error(const char *str, t_game *game)
{
    ft_printf("%s\n", str);
    ft_free(game);
    return (1);
}
