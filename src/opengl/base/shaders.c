#include "shaders.h"

char *read_file(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("fp is null");
        exit(0);
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);

    if (file_size == 0 || file_size == -1)
    {
        fclose(fp);
        printf("invalid file_size");
        exit(0);
    }

    char *buffer = malloc(file_size + 1);
    if (buffer == NULL)
    {
        fclose(fp);
        printf("failed to allocate memory for shader");
        exit(0);
    }

    fseek(fp, 0, SEEK_SET);
    fread(buffer, 1, file_size, fp);

    buffer[file_size] = '\0';

    fclose(fp);

    return buffer;
}

uint32_t create_shader(const char *filename, GLenum shader_type)
{
    const char *source_file = read_file(filename);

    uint32_t shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, (const char **)&source_file, NULL);
    glCompileShader(shader);

    int success;
    char info[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, info);
        printf("Failed to read shader due to: %s", info);
        exit(-1);
    }

    return shader;
}

void use_program(ShaderProgram program)
{
    glUseProgram(program);
}

ShaderProgram create_program(const char *vertex_source, const char *fragment_source)
{
    uint32_t vertex_shader = create_shader(vertex_source, GL_VERTEX_SHADER);
    uint32_t fragment_shader = create_shader(fragment_source, GL_FRAGMENT_SHADER);

    ShaderProgram program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);

    glLinkProgram(program);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return program;
}
