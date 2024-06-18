//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_10_REFACTOR_TEXT_H
#define PRACTICE_10_REFACTOR_TEXT_H

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


#define MAX_WORD_LENGTH 1024
#define MAX_AMOUNT_WORD 128


bool is_resrved(const char* word, char reserved_word[MAX_AMOUNT_WORD][MAX_WORD_LENGTH], const int n) {
    for (int i = 0; i < n; i++)
        if (strcmp(word, reserved_word[i]) == 0)
            return true;
    return false;
}


void refactor_text(char* text, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Не удалось прочесть\n");
        exit(1);
    }

    char reserved_word[MAX_AMOUNT_WORD][MAX_WORD_LENGTH];
    int n = 0;
    while (fscanf(file, "%s", reserved_word[n]) != EOF && n < MAX_AMOUNT_WORD)
        n ++;

    fclose(file);


    char* word = strtok(text, " ");
    while (word != NULL) {
        if (is_resrved(word, reserved_word, n)) {
            for (int i = 0; word[i]; i++)
                word[i] = toupper(word[i]);
        } else {
            for (int i = 0; word[i]; i++)
                word[i] = tolower(word[i]);
        }
        printf("%s ", word);
        word = strtok(NULL, " ");
    }
}




#endif //PRACTICE_10_REFACTOR_TEXT_H
