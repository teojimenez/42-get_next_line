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

char * xtraFunction(char **storage)
{
	char *result;
	int i;
	
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
	if (len > 0)
	{
		*(storage) = ft_substr(*(storage), i, len);
		if (!storage)
			return (free_str(storage));
	}
	else
		*(storage) = NULL;
	return result;
}

void ft_read_real(char **storage, int bytes_read, int fd)
{
	char *buffer = NULL;
	buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer[0] = '\0';
	bytes_read = 1;
	while((!*(storage) && bytes_read > 0) || ((*(storage) && !ft_strchr(*(storage), '\n')) && bytes_read > 0)) //working (MINE)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			*(storage) = ft_strjoin(*(storage), buffer);
			if (!storage)
			{
				return(free(buffer));
			}
		}
	}
	free(buffer);
	if (bytes_read == -1)
		free_str(storage);
}

char *get_next_line(int fd)
{
    static char *storage = NULL;
	size_t bytes_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,0,0) < 0) //read() -> no leas nada, deberia salir 0, si sale menor que 0 es que hay un error
	{
		free(storage);
		return (NULL);
	}
	if (!storage || (storage && !ft_strchr(storage, '\n'))) //caso storage primera iteracion, y storage tiene contenido pero no es barra \n, y ultimo donde bytes read es 0
		ft_read_real(&storage, bytes_read, fd);
	if (!storage) //caso line empty
	{
		storage = NULL;
		return (NULL);
	}
	if (storage && ft_strchr(storage, '\n')) //caso hay \n en storage y hay que leer storage y devolver
	{
		return (xtraFunction(&storage));
	}
    if (storage) //caso last line ('\0')
    {
        char *result = ft_strdup(storage);
        free_str(&storage);
		return result;
    }
	return (NULL);
}


// int	main(void)
// {
// 	int		file_descriptor;
// 	char	*result;

// 	file_descriptor = open("tests/test1.txt", O_RDONLY);
// 	if (file_descriptor == -1)
// 		return (0);
// 	result = get_next_line(file_descriptor);
// 	if (result == NULL)
// 		return (0);
// 	while (result != NULL)
// 	{
// 		printf("%s", result);
// 		free(result);
// 		result = NULL;
// 		result = get_next_line(file_descriptor);
// 		if (result == NULL)
// 			return (0);
// 	}
// 	free(result);
// 	result = NULL;
// 	return (0);
// }