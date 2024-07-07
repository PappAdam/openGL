#if !defined(__APPLICATION_H)
#define __APPLICATION_H

#include "default_include.h"
#include "render.h"

typedef struct __App
{
    GLFWwindow *window;
    Renderer renderer;
} App;

bool initializeApp(App *app);
void runApp(App *app);

#endif // __APPLICATION_H
