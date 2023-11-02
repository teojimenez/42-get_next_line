// Forma Incorrecta
// La cadena "Hola Mundo!" es una cadena literal y se almacena en una región de solo lectura de la memoria.
// Intentar modificar una cadena literal en C resultará en un comportamiento indefinido.
// -> char *p_text1 = "Hola Mundo!";

// Forma Correcta
// Para corregir esto, puedes declarar p_text1 como un array de caracteres o asignar memoria dinámicamente usando malloc.
// Aquí hay un ejemplo usando un array de caracteres:
// -> char p_text1[] = "Hola Mundo!";

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ft_extra(char **p_text1)
{
    (*p_text1)[2] = 'c';
    (*p_text1)[9] = 'w';
    (*p_text1)[4] = ' ';
}

void xtraFunction(char **storage, char **buffer, char **result)
{
    int i = 0;
    while ((*storage)[i] != '\n')
        i++;
    i++;
    *(result) = (char *)malloc((i + 1) * sizeof(char));
    int j = 0;
    while (j < i)
    {
        (*result)[j] = (*storage)[j];
        j++;
    }
    *(result[j]) = '\0';
    while (*(buffer[i]) != '\0')
        i++;
}

int main()
{
    // char *p_text1 = malloc(strlen("Hola Mundo!") + 1);
    // strcpy(p_text1, "Hola Mundo!");
    // ft_extra(&p_text1);
    // printf("%s\n", p_text1);
    // free(p_text1);
    static char *storage = NULL;
    char *buffer = malloc(strlen("Holaa\nndo!") + 1);
    char *result;
    buffer = (char *)malloc(sizeof(char) * (6 + 1));

    xtraFunction(&storage, &buffer, &result);
    return 0;
}

