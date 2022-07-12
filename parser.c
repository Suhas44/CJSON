#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse(char* json, int length);
char* read_file(char* filename);
char* trim(char* json);
void slice(const char* str, char* result, size_t start, size_t end);

void main() {
    char* json = read_file("info.json");
    json = trim(json);
    parse(json, strlen(json));
}

void parse(char* json, int length) {
    if (json[0] != '{' || json[length - 1] != '}') {
        printf("Error: Expected '{' and '}'\n");
        return;
    }
    char* objects = (char*)malloc(sizeof(char) * (length - 2));
    slice(json, objects, 1, length - 1);
    free(json);
}

void string_parse(char* json) {
}

void number_parse(char* json) {
}

void array_parse(char* json) {
}

void boolean_parse(char* json) {
}

void null_parse(char* json) {
}

void object_parse(char* json) {
}

char* read_file(char* filename) {
    FILE* file = fopen(filename, "r");
    char* buffer = (char*)malloc(1);
    char ch;
    int i = 0;
    while ((ch = fgetc(file)) != EOF) {
        buffer = (char*)realloc(buffer, sizeof(char) * (i + 1));
        buffer[i] = ch;
        i++;
    }
    fclose(file);
    return buffer;
}

char* trim(char* json) {
    char* buffer = (char*)malloc(strlen(json) * sizeof(char));
    int i;
    int j = 0;
    for (i = 0; i < strlen(json); i++) {
        if (json[i] == 32 || json[i] == 10 || json[i] == 13) {
            j++;
        } else {
            buffer[i - j] = json[i];
        }
    }
    char* trim;
    strncpy(trim, buffer, (i - j));
    free(buffer);
    return trim;
}

void slice(const char* str, char* result, size_t start, size_t end) {
    size_t i;
    for (i = start; i < end; i++) {
        result[i - start] = str[i];
    }
    result[i - start] = '\0';
}