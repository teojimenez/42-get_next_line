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
	i++;
	result = 0;
	result = (char *)malloc((i + 1) * sizeof(char));
	if(!result)
		return free_str(storage);
	int j = 0;
	while (j < i)
	{
		result[j] = (*storage)[j];
		j++;
	}
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


void ft_read_real(char **storage, int bytes_read, int fd)
{
	char *buffer = NULL;
	// char *result = NULL;

	buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// if (!buffer)
	// {

	// 	// free_str(storage);
	// 	free(*(storage));
	// 	return ;
	// }
	buffer[0] = '\0';
	bytes_read = 1;
	// while(!ft_strchr(*(storage), '\n') && bytes_read > 0) //brayan one
	// while (!*(storage) || (bytes_read > 0 && !ft_strchr(*(storage), '\n'))) //gpt
	// while (bytes_read > 0 && !ft_strchr(*(storage), '\n'))
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
				// free_str(&buffer);
			}
		}
		
	}
	free(buffer);

	if (bytes_read == 0 && *(storage) != NULL)
    {
        // Return the content of storage if the file is empty
        return;
    }

	if (bytes_read == -1)
		free_str(storage);
	// {
	// 	return (xtraFunction(storage));
		// if (!*(storage))
		// {
		// 	*(result) = ft_strdup("");
		// 	if(!*(result))
		// 		free_str(storage);
		// }
		// else
		// {
			// *(result) = ft_strdup(*(storage));
			// if(!*(result))
			// 	free_str(storage);

		// }
	// }
	// return (result);
}

char *get_next_line(int fd)
{
    static char *storage = NULL;
    // char *buffer = NULL;
	// char *result = NULL;
	size_t bytes_read = 0;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,0,0) < 0) //read() -> no leas nada, deberia salir 0, si sale menor que 0 es que hay un error
	{
		free(storage);
		return (NULL);
	}
	 
	if (!storage || (storage && !ft_strchr(storage, '\n'))) //caso storage primera iteracion, y storage tiene contenido pero no es barra \n, y ultimo donde bytes read es 0
		ft_read_real(&storage, bytes_read, fd);
	if (!storage)
		return (NULL);
	// if (!storage)
    //     return (free_str(&buffer));
	if (storage && ft_strchr(storage, '\n')) //caso hay \n en storage y hay que leer storage y devolver
		return (xtraFunction(&storage));
	// if (storage && bytes_read == 0)
	// {
	// 	return ft_strdup(storage);
	// }
	// free(buffer);
	// if(!result)
	// 	return (free_str(&storage));

	if (storage)
    {
        char *result = ft_strdup(storage);
        free(storage);
        storage = NULL;
        return result;
    }
	return (NULL);
}

// int main()
// {
//     int fd = open("tests/test1.txt", O_RDONLY);
//     if (fd < 0)
//         return (0);
// 	char	*str;
// 	int i = 0;
// 	while(i < 2)
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

int	main(void)
{
	int		file_descriptor;
	char	*result;

	file_descriptor = open("tests/test1.txt", O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	result = get_next_line(file_descriptor);
	if (result == NULL)
		return (0);
	while (result != NULL)
	{
		printf("%s", result);
		free(result);
		result = NULL;
		result = get_next_line(file_descriptor);
		if (result == NULL)
			return (0);
	}
	free(result);
	result = NULL;
	return (0);
}