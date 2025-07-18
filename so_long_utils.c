/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:13:48 by mmembril          #+#    #+#             */
/*   Updated: 2025/07/17 19:05:51 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *name)
{
	int	i;

	i = ft_strlen(name);
	i -= 1;
	if (name[i] != 'r' || name[i - 1] != 'e' || name[i - 2] != 'b' || name[i
			- 3] != '.')
		return (FALSE);
	return (TRUE);
}
