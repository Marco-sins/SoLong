/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:37:08 by mmembril          #+#    #+#             */
/*   Updated: 2024/12/26 13:51:18 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_count_exit(char **map)
{
    int i;
    int j;
    int exit;

    i = 0;
    exit = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'E')
                exit++;
            j++;
        }
        i++;
    }
    if (exit != 1)
        error (" en cantidad de salidas");
    return (1);
}

int ft_count_player(char **map)
{
    int i;
    int j;
    int player;

    i = 0;
    player = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                player++;
            j++;
        }
        i++;
    }
    if (player != 1)
        error (" en cantidad de jugadores");
    return (1);
}

int ft_count_coin(char **map)
{
    int i;
    int j;
    int coin;

    i = 0;
    coin = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C')
                coin++;
            j++;
        }
        i++;
    }
    if (coin < 1)
        error (" en cantidad de coleccionables");
    return (1);
}

int check_map(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != 'C' || map[i][j] != 'E' || map[i][j] != '1' || map[i][j] != '0' || map[i][j] != 'P')
                error(" en un caracter invalido");
            j++;
        }
        i++;
    }
    return (1);
}

int ft_walls_map(char **map, int rows, int columns)
{
    int i;
    int j;
    
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (j == 0 || j == columns - 1 || i == 0 || i == rows - 1)
            {
                if (map[i][j] != 1)
                    error(", no esta encerrado entre paredes");
            }
            j++;
        }
        i++;
    }
    return (1);
}
