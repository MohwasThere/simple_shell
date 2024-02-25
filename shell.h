#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*For Read and Write BUFFS*/
#define READ_BUF_SIZE  1024
#define WRITE_BUF_SIZE 1024

/**
 * liststr - singly linked list
 * @num: int value
 * @str: string value
 * @next: points to the next node in the linkedlist
*/
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

typedef struct passinfo
{
    char *arg;
    char **argv;
    char *path;
    int argc;
    unsigned int line_count;
    int err_num;
    int linecount_flag;
    char *fname;
    list_t *env;
    list_t  *history;
    list_t *alias;
    char **environ;
    int env_changed;
    int status;

    int readfd;

} info_t;



#endif