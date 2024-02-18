/**
 *_strlen - counts the length of the string
 *@s: string to be counted.
 * 
 * Return: The length of the string S.
 */
int _strlen(char *s)
{
    int len = 0;

    if (!s)
        return (0);

    while (*s++)
        len++;
    return (len);

}

/**
 * _strcmp - performs lexicographic comparison between S1 and S2
 * @s1: the first string
 * @s2: the second string
 * 
 * Returns: negative is s1 < s2, positive if s1 > s2, zero if s1 == s2
*/
int _strcamp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1
    }
}