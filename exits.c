#include "shell.h"

/**
 * *_strcpy - copies a string
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
 
/**
 * *_strncat - concatenantes two strings
 * @dest: string to
 * @src: source string
 * @n: amound of bytes maximally used
 * 
 * Return: the final string
*/
char *_strncat(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    i = 0;
    j = 0;
    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && j < n)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    if (j < n)
        dest[i] = '\0';
    return (s);
}

/**
 **_strchar - locates a char in a string
 *@s: string to be parsed
 *@c: the char to look for
 *
 * Return: (s) a pointer to the memory area of s.
*/
char *_strchar(char *s, char c)

{
    do {
            if (*s == c)
                return (s);
    } while (*s++ != '\0');

    return (NULL);
}