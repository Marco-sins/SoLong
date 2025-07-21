/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:25:38 by marco             #+#    #+#             */
/*   Updated: 2025/07/21 17:10:20 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strchr_gnl(char *s, int c)
{
	char	a;

	a = (char)c;
	while (*s)
	{
		if (*s == a)
			return (s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	if (!nmemb || !size)
		return (NULL);
	str = malloc((nmemb * size));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	s1_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	s1_len = ft_strlen_gnl(s1);
	str = malloc(((s1_len + ft_strlen_gnl(s2)) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = ft_strlen_gnl((char *)s1);
	copy = malloc(len + 1);
	if (copy == NULL)
	{
		free(copy);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[len] = '\0';
	return (copy);
}
