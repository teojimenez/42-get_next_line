/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:27:12 by teojimen          #+#    #+#             */
/*   Updated: 2023/10/24 12:27:12 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

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
	return (NULL);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*str;
// 	char	* result;
// 	if (!s1)
// 	{
// 		s1 = (char *)malloc(1); //new
// 		s1[0] = '\0';
// 		if(!s1)
// 			return (0);
// 		// return (ft_free(&s1));
// 	}
// 	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)  * sizeof(char));
// 	if (!str)
// 		return (free_str(&s1)); //new
// 	result = str;
// 	while (*s1)
// 		*str++ = *s1++;
// 	while (*s2)
// 		*str++ = *s2++;
//     *str = '\0';
// 	free(s1); //peta da Abort
// 	return (result);
// }

static char	*get_strjoin(char *s1, char *s2, size_t len_s1, size_t len_s2)
{
	int		i;
	int		j;
	char	*new_str;

	new_str = (char *)malloc(len_s1 + len_s2 + 1);
	if (!new_str)
		return (free_str(&s1));
	i = -1;
	j = 0;
	while (s1[++i])
		new_str[i] = s1[i];
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[len_s1 + len_s2] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	return (get_strjoin(s1, s2, len_s1, len_s2));
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = malloc(len + 1 * sizeof(char));
	if(!sub)
	{
		free(sub);
		return NULL;
	}
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';	
	free((char *)s);
	return ((char *)sub);
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