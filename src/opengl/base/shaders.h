#if !defined(__SHADERS_H)
#define __SHADERS_H

#include "default_include.h"
uint32_t create_shader(const char *filename, GLenum shader_type);

typedef uint32_t ShaderProgram;

void use_program(ShaderProgram program);
ShaderProgram create_program(const char *vertex_source, const char *fragment_source);

#endif // __SHADERS_H
