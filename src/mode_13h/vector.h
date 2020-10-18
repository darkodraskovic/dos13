#ifndef VECTOR_H
#define VECTOR_H

#define VEC3_ZERO(vec) vec.x = 0; vec.y = 0; vec.z = 0;

typedef struct {
    int x;
    int y;
} vec2i;

typedef struct {
    int x;
    int y;
    int z;
} vec3i;

typedef struct {
    float x;
    float y;
} vec2f;

typedef struct {
    float x;
    float y;
    float z;
} vec3f;

#endif /* VECTOR_H */
