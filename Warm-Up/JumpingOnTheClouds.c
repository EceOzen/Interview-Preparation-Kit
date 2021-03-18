#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(int c_count, int* c) {
    // always start with 0
    // If I want to achieve min jumps, probably I need to take into
    // acount first 2 step forward
    // I need a counter array -> there can be different paths
    printf("%d\n", c_count);
    int* counter = malloc(c_count * sizeof(int));
    int count = 0;
    int i = 0;
    while(i < c_count){
        // first go two step
        printf("%d\n", i);
        if(i+2 < c_count && c[i+2] == 0){
            // that means it is safe
         //   printf("I am in %d, I will go %d, is it safe %d\n",i, i+2, c[i+2]);
            count ++;
            i = i + 2;
           
        }else if(i+1 < c_count && c[i+1] == 0){
            // that means it is safe
          //  printf("I am in %d, I will go %d, is it safe %d\n",i, i+1, c[i+1]);
            count++;
            i = i + 1;
            
        }else{
            break;
        }
    }
    
    return count;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** c_temp = split_string(readline());

    int* c = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* c_item_endptr;
        char* c_item_str = *(c_temp + i);
        int c_item = strtol(c_item_str, &c_item_endptr, 10);

        if (c_item_endptr == c_item_str || *c_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(c + i) = c_item;
    }

    int c_count = n;

    int result = jumpingOnClouds(c_count, c);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
