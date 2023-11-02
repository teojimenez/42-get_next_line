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

int	ft_strlen(const char *str)
{
	int	i;

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
		if (!s1)
			return (0);//NULL
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
	if (!sub)
		return (0);
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';	
	return ((char *)sub);
}

void xtraFunction(char **storage, char **buffer, char **result)
{
	
	
	// if(ft_strchr(storage, '\n'))
	// {
		// -------------- Rellenar result -------------
		int i = 0;
		while ((*storage)[i] != '\n')
			i++;
		i++;
		*(result) = (char *)malloc((i + 1) * sizeof(char));
		int j = 0;
		while(j < i)
		{
			(*result)[j] = (*storage)[j];
			j++;
		}
		*(result[j]) = '\0';
		// ---------------------------------------------
		// ----- Rellenar storage con lo sobrante ------
		while(*(buffer[i]) != '\0')
			i++;
		
		(*storage) = 0;
		int ft_len = ft_strlen(*(buffer));

		int first = 0;
		while(*(buffer[first]) != '\n')
			first++;
		first++;
		*(storage) = ft_substr(*(buffer), first, ft_len - 1);
		ft_len = 3;
	// }
	// else //no se ha leido lo suficiente y hace falta volver a hacer read
	// {
		
	// }
}

char *get_next_line(int fd)
{
    static char *storage = NULL;
    char *buffer;
	char *result;
    buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));

	//cuando queremos leer?????
	while(!ft_strchr(buffer, '\n'))
	{
        read(fd, buffer, BUFFER_SIZE);
        // -------------- Rellenar store -------------
        storage = ft_strjoin(storage, buffer);
        // -------------------------------------------
		if(ft_strchr(storage, '\n'))
		{
			xtraFunction(&storage, &buffer, &result);
		}
	}
	// if(ft_strchr(storage, '\n'))
	// {
	// 	// -------------- Rellenar result -------------
	// 	int i = 0;
	// 	while (buffer[i] != '\n')
	// 		i++;
	// 	i++;
	// 	result = (char *)malloc((i + 1) * sizeof(char));
	// 	int j = 0;
	// 	while(j < i)
	// 	{
	// 		result[j] = buffer[j];
	// 		j++;
	// 	}
	// 	result[j] = '\0';
	// 	// ---------------------------------------------
	// 	// ----- Rellenar storage con lo sobrante ------
	// 	while(buffer[i] != '\0')
	// 		i++;
	// 	storage = 0;
	// 	int ft_len = i - j;
	// 	storage = ft_substr(buffer, i, ft_len);
	// }
	// else //no se ha leido lo suficiente y hace falta volver a hacer read


    // if(read == -1)
        //error liberar buffer y todo lo usado
    return (result);
}


int main(void)
{
    char path[] = "file.txt";
    int fd = open(path, O_RDONLY);
    // printf("%s", get_next_line(fd));
    get_next_line(fd);
}