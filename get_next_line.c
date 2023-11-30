/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:26:39 by teojimen          #+#    #+#             */
/*   Updated: 2023/10/24 12:26:39 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_str(char **str)
{
	free(*str);
	(*str) = NULL;
	return (NULL);
}
#include <stdio.h>

char * xtraFunction(char **storage)
{
	
	char *result = NULL;
	int i;
	
	if (*storage && !ft_strchr(*storage, '\n')) //caso hay \0
	{
        result = ft_strdup(*storage);
        free_str(storage);
		return result;
    }
	i = 0;
	while ((*storage)[i] != '\n')
		i++;
	result = (char *)malloc((++i + 1) * sizeof(char));
	if(!result)
		return free_str(storage);
	int j = -1;
	while (++j < i)
		result[j] = (*storage)[j];
	result[j] = '\0';
	int len = ft_strlen(*(storage)) - i;
	// if (len > 0)
	// {
		if (len <= 0 && ft_strlen(*(storage)) > 0) //AQUI !!!!!!
		{
			free(*storage);
			*(storage) = NULL;
			//printf("LEN: %i, STORAGE: %s", len, *(storage));
			//free(storage);
		}
		else if(len > 0)
		{
			*(storage) = ft_substr(*(storage), i, len);
			if (!storage)
				return free_str(storage);

		}
	return result;
}


char *ft_read_real(char *storage, int fd)
{
	char *buffer = NULL;
	int bytes_read;
	buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return free_str(&storage);
	// buffer[0] = '\0';
	bytes_read = 1;
	
	while((!storage && bytes_read > 0) || ((storage && !ft_strchr(storage, '\n')) && bytes_read > 0)) //working (MINE)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			storage = ft_strjoin(storage, buffer);
			if (!storage)
				return(free_str(&buffer));
		}
	}
	if (bytes_read == -1)
		free_str(&storage);
	free(buffer);
	return storage;
}

char *get_next_line(int fd)
{
    static char *storage = NULL;
	char *line;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,0,0) < 0) //read() -> no leas nada, deberia salir 0, si sale menor que 0 es que hay un error
	{
		free(storage);
		return (NULL);
	}
	storage = ft_read_real(storage, fd);
	if (!storage) //caso line empty
		return (storage = NULL);

	line = xtraFunction(&storage);
	if (!line)
		return (free_str(&storage));
	return (line);
}