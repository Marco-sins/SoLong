/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:48:54 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/01 20:24:19 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

int main(int ac, char **av)
{
    t_game *game;

    if ((ac =! 2) || !check_name(av[1]))
        error("Invalid map name");
    game = malloc(sizeof(t_game));
    if (!game)
        error ("Malloc error");
    ft_map(av[1], game);
}