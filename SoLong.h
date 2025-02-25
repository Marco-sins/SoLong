/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:00:00 by mmembril          #+#    #+#             */
/*   Updated: 2024/12/30 19:11:33 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/includes/libft.h"
# include "gnl/get_next_line.h"
# include <unistd.h>
# include <stdio.h>

# define MAP_WIDTH      7100
# define MAP_HEIGHT     7100
# define IMG_WIDTH      64
# define IMG_HEIGHT     64

typedef struct s_map
{
    char    **map;
    int     row;
    int     column;
    int     row_2;
    int     column_2;
    int     coin;
    int     exit_row;
    int     exit_column;
    int     mov;
    mlx_t   *mlx;    
}   t_map;

int ft_count_exit(char **map);
int ft_count_player(char **map);
int ft_count_coin(char **map);
int check_map(char **map);
int ft_walls_map(char **map, int rows, int columns);
int	check_name(char *name);
void error (char *str);
char **ft_map(char *name_file, t_map *maps);
char **ft_mount_map(char *name_file, int rows);
int ft_check_column(char *name_file, int cant_rows);
int ft_count_rows(char *name_file);

#endif