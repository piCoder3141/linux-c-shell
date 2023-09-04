#include "main.h"

int main(int ac, char **argv){
    char *prompt = "(PiShell) $ ";
    char *lineptr = NULL;
    size_t len = 0;
    char *delim = " ";

    while(1){
        printf("%s", prompt);
        ssize_t line_size = getline(&lineptr, &len, stdin);
        if (line_size == -1){
            free(lineptr);
            printf("\nExiting PiShell\n");
            break;
        }
        char *saveptr;
        char *p = strtok_r(lineptr, delim, &saveptr);
        char **arr = malloc(80);
        int n_spaces = 0;
        while(p){
            n_spaces++;
            // arr = realloc(arr, sizeof(char*) * n_spaces);
            // if (arr == NULL){
            //     exit(EXIT_FAILURE);
            // }
            arr[n_spaces-1] = malloc(sizeof(char*));
            arr[n_spaces-1] = p;

            p = strtok_r(NULL, delim, &saveptr);
        }
        // arr = realloc(arr, sizeof(char*) * n_spaces);
        arr[n_spaces] = malloc(sizeof(char*));
        arr[n_spaces] = NULL;

        for (int i = 0; i < n_spaces; i++){
            printf("%s\n", arr[i]);
        }
        free(arr);
    }

    exit(EXIT_SUCCESS);
}
