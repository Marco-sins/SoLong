/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:13:48 by mmembril          #+#    #+#             */
/*   Updated: 2024/12/30 19:15:07 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

int	check_name(char *name)
{
	int i;

	i = ft_strlen(name);
	if (name[i - 1] != 'r' || name[i - 2] != 'e' || name[i - 3] != 'b' || name[i
		- 4] != '.')
		return (0);
	return (1);
}