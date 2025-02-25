/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:48:54 by mmembril          #+#    #+#             */
/*   Updated: 2024/12/30 19:14:03 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

int main(int ac, char **av)
{
    t_map *map;

    if ((ac =! 2) || !check_name(av[1]))
        error(" en el nombre del archivo");
    map = malloc(sizeof(t_map) + 1);
    if (!map)
        error (" en la reserva de memoria");
    ft_map(av[1], map);
}