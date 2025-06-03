/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:00:00 by mmembril          #+#    #+#             */
/*   Updated: 2025/06/03 19:04:59 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "minilibx-linux/mlx.h"
# include "libft/includes/libft.h"
# include "gnl/get_next_line.h"
# include <unistd.h>
# include <stdio.h>

# define TRUE   1
# define FALSE  0
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define IMG_WIDTH      64
# define IMG_HEIGHT     64

typedef struct s_map
{
    char    **str_map;
    int     row;
    int     column;
    int     coin;
    int     exit_row;
    int     exit_column;
    int     mov;
    t_player    player;  
}   t_map;

typedef struct s_player
{
    int x;
    int y;
}   t_player;

typedef struct s_image
{
    void    *coin;
    void    *exit;
    void    *floor;
    void    *player;
    void    *wall;
}   t_image;

typedef struct s_game
{
    t_map   map;
    void    *mlx;
}   t_game;


#endif