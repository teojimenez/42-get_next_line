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

char *get_next_line(int fd)
{
    
}

//abrir el archivo
//fd
//leer, y retornar hasta \n
//buffer size, 
//modificar la variable, eliminando lo ya leido

buffer 5; 

hola\n
que tal\n
estas\n


static char *store = "hola\nq" //lee todo lo que se puede por buffer_size //lee read
char *return = "hola\n" //retorna hasta el \n (incluyendo el \n)

//despues de la funcion para limpiar la statica tiene que ser:

static char *store = "q"

ft_free(&store)
void    ft_free(char **ptr);

free(*ptr);
*ptr = NULL;
RETURN NULL;
////////////////

ue tal\n //lo siguiente que va a leer read 
estas\n

//unes lo que sobra con lo que de buffer size
static char *store = "que tal"
char *return = "" //no retornas no hay null

////////////////

\n
estas\n

//unes lo que sobra con lo que de buffer size
static char *store = "que tal\nestas"
char *return = "que tal\n"

////////////////

\n

//unes lo que sobra con lo que de buffer size
static char *store = "estas\n"
char *return = "estas\n"

////////////////