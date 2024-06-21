//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_10_REFACTOR_TEXT_H
#define PRACTICE_10_REFACTOR_TEXT_H

#include <assert.h>
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


char* refactor_text(char* text, const char* filename) {
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

    char* result = malloc(strlen(text) + 1);
    result[0] = '\0';

    char* word = strtok(text, " ");
    while (word != NULL) {
        if (is_resrved(word, reserved_word, n)) {
            for (int i = 0; word[i]; i++)
                word[i] = toupper(word[i]);
        } else {
            for (int i = 0; word[i]; i++)
                word[i] = tolower(word[i]);
        }
        strcat(result, word);
        strcat(result, " ");
        word = strtok(NULL, " ");
    }

    return result;
}


void test_refactor_text_only_russian_word() {
    char text[] = "онли руссиан ворд";
    const char filename[] = "/home/bnkr/CLionProjects/practice/file_for_tasks/10_refactor_text/set_word.txt";

    const char* refactoring = refactor_text(text, filename);

    puts(refactoring);

    assert(strcmp(refactoring, "онли руссиан ворд ") == 0);
}


void test_refactor_text_word_only_from_set() {
    char text[] = "for while if else";
    const char filename[] = "/home/bnkr/CLionProjects/practice/file_for_tasks/10_refactor_text/set_word.txt";

    const char* refactoring = refactor_text(text, filename);

    puts(refactoring);

    assert(strcmp(refactoring, "FOR WHILE IF ELSE ") == 0);
}


void test_refactor_text_different_word() {
    char text[] = "for русский while if else url ";
    const char filename[] = "/home/bnkr/CLionProjects/practice/file_for_tasks/10_refactor_text/set_word.txt";

    const char* refactoring = refactor_text(text, filename);

    puts(refactoring);

    assert(strcmp(refactoring, "FOR русский WHILE IF ELSE url ") == 0);
}


void test_refactor_text() {
    test_refactor_text_only_russian_word();
    test_refactor_text_word_only_from_set();
    test_refactor_text_different_word();
}




#endif //PRACTICE_10_REFACTOR_TEXT_H
