//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_8_FIND_CONVEX_HULL_H
#define PRACTICE_8_FIND_CONVEX_HULL_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct point {
    double x, y, z;
} point;


typedef struct face {
    point a, b, c;
} face;


point cross_product(const point a, const point b) {
    point result;

    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;

    return result;
}


double dot_product(const point a, const point b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

bool is_face_visible(const face f, const point p) {
    point normal = cross_product(f.b, f.c);
    point diff = {p.x - f.a.x, p.y - f.a.y, p.z - f.a.z};
    return dot_product(normal, diff) > 0;
}

face find_next_face(const point* points, int num_points, const face current_face) {
    for (int i = 0; i < num_points; i++) {
        if (is_face_visible(current_face, points[i])) {
            return (face){current_face.b, current_face.c, points[i]};
        }
    }
    return current_face; // no visible face found, return the current face
}

void convex_hull(const point* points, int num_points) {
    face hull_face = {points[0], points[1], points[2]}; // start with the first three points
    face prev_face;

    do {
        printf("Face: (%f, %f, %f), (%f, %f, %f), (%f, %f, %f)\n",
               hull_face.a.x, hull_face.a.y, hull_face.a.z,
               hull_face.b.x, hull_face.b.y, hull_face.b.z,
               hull_face.c.x, hull_face.c.y, hull_face.c.z);

        prev_face = hull_face;
        hull_face = find_next_face(points, num_points, hull_face);
    } while ((hull_face.a.x != prev_face.a.x || hull_face.a.y != prev_face.a.y || hull_face.a.z != prev_face.a.z) &&
             (hull_face.a.x != points[0].x || hull_face.a.y != points[0].y || hull_face.a.z != points[0].z));
}


#endif //PRACTICE_8_FIND_CONVEX_HULL_H
