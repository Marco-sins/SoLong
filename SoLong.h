/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:00:00 by mmembril          #+#    #+#             */
/*   Updated: 2025/07/17 17:00:34 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define IMG_WIDTH 64
# define IMG_HEIGHT 64

typedef struct s_image
{
	mlx_image_t		*i_coin;
	mlx_texture_t	*t_coin;
	mlx_image_t		*i_exit;
	mlx_texture_t	*t_exit;
	mlx_image_t		*i_floor;
	mlx_texture_t	*t_floor;
	mlx_image_t		*i_player;
	mlx_texture_t	*t_player;
	mlx_image_t		*i_wall;
	mlx_texture_t	*t_wall;
}					t_image;

typedef struct s_map
{
	char			**str_map;
	int				row;
	int				column;
	int				coin;
	int				mov;
	int				x_player;
	int				y_player;
	int				x_exit;
	int				y_exit;
	t_image			*image;
}					t_map;

typedef struct s_game
{
	t_map			*map;
	int				moves;
	void			*mlx;
}					t_game;

int					error(const char *str, t_game *game);
void				move_player(mlx_key_data_t keydata, void *param);
int					ft_map(char *name_file, t_game *game);
int					check_map(t_game *game);
int					is_valid_map(char **map, int rows, int columns);
int					check_name(char *name);
int					load_images(t_game *game);
void				ft_free(t_game *game);
void				ft_free_all(t_game *game);
int					set_map_images(t_game *game);
void				ft_free_map(char **str);
void				clear_img(t_game *game);

#endif