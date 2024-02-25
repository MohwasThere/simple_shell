#include "shell.h"

int main(int argc, char **argv)
{
    size_t s;
    size_t buff_size = 1024;
    char *buff;

    buff = (char *)malloc(buff_size * sizeof(char));
    if (buff == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("$");
    s = getline(&buff, &buff_size, stdin);

    // Free allocated memory
    free(buff);

    return 0;
}
