/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:38:48 by teojimen          #+#    #+#             */
/*   Updated: 2023/12/01 10:38:48 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;
	int	size;

	if (!str)
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_str;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (free_str(&s1));
	i = -1;
	j = 0;
	while (s1[++i])
		new_str[i] = s1[i];
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(len + 1 * sizeof(char));
	if (!sub)
	{
		free (s);
		return (NULL);
	}
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';
	free(s);
	return ((char *)sub);
}

char	*ft_strdup(const char *s1)
{
	char	*memory;
	int		i;

	i = -1;
	memory = (char *)malloc(ft_strlen(s1) + 1);
	if (!memory)
	{
		free(memory);
		return (NULL);
	}
	while (s1[++i])
		memory[i] = s1[i];
	memory[i] = '\0';
	return (memory);
}
