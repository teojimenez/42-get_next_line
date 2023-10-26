/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:27:07 by teojimen          #+#    #+#             */
/*   Updated: 2023/10/24 12:27:07 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef get_next_line.h
# define GET_NEXT_LINE_FT

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif


char *get_next_line(int fd);

#endif