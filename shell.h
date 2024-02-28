#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>

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

extern char **environ;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0} //like an array or struct

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

/*getinfo functions*/
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/*mem functions*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ffree(char **pp);
char *_memset(char *s, char b, unsigned int n);
int bfree(void **ptr);

/*error functions*/
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/*list functions*/
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/*enviroment functoions*/
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

#endif