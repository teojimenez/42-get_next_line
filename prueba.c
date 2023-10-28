#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//function para la lectura
//function obtener la string hasta newline
//lo que sobre almacenarlo en la estatica (limpiar)


int main(void)
{
    char path[] = "file.txt";
    int fd = open(path, O_RDONLY);
    int buff_size = 7;
    char *buff;
    buff = (char*)malloc(sizeof(char) * (buff_size + 1));
    read(fd, buff, buff_size);
    static char *store = NULL;

    //ft_strlen hasta \n
    int i = 0;
    while(buff[i] != '\n' && i < buff_size)
        i++;
    i++; //para el \n
    store = (char *)malloc(i + 1 * sizeof(char));
    //rellenar
    int j = 0;

    while(j < i)
    {
        store[j] = buff[j];
        j++;
    }
    store[j] = '\0'; //has extraido lo que quieres retornar colocando un nulo despues del \n 
    
    printf("buff: %s\n\n", buff);
    printf("store: %s", store);
    read(fd, buff, buff_size);
    printf("\n\n(lo leido no sale ya)buff: %s", buff);
}