//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_8_FIND_CONVEX_HULL_H
#define PRACTICE_8_FIND_CONVEX_HULL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_POINTS 10001

typedef struct {
    float x, y, z;
} Vector3;

typedef struct {
    Vector3 normal;
    float dfo;
    int c1, c2, c3;
} Face;

typedef struct {
    int i1, i2;
} PairIndex;

Vector3 all_points[MAX_POINTS];
Face hull_faces[MAX_POINTS];
PairIndex edge_to_face[MAX_POINTS][MAX_POINTS];
int num_faces = 0;

Vector3 cross(Vector3 v1, Vector3 v2) {
    Vector3 result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}

Vector3 sub(Vector3 v1, Vector3 v2) {
    Vector3 result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

float dot(Vector3 v1, Vector3 v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

void insert(PairIndex* pair, int a) {
    if(pair->i1 == -1) {
        pair->i1 = a;
    } else {
        pair->i2 = a;
    }
}

void remove_index(PairIndex* pair, int a) {
    if(pair->i1 == a) {
        pair->i1 = -1;
    } else if(pair->i2 == a) {
        pair->i2 = -1;
    }
}


int num_ver(PairIndex* pair) {
    int a = 0;
    if(pair->i1 != -1) {
        a++;
    }
    if(pair->i2 != -1) {
        a++;
    }
    return a;
}

Face add_face(int p1, int p2, int p3, int mid) {
    insert(&edge_to_face[p1][p2], p3);
    insert(&edge_to_face[p2][p1], p3);
    insert(&edge_to_face[p2][p3], p1);
    insert(&edge_to_face[p3][p2], p1);
    insert(&edge_to_face[p1][p3], p2);
    insert(&edge_to_face[p3][p1], p2);

    Face newf;
    newf.c1 = p1;
    newf.c2 = p2;
    newf.c3 = p3;

    newf.normal = cross(sub(all_points[p2], all_points[p1]), sub(all_points[p3], all_points[p1]));
    newf.dfo = dot(newf.normal, all_points[p1]);

    if(dot(newf.normal, all_points[mid]) > newf.dfo) {
        newf.normal.x *= -1;
        newf.normal.y *= -1;
        newf.normal.z *= -1;
    }

    return newf;
}

int getPoints(char* file_name) {
    FILE* file = fopen(file_name, "r");
    if(file == NULL) {
        printf("Could not open file %s\n", file_name);
        return -1;
    }

    int n;
    fscanf(file, "%d", &n);

    for(int i = 0; i < n; i++) {
        fscanf(file, "%f %f %f", &all_points[i].x, &all_points[i].y, &all_points[i].z);
    }

    fclose(file);
    return n;
}

void hullInitial(int n) {
    memset(edge_to_face, -1, sizeof(edge_to_face));

    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 4; j++) {
            for(int k = j + 1; k < 4; k++) {
                hull_faces[num_faces++] = add_face(i, j, k, 6 - i - j - k);
            }
        }
    }
}


void find_convex_hull(char* inputfile, const char* outputfile) {
    int n = getPoints(inputfile);

    hullInitial(n);

    for(int i = 4; i < n; i++) {
        for(int j = 0; j < num_faces; j++) {
            Face f = hull_faces[j];

            if(dot(f.normal, all_points[i]) > f.dfo) {
                remove_index(&edge_to_face[f.c1][f.c2], f.c3);
                remove_index(&edge_to_face[f.c2][f.c1], f.c3);
                remove_index(&edge_to_face[f.c1][f.c3], f.c2);
                remove_index(&edge_to_face[f.c3][f.c1], f.c2);
                remove_index(&edge_to_face[f.c3][f.c2], f.c1);
                remove_index(&edge_to_face[f.c2][f.c3], f.c1);
                hull_faces[j--] = hull_faces[--num_faces];
            }
        }

        int num_f = num_faces;
        for(int j = 0; j < num_f; j++) {
            Face f = hull_faces[j];
            if(num_ver(&edge_to_face[f.c1][f.c2]) != 2) {
                hull_faces[num_faces++] = add_face(f.c1, f.c2, i, f.c3);
            }
            if(num_ver(&edge_to_face[f.c1][f.c3]) != 2) {
                hull_faces[num_faces++] = add_face(f.c1, f.c3, i, f.c2);
            }
            if(num_ver(&edge_to_face[f.c2][f.c3]) != 2) {
                hull_faces[num_faces++] = add_face(f.c2, f.c3, i, f.c1);
            }
        }
    }

    Vector3 hull_points[MAX_POINTS];
    int hull_size = 0;

    for(int i = 0; i < n; i++) {
        Vector3 v = all_points[i];
        for(int j = 0; j < num_faces; j++) {
            float d = hull_faces[j].dfo - dot(hull_faces[j].normal, v);
            if(d == 0) {
                hull_points[hull_size++] = all_points[i];
                break;
            }
        }
    }

    FILE* file = fopen(outputfile, "w");
    if(file == NULL) {
        printf("Could not open file %s\n", outputfile);
        exit(-1);
    }

    fprintf(file, "%d\n", hull_size);
    for(int i = 0; i < hull_size; i++) {
        fprintf(file, "%f %f %f\n", hull_points[i].x, hull_points[i].y, hull_points[i].z);
    }

    fclose(file);
}


#endif //PRACTICE_8_FIND_CONVEX_HULL_H
