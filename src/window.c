#include <alexandria/window.h>
#include <alexandria/helpers.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef enum Flag {
    IS_RUNNING = 0b1,
} Flag;

static inline void __handle_events__(Window* window);
static inline void __render__(Window* window);

Window
window_create(Alexandria* alexandria, const char* title, u32 x, u32 y, u32 width, u32 height, WindowFlag window_flags, RendererFlag renderer_flags)
{
    if(!alexandria) panic("alexandira is never NULL, shame on you.");
    SDL_Window* window = SDL_CreateWindow(title, x, y, width, height, (u32)window_flags);
    if(!window) panic(SDL_GetError());
    // SDL_SetWindowOpacity(window, 0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, (u32)renderer_flags);
    if(!renderer) panic(SDL_GetError());
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    return (Window) { .flags = 0, .alexandria = alexandria, .window_impl = window, .renderer_impl = renderer };
}

void
window_destroy(Window* self)
{
    if(self)
    {
        SDL_DestroyWindow(self->window_impl);
        SDL_DestroyRenderer(self->renderer_impl);
    }
}

void
window_mainloop(Window* self)
{
    self->flags |= IS_RUNNING;      // start running

    while(self->flags & IS_RUNNING)
    {
        __handle_events__(self);

        // __upate_timer(delta_time);

        __render__(self);

        SDL_Delay(1000 / 60);
    }
}

void window_center(Window* self)
{
    SDL_SetWindowPosition(self->window_impl, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}


/***********************************************************/
/************************* Private *************************/
/***********************************************************/

void
__handle_events__(Window* window)
{
    SDL_Event ev;

    //Handle events on queue
    while( SDL_PollEvent( &ev ) )
    {
        //User requests quit
        if( ev.type == SDL_QUIT )
        {
            window->flags &= ~(IS_RUNNING);  // toggle running flag
        }
    }
}

void
__render__(Window* window)
{
    // // Set the color to cornflower blue and clear
    // SDL_SetRenderDrawColor(window->renderer_impl, 100, 149, 237, 0);
    // SDL_RenderClear(window->renderer_impl);

    // // Show the renderer contents
    SDL_RenderPresent(window->renderer_impl);
}