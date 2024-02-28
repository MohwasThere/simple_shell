#include "shell.h"

/**
 * _myenv - prints current enviroment
 * @info : struct containg potential args
 * 
 * Return: Always 0
*/
int _myenv(info_t *info)
{
    print_list_str(info->env);
    return (0);
}