#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the string to be copied to 
 * @src: the source string
 * @n: the amound of chars to be copied
 * 
 * Return: concatenated string
*/

char *_strncpy(char *dest, char *src, int n)
{
    int i,j;
    char *s = dest;

    i = 0;
    while (src[i] != '\0' && i < n - 1)
    {
        dest[i] = src[i];
        i++;

    }
    if (i < n)
    {
        j = i;
        while (j < n)
        {
            dest[j] = '\0';
            j++;
        }
    }
    return (s);

}
 
