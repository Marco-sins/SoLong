/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:00:00 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/29 13:39:01 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
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
    int moves;
    void    *mlx;
}   t_game;

int error(const char *str, t_game *game);
void    move_player(mlx_key_data_t keydata, void *param);
int ft_map(char *name_file, t_game *game);
int check_map(t_game *game);
int is_valid_map(char **map, int rows);
int	check_name(char *name);
int load_images(t_game *game);
void    ft_free(t_game *game);
int set_map_images(t_game *game);
void    ft_free_map(char **str);
void    clear_img(t_game *game);

#endif