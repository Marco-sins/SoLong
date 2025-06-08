/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:00:00 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/06 19:56:49 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/includes/libft.h"
# include "gnl/get_next_line.h"
# include <unistd.h>
# include <stdio.h>

# define TRUE   1
# define FALSE  0
# define IMG_WIDTH      64
# define IMG_HEIGHT     64

typedef struct s_image
{
    mlx_image_t    *i_coin;
    mlx_texture_t   *t_coin;
    mlx_image_t    *i_exit;
    mlx_texture_t   *t_exit;
    mlx_image_t    *i_floor;
    mlx_texture_t   *t_floor;
    mlx_image_t    *i_player;
    mlx_texture_t   *t_player;
    mlx_image_t    *i_wall;
    mlx_texture_t   *t_wall;    
}   t_image;

typedef struct s_map
{
    char    **str_map;
    int     row;
    int     column;
    int     coin;
    int     exit_row;
    int     exit_column;
    int     mov;
    int     x_player;
    int     y_player;
    t_image *image;
}   t_map;

typedef struct s_game
{
    t_map   *map;
    void    *mlx;
}   t_game;

t_game  *init_game();
int	check_name(char *name);
void    load_images(t_game *game);
void    set_map_images(t_game *game);
void    ft_map(char *name_file, t_game *game);
char **ft_mount_map(char *name_file, int rows);
int ft_check_column(char **map, int cant_rows);
int ft_count_rows(char **map);

#endif