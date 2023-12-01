/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:38:35 by teojimen          #+#    #+#             */
/*   Updated: 2023/12/01 10:38:35 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_str(char **str)
{
	free(*str);
	(*str) = NULL;
	return (NULL);
}

int	ft_update_storage(int i, char **storage)
{
	int	len;

	len = ft_strlen(*(storage)) - i;
	if (len <= 0 && ft_strlen(*(storage)) > 0)
	{
		free(*storage);
		*(storage) = NULL;
	}
	else if (len > 0)
	{
		*(storage) = ft_substr(*(storage), i, len);
		if (!storage)
			return (-1);
	}
	return (0);
}

char	*ft_line(char **storage)
{
	char	*result;
	int		i;
	int		j;

	result = NULL;
	i = 0;
	j = -1;
	if (*storage && !ft_strchr(*storage, '\n'))
	{
		result = ft_strdup(*storage);
		free_str(storage);
		return (result);
	}
	while ((*storage)[i] != '\n')
		i++;
	result = (char *)malloc((++i + 1) * sizeof(char));
	if (!result)
		return (free_str(storage));
	while (++j < i)
		result[j] = (*storage)[j];
	result[j] = '\0';
	if (ft_update_storage(i, storage) == -1)
		return (free_str(storage));
	return (result);
}

char	*ft_read(char *storage, int fd)
{
	char	*buffer;
	int		b_read;

	buffer = NULL;
	b_read = 1;
	buffer = (char *)malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_str(&storage));
	while ((!storage || (storage && !ft_strchr(storage, '\n'))) && b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			free_str(&storage);
		if (b_read > 0)
		{
			buffer[b_read] = '\0';
			storage = ft_strjoin(storage, buffer);
			if (!storage)
				return (free_str(&buffer));
		}
	}
	free (buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[1025] = {NULL};
	char		*line;

	line = NULL;
	if ((fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
	{
		free(storage[fd]);
		return (NULL);
	}
	storage[fd] = ft_read(storage[fd], fd);
	if (!storage[fd])
		return (storage[fd] = NULL);
	line = ft_line(&storage[fd]);
	if (!line)
		return (free_str(&storage[fd]));
	return (line);
}
