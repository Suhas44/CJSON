#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_file(char* filename);
void parse(char* json);
char* trim(char* json);

void main() {
    char* json = read_file("info.json");
    json = trim(json);
}

void parse(char* json) {
}

char* read_file(char* filename) {
    FILE* file = fopen(filename, "r");
    char* buffer = (char*)calloc(3000, sizeof(char));
    char ch;
    int i = 0;
    do {
        ch = fgetc(file);
        buffer[i] = ch;
        i++;
    } while (ch != EOF);
    fclose(file);
    return buffer;
    free(buffer);
}

char* trim(char* json) {
    char* buffer = (char*)malloc(strlen(json) * sizeof(char));
    int i;
    int j = 0;
    for (i = 0; i < strlen(json); i++) {
        if (json[i] == 32) {
            j++;
        } else {
            buffer[i - j] = json[i];
        }
    }
    char* trim;
    strncpy(trim, buffer, (i - j));
    return trim;
}