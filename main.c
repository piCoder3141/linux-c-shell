#include "main.h"

int main(int ac, char **argv){
    char *prompt = "(PiShell) $ ";
    char *lineptr = NULL;
    size_t len = 0;

    ssize_t line_size = getline(&lineptr, &len, stdin);
    printf("%s\n", lineptr);

    printf("%s", prompt);
}
