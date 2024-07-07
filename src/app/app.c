#include "app.h"
#include "initializers.h"
#include "input.h"
#include "callbacks.h"

bool initializeApp(App *self)
{
    self->window = NULL;
    if (!initWindow(&self->window))
    {
        return false;
    }
    glfwSetWindowSizeCallback(self->window, framebuffer_size_callback);
    initRenderer(&self->renderer);

    return true;
}

void runApp(App *self)
{
    GLFWwindow *window = self->window;
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        render(&self->renderer);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}