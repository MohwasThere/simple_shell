//#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimiter string
 * 
 * Return: a pointer to an array of strings, or NULL on failure
*/

char **strtow(char *str, char *d)
{
    int i, j, k, z, num = 0;
    char **s;
    if (str == NULL || str[0] == 0)
        return (NULL);
    if (!d)
        d = " ";
    for ( i = 0; str[i] != '\0'; i++)
    {
        if (!is_delim());
    }
}
