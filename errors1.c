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
        _eputchar(str[i]);
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
    if (c != -1)
        buff[i++] = c;
    return (1);
}

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == -1 || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != -1)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
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
