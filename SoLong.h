/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:00:00 by mmembril          #+#    #+#             */
/*   Updated: 2024/12/18 12:33:06 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

#include "libft/includes/libft.h"


typedef struct  pj
{
    int x;
    int y;
    int n_collection;
}   pj;

typedef struct map_t
{
    int x;
    int y;
    int size_x;
    int size_y;
    int valid;
}   map;



#endif