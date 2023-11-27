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

char	*ft_free(char **str)
{
	free(*str);
	(*str) = NULL;
	return (NULL);
}

void xtraFunction(char **storage, char **result)
{
		int i;
		
		i = 0;
		while ((*storage)[i] != '\n')
			i++;
		i++;
		*result = 0;
		*(result) = (char *)malloc((i + 1) * sizeof(char));
		if(!(*result))
		{
			return ;
		}
		int j = 0;
		while (j < i)
		{
			(*result)[j] = (*storage)[j];
			j++;
		}
		(*result)[j] = '\0';
		int len = ft_strlen(*(storage)) - i;
		if (len > 0)
		{
			*(storage) = ft_substr(*(storage), i, len);
			if (!storage)
				ft_free(storage);
		}
		else
			*(storage) = "";
}

// void ft_read_storage(char **storage, char *buffer, char **result)
// {
// 	while(!ft_strchr(buffer, '\n') && bytes_read > 0) 
// 	{
        
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		// -------------- Rellenar/Actualizar store -------------
// 		buffer[bytes_read] = '\0';
// 		storage = ft_strjoin(storage, buffer);
//         // -------------------------------------------
// 		if (bytes_read == 0)
// 		{
// 			result = ft_strdup(storage);
// 			break;
// 			//free(*storage);
// 			//*storage = NULL;
// 		}
// 		else if(ft_strchr(storage, '\n')) //
// 			xtraFunction(&storage, buffer, &result);
// 	}
// }


char *ft_read_real(char **storage, char *buffer, int bytes_read, int fd, char **result)
{
	buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return  (ft_free(storage));
	buffer[0] = '\0';
	bytes_read = 1;
	while(!*(storage) || ((*(storage) && !ft_strchr(*(storage), '\n')) && bytes_read > 0))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';

		*(storage) = ft_strjoin(*(storage), buffer);
		if (!storage)
			return (ft_free(storage));
		// -------------------------------------------
		if(ft_strchr(*(storage), '\n')) //
		{
			xtraFunction(storage, result);
			break;
		}
	}
	// if (bytes_read == 0)
	// {
	// 	*(result) = ft_strdup(*(storage));
	// }
	if (bytes_read == 0)
	{
		if (!*(storage))
		{
			*(result) = ft_strdup("");
			if(!*(result))
				ft_free(storage);
		}
		else
		{
			*(result) = ft_strdup(*(storage));
			if(!*(result))
				ft_free(storage);

		}
	}

	return *(result);
}

char *get_next_line(int fd)
{
    static char *storage = NULL;
    char *buffer = NULL;
	char *result = NULL;
	size_t bytes_read = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	if (!storage || (storage && !ft_strchr(storage, '\n'))) //caso storage primera iteracion, y storage tiene contenido pero no es barra \n, y ultimo donde bytes read es 0
		ft_read_real(&storage, buffer, bytes_read, fd, &result);
	if (!storage)
        return (ft_free(&buffer));
	if (storage && ft_strchr(storage, '\n')) //caso hay \n en storage y hay que leer storage y devolver
	{
		xtraFunction(&storage, &result);
	}

	return (result);
}

// int main()
// {
//     int fd = open("tests/big-scrolling.txt", O_RDONLY);
//     if (fd < 0)
//         return (0);
// 	char	*str;
// 	int i = 0;
// 	while(i < 4490)
// 	{
// 		str = get_next_line(fd);
//         if (!str)
//             break;
//         printf("%s", str);
//         free(str);
//         i++;
// 	}
// 	close(fd);
//     return 0;
// }