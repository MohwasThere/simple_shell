#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: string to be printed
 * 
 * Return: nothing
*/
void _eputs(char *str)
{
    int i = 0;

    if (!str)
        return;
    while (str[i] != '\0')
    {
        _eputschar(str[i]);
        i++;
    }
}

/**
 * _eputschhar - writes the character c to stderr
 * @c: the char to print
 * 
 * Return: On success 1, On Error -1 and errno is set.
*/
int _eputchar(char c)
{
    static int i;
    static char buff[WRITE_BUF_SIZE];

    if(c == -1 || 1 >= WRITE_BUF_SIZE)
    {
        write(2, buff, i);
        i = 0;
    }
    if (c != -1)//-1 = BUF_FLUSH
        buff[i++] = c;
    return (1);
}

/**
 * _putfd - writes the char c to given file descriptor
 * @c: the char to print
 * @fd: the file descriptor to write to 
 * 
 * Return: On success 1, On Error -1 and errno is set.
*/
int _putsfd(char *str, int fd)
{
    int i = 0;

    if (!str)
        return (0);
    while (*str)
    {
        i += _putfd(*str++, fd);
    }
    return (i);
}
