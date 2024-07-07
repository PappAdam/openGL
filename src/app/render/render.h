#ifndef __ENGINE_RENDER_H

#define __ENGINE_RENDER_H
#include "default_include.h"
#include "vertex.h"
#include "shaders.h"
#include "texture.h"

typedef struct __Renderer
{
    ShaderProgram shader_program;

    uint32_t VBO;
    uint32_t VAO;
    uint32_t EBO;

    int color_uniform_location;
    float color;

    Texture texture;
} Renderer;

void render(Renderer *renderer);
void initRenderer(Renderer *self);

#endif
