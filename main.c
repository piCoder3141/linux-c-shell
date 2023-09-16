#include "main.h"

int _ls(const char *path){
    DIR *dp;
    struct dirent *entry;

    dp = opendir(path);
    if (dp == NULL){
        perror("Error");
        return -1;
    }

    while (entry = readdir(dp)){
        printf("%s\n", entry->d_name);
    }
    closedir(dp);
    return 0;
}

int main(int ac, char **argv){
    char *prompt = "(PiShell) $ ";
    size_t len = 0;
    char *delim = " \n";

    while(1){
    char *lineptr = NULL;
        printf("%s", prompt);
        ssize_t line_size = getline(&lineptr, &len, stdin);
        if (line_size == -1){
            free(lineptr);
            printf("\nExiting PiShell\n");
            break;
        }
        char *saveptr;
        char *p = strtok_r(lineptr, delim, &saveptr);
        char **arr = NULL;
        int n_spaces = 0;
        while(p){
            n_spaces++;
            char **tmp = realloc(arr, sizeof(char*) * n_spaces);
            if (tmp == NULL){
                exit(EXIT_FAILURE);
            }
            else{
                arr = tmp;
            }
            arr[n_spaces-1] = p;

            p = strtok_r(NULL, delim, &saveptr);
        }

        if (strcmp(arr[0], "ls") == 0){
            _ls(arr[1]);
        }
        free(arr);
        free(lineptr);
    }

    exit(EXIT_SUCCESS);
}
