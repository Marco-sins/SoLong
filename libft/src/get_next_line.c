/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:25:08 by marco             #+#    #+#             */
/*   Updated: 2025/07/21 17:11:03 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc_gnl((ft_strlen_gnl(buffer) - i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc_gnl(i + 2, sizeof(char));
	else
		line = ft_calloc_gnl(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_free_join(char *gnl_buf, char *buf)
{
	char	*join;

	if (!gnl_buf)
		return (ft_strdup_gnl(buf));
	join = ft_strjoin_gnl(gnl_buf, buf);
	free(gnl_buf);
	return (join);
}

char	*read_file(int fd, char *gnl_buf)
{
	char	*buffer;
	int		reading_bytes;

	buffer = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	reading_bytes = 1;
	while (reading_bytes > 0)
	{
		reading_bytes = read(fd, buffer, BUFFER_SIZE);
		if (reading_bytes < 0)
		{
			free(buffer);
			free(gnl_buf);
			return (NULL);
		}
		buffer[reading_bytes] = '\0';
		gnl_buf = ft_free_join(gnl_buf, buffer);
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (gnl_buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*row;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (fd <= 0 && buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	if (!buffer)
		buffer = ft_calloc_gnl(1, sizeof(char));
	if (!buffer)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	row = ft_line(buffer);
	buffer = ft_next(buffer);
	return (row);
}


//int main()
//{
//    int fd;
//	char *line;
//
//    fd = open("empty.txt", O_RDONLY);
//    if (fd == -1) 
//	{
//        printf("Error al abrir el archivo");
//        return (1);
//    }
//    for (int i = 0; i < 2; i++)
//    {
//		line = get_next_line(fd);
//        printf("[%i] %s", i + 1, line);
//		free (line);
//    }
//    // Realiza operaciones con el archivo (lectura/escritura)
//
//    close(fd); // Cerrar el archivo
//    return (0);
//}