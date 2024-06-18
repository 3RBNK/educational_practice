#include "algorithms/task/10_refactor_text.h"

int main() {
    const char filename[] = "/home/bnkr/CLionProjects/practice/for_while_if_else_int.txt";
    char text[] = "for float россия int i = 0; i < 10; i++";

    refactor_text(text, filename);

    return 0;
}
