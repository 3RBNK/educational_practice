//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_6_GET_UPPER_ENVELOPE_H
#define PRACTICE_6_GET_UPPER_ENVELOPE_H

#include <assert.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define INF DBL_MAX


typedef struct Point {
    double x;
    double y;
} Point;


double get_intersection(const Point a, const Point b) {
    const double x = (b.y - a.y) / (a.x - b.x);
    const double y = a.x * x + a.y;
    return y;
}


int orientation(const Point p, const Point q, const Point r) {
    const double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (fabs(val) < DBL_EPSILON)
        return 0;
    return val > 0 ? 1 : 2;
}


double get_upper_envelope(Point points[], int n) {
    if (n < 2)
        return -INF;

    Point* new_points = malloc(sizeof(Point) * (n + 1));
    for (int i = 0; i < n; i++)
        new_points[i] = points[i];
    new_points[n].x = 0;
    new_points[n].y = -INF;

    n += 1;
    int *next = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        next[i] = -1;

    int l = 0;
    for (int i = 1; i < n; i++)
        if (new_points[i].x < new_points[l].x)
            l = i;

    int p = l;
    do {
        int q = (p + 1) % n;
        for (int i = 0; i < n; i++)
            if (orientation(new_points[p], new_points[i], new_points[q]) == 2)
                q = i;

        next[p] = q;
        p = q;
    } while (p != l);

    double min_y = INF;
    for (int i = 0; i < n - 1; i++) {
        double max_intersection = -INF;
        for (int j =  i+ 1; j < n; j++) {
            if (next[i] != -1 && next[j] != -1) {
                const double y = get_intersection(new_points[i], new_points[j]);
                if (y > max_intersection)
                    max_intersection = y;
            }
        }

        if (max_intersection < min_y && fabs(max_intersection + INF) >= DBL_EPSILON)
            min_y = max_intersection;
    }

    free(next);
    free(new_points);

    return min_y;
}


void test_get_upper_envelope_one_line() {
    Point points[] = {{10, 5}};
    const int n = 1;

    const double y = get_upper_envelope(points, n);

    assert(fabs(y + DBL_MAX) < DBL_EPSILON);
}


void test_get_upper_envelope_two_line() {
    Point points[] = {{2, 0}, {0.5, 3}};
    const int n = 2;

    const double y = get_upper_envelope(points, n);

    assert(fabs(y - 4) < DBL_EPSILON);
}


void test_get_upper_envelope_more_line() {
    Point points[] = {{2, 0}, {0.5, 3}, {-1, -3}, {1, 1}};
    const int n = 4;

    const double y = get_upper_envelope(points, n);

    assert(fabs(y - 1) < DBL_EPSILON);
}


void test_get_upper_envelope() {
    test_get_upper_envelope_one_line();
    test_get_upper_envelope_two_line();
    test_get_upper_envelope_more_line();
}


#endif //PRACTICE_6_GET_UPPER_ENVELOPE_H
