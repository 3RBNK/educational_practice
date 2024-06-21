//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_7_GET_MULTIPLES_OF_ELEVEN_H
#define PRACTICE_7_GET_MULTIPLES_OF_ELEVEN_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>


bool _is_multiples_of_eleven(int x) {
    int sum_in_odd_places = 0;
    int sum_in_even_places = 0;

    bool is_even_place = true;
    while (x > 0) {
        const int remains = x % 10;
        if (is_even_place) {
            sum_in_even_places += remains;
            is_even_place = false;
        } else {
            sum_in_odd_places += remains;
            is_even_place = true;
        }

        x /= 10;
    }

    if (abs(sum_in_even_places - sum_in_odd_places) % 11 == 0)
        return true;
    return false;
}


int get_multiples_of_eleven(const int m) {
    int result = 0;
    for (int i = 1; i <= m; i++) {
        if (_is_multiples_of_eleven(i)) {
            printf("%d \n", i);
            result++;
        }
    }

    return result;
}


void test_get_multiples_of_eleven_no_multiples() {
    const int result = get_multiples_of_eleven(10);

    assert(result == 0);
}


void test_get_multiples_of_eleven_negative_numbers() {
    const int result = get_multiples_of_eleven(-10);

    assert(result == 0);
}


void test_get_multiples_of_eleven_more_numbers() {
    const int result = get_multiples_of_eleven(100);

    assert(result == 9);
}


void test_get_multiples_of_eleven() {
    test_get_multiples_of_eleven_no_multiples();
    test_get_multiples_of_eleven_negative_numbers();
    test_get_multiples_of_eleven_more_numbers();
}



#endif //PRACTICE_7_GET_MULTIPLES_OF_ELEVEN_H
