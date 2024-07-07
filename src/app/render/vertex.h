#if !defined(__VERTEX_H)
#define __VERTEX_H

#include "default_include.h"

typedef struct __Vertex
{
    vec3 position;
    vec3 color;
    vec2 texture_coord;
} Vertex;

DEFINE_VEC(Vertex);

#endif // __VERTEX_H
