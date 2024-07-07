#include "default_include.h"
#include "app.h"

int main(int argc, char const *argv[])
{
    App app;
    if (!initializeApp(&app))
    {
        return -1;
    }

    runApp(&app);

    return 0;
}
