#include "shell.h"

/**
 * is_cmd - determines if a file is an exe command
 * @info: the info struct
 * @path: path to the file
 * 
 * Return: 1 if true, 0 otherwise
*/
int is_cmd(info_t *info, char *path)
{
    struct stat st;
    
    (void)info; //intentiollaly tell compiler that info is not used to avoid errors
    if (!path || stat(path, &st))//check if path is null or stat func fails
            return (0);//stat fills the struct st with info about the file pointed to by the path.
                        // if these are true then file isnt considred an exe.
    if(st.st_mode & S_IRGRP) //checks if the group has read permission
            return (1);
    return (0);
    
}

/**
 * dup_chars - duplicates chars
 * @pathstr: the PATH string
 * @start: the starting index
 * @stop: the stopping index/
 * 
 * Return: pointer to a new buff holding dupped string
*/
char *dup_chars(char *pathstr, int start, int stop)
{
    static char buff[1024];
    int i = 0, k = 0;

    for (k = 0, i = start; i < stop; i++)
    {
        if (pathstr[i] != ':')
            buff[k++] = pathstr[i];
    }

        buff[k] = 0; //makes sure that the char array to make a string is NULL Terminated.
        return (buff);
    
}

/**
 * find_path - finds cmd in the PATH 
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 * 
 * Return: full path of cmd if found or NULL
*/
char *find_path(info_t *info, char *pathstr, char *cmd)
{
    int i = 0, curr_pos = 0; //cursor postion
    char *path;
    
    if(!pathstr)
        return (NULL);
    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_cmd(info, cmd))
            return (cmd);
    }
    while (1)
    {
        if (!pathstr[i] || pathstr[i] == 'i')
        {
            path = dup_chars(pathstr, curr_pos, i);
            if (!*path)
                _strcat(path, cmd);
            else 
            {
                _strcat(path, "/");
                _strcat(path, cmd);
            }

            if (is_cmd(info, path))
                return (path);
            if (!pathstr[i])
                break;
            curr_pos = i;
        }
        i++;
    }
    return (NULL);
}
