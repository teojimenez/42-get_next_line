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
Hola sy
soy una persona
hola

//function para la lectura
//function obtener la string hasta newline
//lo que sobre almacenarlo en la estatica (limpiar)

char *get_next_line(int fd)
{
    static char *store = NULL;
    char *buff;
    buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    
    while(!strchr(buf) y mientras read > 0)
    {

        read(fd, buff, BUFFER_SIZE);
    }
    if(read == -1)
        //error liberar buffer y todo lo usado
}

int main(void)
{
    char path[] = "file.txt";
    int fd = open(path, O_RDONLY);

}