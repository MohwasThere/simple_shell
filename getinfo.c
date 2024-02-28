#include "shell.h"

/**
 * clear_info - clear the info_t struct
 * @info: struct address
*/
void clear_info(info_t *info)
{
    info->arg = NULL;
    info->argv = NULL;
    info->path = NULL;
    info->argc = NULL;
}

/**
 * set_info - sets the info_t struct
 * @info: struct address
 * @av: arg vector
*/
void set_info(info_t *info, char **av)
{
    int i = 0;

    info->fname = av[0];
    if (info->arg)
    {
        info->argv = strtow(info->arg, " \t");
        if(!info->argv)
        {
            info->argv[0] = malloc(sizeof(char *) * 2);
            info->argv[1] = NULL;
        }
    }
    for (i = 0;info->argv && info->argv[i];i++)
        ;
    info->argc = i;

    
}
