#include "shell.h"

/**
 * _errtoi - converts a string to an integer
 * @s: the string to be converted
 * 
 * Return: 0 if no numbers in string, converted number others -1 on error
*/
int _erratoi(char *s)
{
    int i = 0;
    unsigned long int result = 0;

    if (*s == '+')
        s++;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            result *= 10;
            result =+ (s[i] - '0');
        }
    }
}
