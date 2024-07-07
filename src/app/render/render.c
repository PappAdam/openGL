#include "render.h"
#include "shaders.h"

void initRenderer(Renderer *self)
{
    Vertex vertices[] = {
        (Vertex){
            position :
                {0.5f,
                 0.5f,
                 0.0f},
            color :
                {1.0f,
                 0.0f,
                 0.0f},
            texture_coord :
                {1.0f,
                 1.0f},
        }, // top right
        (Vertex){
            position :
                {0.5f,
                 -0.5f,
                 0.0f},
            color :
                {0.0f,
                 1.0f,
                 0.0f},
            texture_coord :
                {1.0f,
                 0.0f},
        }, // bottom right
        (Vertex){
            position :
                {-0.5f,
                 -0.5f,
                 0.0f},
            color :
                {0.0f,
                 0.0f,
                 1.0f},
            texture_coord :
                {0.0f,
                 0.0f},
        },                                                                                                 // bottom left
        (Vertex){position : {-0.5f, 0.5f, 0.0f}, color : {1.0f, 1.0f, 0.0f}, texture_coord : {0.0f, 1.0f}} // top left
    };

    uint32_t indices[] = {
        0, 1, 3, // 1st
        1, 2, 3  // 2nd
    };

    glGenBuffers(1, &self->VBO);
    glGenBuffers(1, &self->EBO);
    glGenVertexArrays(1, &self->VAO);

    glBindVertexArray(self->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, self->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, self->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    self->texture = create_texture("src/resources/texture.jpg");

    self->shader_program = create_program("src/shaders/vertex.vert", "src/shaders/fragment.frag");

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void render(Renderer *self)
{
    glClearColor(0.2, 0.3, 0.4, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    use_program(self->shader_program);
    double time = glfwGetTime();

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, self->texture);
    glBindVertexArray(self->VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
