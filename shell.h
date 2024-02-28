#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

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

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@readfd: the fd from which to read line input
 */
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

/*string functions*/
char **strtow(char *str, char * d);//tokenize
char **strtow2(char *str, char *d);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *starts_with(const char *haystack, const char *needle);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);

/*mem functions*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ffree(char **pp);
char *_memset(char *s, char b, unsigned int n);
int bfree(void **ptr);

#endif
