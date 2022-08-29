#include <alexandria.h>
#include <alexandria/helpers.h>
#include <alexandria/define.h>
#include <alexandria/typedef.h>

#include <SDL2/SDL.h>

Alexandria
alexandria_init()
{
    if( SDL_Init(SDL_INIT_FLAGS) < 0)
    {
        panic("Couldn't initialize SDL");
    }
}

void
alexandria_deinit(Alexandria* self)
{
    SDL_Quit();
}