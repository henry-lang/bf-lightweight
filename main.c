#include <stdio.h>
#include <stdlib.h>

char *src;
char mem[30000];

void run() {
    printf("%s\n", src);
}

void die(char *msg) {
    printf("\033[31;1mERROR: %s\033[0m\n", msg); // The jumble of characters before and after the ERROR: is just color formatting for the terminal
    exit(1);
}

int main(int argc, char **argv) {
    if(argc != 2) die("Invalid number of arguments.");
    char *fname = argv[1];

    // Open file and get size
    FILE *file = fopen(fname, "r");
    if(file == NULL) {
        die("Failed to open file.");
    }
    fseek(file, 0L, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    // Allocate memory for the program source
    src = malloc(sizeof(char) * (size + 1));
    if(src == NULL) {
        die("Failed to allocate memory for the file source.");
    }

    // Copy source file in memory
    char curr;
    size_t idx;
    while ((curr = fgetc(file)) != EOF) {

        idx++;
    }

    run();

    fclose(file);
    return 0;
}
