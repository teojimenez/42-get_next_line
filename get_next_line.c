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

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"  

//function para la lectura
//function obtener la string hasta newline
//lo que sobre almacenarlo en la estatica (limpiar)

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;
	int	size;

	size = ft_strlen(str);
	i = 0;
	while (i <= size)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	* result;
	if (!s1)
	{
		s1 = (char *)malloc(1);
		if(!s1)
		{
			free(s1);
			return NULL;
		}
		s1[0] = '\0';
	}
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)  * sizeof(char));
    // str[ft_strlen(s1) + ft_strlen(s2) + 1] = '\0';
	if (!str)
		return (0);
	result = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
    *str = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	// if (start > (unsigned int)ft_strlen(s))
	// 	return (ft_strdup(""));
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = malloc(len + 1 * sizeof(char));
	sub[len + 1] = '\0';
	if(!sub)
	{
		free(sub);
		return NULL;
	}
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';	
	return ((char *)sub);
}

void xtraFunction(char **storage, char *buffer, char **result)
{
		int i = 0;
		//tamaño de result, desde storage
		while ((*storage)[i] != '\n')
			i++;
		i++;
		*(result) = (char *)malloc((i + 1) * sizeof(char));
		if(!(*result))
		{
			free(*result);
			return ;
		}
		int j = 0;
		//rellenar result con storage
		while (j < i)
		{
			(*result)[j] = (*storage)[j];
			j++;
		}
		(*result)[j] = '\0';
		// ---------------------------------------------
		// ----- Rellenar storage con lo sobrante ------
		// aqui result rellenado entero
		// no necesitamos storage a no ser que haya algo en buffer despues del \n
		
		// i = 0;
		// if (buffer[i] != '\n' && buffer[i] != '\0')
		// {
		// 	while (buffer[i] != '\n' && buffer[i] != '\n')
		// 		i++;
		// 	i++;
		// }
		//storage debe ser storage pero sin lo de buffer
		// free(*storage);
		// (*storage) = 0;
		int buff_len = ft_strlen(buffer);

		//caso en que hay mas cosas despues del buffer
		// if (buff_len > i)
		int len = ft_strlen(*(storage)) - i;
		*(storage) = ft_substr(*(storage), i, len);
}

char	*ft_strdup(const char *s1)
{
	char	*memory;
	int		i;

	i = -1;
	memory = (char *)malloc(ft_strlen(s1) + 1);
	if(!memory)
	{
		free(memory);
		return NULL;
	}
	while (s1[++i])
		memory[i] = s1[i];
	memory[i] = '\0';
	return (memory);
}

char *ft_read(char *storage)
{
	/*
	CREO UN BUFFER Y LEO LA CANTIDAD QUE ME DAN DEL BUFFER SIZE
	N VECES HASTA QUE TENGA UN BARRA N COMO MINIMO EN EL BUFFER
	READ()
	*/
}

/*
	hola como 
	estas
	soy
*/

char *get_next_line(int fd)
{
    static char *storage = NULL;
    char *buffer;
	char *result;
	size_t bytes_read = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage || (storage && !ft_strchr(storage, '\n'))) //caso storage primera iteracion, y storage tiene contenido pero no es barra \n
		storage = ft_read();//read()
	if (!storage)
		return (NULL);
	//siempre lees del storage pero no nunca lo llenas
	//funcion  
	// ex

    buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(storage);
		return (NULL);
	}
	
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(storage);
		return NULL;
	}
	buffer[bytes_read] = '\0';
	storage = ft_strjoin(storage, buffer);
	if (ft_strchr(storage, '\n'))
		xtraFunction(&storage, buffer, &result);

	//cuando queremos leer?????
	while(!ft_strchr(buffer, '\n') && bytes_read > 0) 
	{
        
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		// -------------- Rellenar/Actualizar store -------------
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
        // -------------------------------------------
		if (bytes_read == 0)
		{
			result = ft_strdup(storage);
			break;
			//free(*storage);
			//*storage = NULL;
		}
		else if(ft_strchr(storage, '\n')) //
			xtraFunction(&storage, buffer, &result);
	}
    free(buffer);
	return (result);
}

// char *get_next_line(int fd)
// {
//     static char *storage = NULL;
//     char buffer[BUFFER_SIZE];
// 	char *result;
// 	size_t bytes_read = 0;

// 	bytes_read = read(fd, buffer, BUFFER_SIZE);
// 	if (bytes_read < 0)
// 	{
// 		free(storage);
// 		return NULL;
// 	}
// 	buffer[bytes_read] = '\0';
// 	if (bytes_read == 0)
// 		return NULL;
// 	storage = ft_strjoin(storage, buffer);
// 	if(!storage)
// 	{
// 		free(storage);
// 		return NULL;
// 	}
// 	if (ft_strchr(storage, '\n'))
// 		xtraFunction(&storage, buffer, &result);

// 	while(!ft_strchr(buffer, '\n')) 
// 	{
//         bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read < 0)
// 		{
// 			free(storage);
// 			return NULL;
// 		}
// 		buffer[bytes_read] = '\0';
// 		// -------------- Rellenar/Actualizar store -------------
// 		storage = ft_strjoin(storage, buffer);
// 		if(!storage)
// 		{
// 			free(storage);
// 			return NULL;
// 		}
//         // -------------------------------------------
// 		if (bytes_read == 0)
// 		{
// 			result = ft_strdup(storage);
// 			if(!result)
// 			{
// 				free(result);
// 				return NULL;
// 			}
// 			break;
// 			//free(*storage);
// 			//*storage = NULL;
// 		}
// 		else if(ft_strchr(storage, '\n')) //
// 			xtraFunction(&storage, buffer, &result);
// 	}
//     return (result);
// }


// int main(void)
// {
//     char path[] = "file.txt";
//     int fd = open(path, O_RDONLY);
//     char	*str;
// 	// printf("%s", get_next_line(fd));
//     str = get_next_line(fd);
// 	printf("%s\n", str);
// 	free(str);
// 	// str = get_next_line(fd);
// 	// printf("%s\n", str);
// 	// free(str);

// 	//get_next_line(fd);
// }

int main()
{
    int fd = open("file.txt", O_RDONLY);
    if (fd < 0)
        return (0);
	char	*str;
	int i = 0;
	while(i < 50)
	{
		str = get_next_line(fd);
        if (!str)
            break;
        printf("%s", str);
        free(str);
        i++;
	}
	close(fd);
    return 0;
    // while (s != NULL)
    // {
    //     printf("%s", s);
    //     free(s);
    //     s = get_next_line(fd);
	// }	
}