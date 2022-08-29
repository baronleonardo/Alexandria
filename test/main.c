#include <alexandria.h>
#include <alexandria/window.h>

#include <stdio.h>

int main(int argc, char* argv[])
{
    Alexandria alexandria = alexandria_init();
    Window window = window_create(
        &alexandria,
        "This is the end!",
        0, 0,
        800, 600,
        WINDOWFLAG_RESIZABLE,
        RENDERERFLAG_ACCELERATED | RENDERERFLAG_PRESENTVSYNC
    );
    window_center(&window);

    window_mainloop(&window);

    window_destroy(&window);
    alexandria_deinit(&alexandria);
}