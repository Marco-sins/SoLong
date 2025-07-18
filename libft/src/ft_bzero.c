/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:12:18 by mmembril          #+#    #+#             */
/*   Updated: 2024/11/09 14:14:06 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	int				i;

	i = 0;
	a = s;
	while (n > 0)
	{
		a[i] = '\0';
		i++;
		n--;
	}
	s = a;
}
