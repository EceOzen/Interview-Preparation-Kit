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

int getSize (char * s) {
    char * t; // first copy the pointer to not change the original
    int size = 0;

    for (t = s; *t != '\0'; t++) {
        size++;
    }

    return size;
}

// Complete the repeatedString function below.
long repeatedString(char* s, long n) {
    // first find number of a repeated string
    int size = getSize(s);
    long a_counter = 0;
    long remain_count = 0;
    long last_counter = 0;
    long repeat = 0;
    int remain = 0;
    
    //printf("%d\n", size);
    for(int i = 0; i < size; i++){
        if(s[i] == 'a'){
            a_counter++;
        }
    }
    // find repeat count
    repeat = n / size;
    
    if(n % size != 0){
        remain = n - (size * repeat);
        for(int j = 0; j < remain; j++){
            if(s[j] == 'a'){
                remain_count++;
            }
        }
    }
    // find repeat count
    repeat = n / size;
    
//    printf("%ld %ld\n", n, repeat);
    
    last_counter = (repeat * a_counter) + remain_count;
    return last_counter;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* n_endptr;
    char* n_str = readline();
    long n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    long result = repeatedString(s, n);

    fprintf(fptr, "%ld\n", result);

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
