#include "shell.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @info: struct address
 * 
 * Return: 1 if in interactive mode, 0 otherwise
*/

int interactive(info_t *info)
{
    return(isatty(STDERR_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimiter
 * @c: the char to check
 * @delim: the delimiter string
 * Return: 1 if true, 0 if false
*/

int is_delim(char c, char *delim)
{
    while (*delim)
            if(*delim++ == c)
                return (1);
    return (0);
}