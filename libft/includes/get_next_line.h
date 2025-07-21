/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:25:49 by marco             #+#    #+#             */
/*   Updated: 2025/07/21 17:09:42 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strchr_gnl(char *s, int c);
size_t	ft_strlen_gnl(char *str);
void	*ft_calloc_gnl(size_t nmemb, size_t size);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_next(char *buffer);
char	*ft_line(char *buffer);
char	*ft_free_join(char *gnl_buf, char *buf);
char	*read_file(int fd, char *gnl_buf);
char	*ft_strdup_gnl(const char *s1);
char	*read_and_append(int fd, char *gnl_buf, char *buffer);

#endif