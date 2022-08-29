#pragma once

#include <alexandria.h>
#include <alexandria/typedef.h>

typedef struct Window {
    u32 flags;
    Alexandria* alexandria;
    void* window_impl;
    void* renderer_impl;
} Window;

typedef enum WindowFlag {
    WINDOWFLAG_NONE = 0x00000000,
    WINDOWFLAG_FULLSCREEN = 0x00000001,         /**< fullscreen window */
    WINDOWFLAG_SHOWN = 0x00000004,              /**< window is visible */
    WINDOWFLAG_HIDDEN = 0x00000008,             /**< window is not visible */
    WINDOWFLAG_BORDERLESS = 0x00000010,         /**< no window decoration */
    WINDOWFLAG_RESIZABLE = 0x00000020,          /**< window can be resized */
    WINDOWFLAG_MINIMIZED = 0x00000040,          /**< window is minimized */
    WINDOWFLAG_MAXIMIZED = 0x00000080,          /**< window is maximized */
    WINDOWFLAG_MOUSE_GRABBED = 0x00000100,      /**< window has grabbed mouse input */
    WINDOWFLAG_INPUT_FOCUS = 0x00000200,        /**< window has input focus */
    WINDOWFLAG_MOUSE_FOCUS = 0x00000400,        /**< window has mouse focus */
    WINDOWFLAG_FULLSCREEN_DESKTOP = ( WINDOWFLAG_FULLSCREEN | 0x00001000 ),
    WINDOWFLAG_FOREIGN = 0x00000800,            /**< window not created by SDL */
    WINDOWFLAG_ALLOW_HIGHDPI = 0x00002000,      /**< window should be created in high-DPI mode if supported.
                                                     On macOS NSHighResolutionCapable must be set true in the
                                                     application's Info.plist for this to have any effect. */
    WINDOWFLAG_MOUSE_CAPTURE    = 0x00004000,   /**< window has mouse captured (unrelated to MOUSE_GRABBED) */
    WINDOWFLAG_ALWAYS_ON_TOP    = 0x00008000,   /**< window should always be above others */
    WINDOWFLAG_SKIP_TASKBAR     = 0x00010000,   /**< window should not be added to the taskbar */
    WINDOWFLAG_UTILITY          = 0x00020000,   /**< window should be treated as a utility window */
    WINDOWFLAG_TOOLTIP          = 0x00040000,   /**< window should be treated as a tooltip */
    WINDOWFLAG_POPUP_MENU       = 0x00080000,   /**< window should be treated as a popup menu */
    WINDOWFLAG_KEYBOARD_GRABBED = 0x00100000,   /**< window has grabbed keyboard input */
    WINDOWFLAG_INPUT_GRABBED    = WINDOWFLAG_MOUSE_GRABBED /**< equivalent to SDL_WINDOW_MOUSE_GRABBED for compatibility */
} WindowFlag;

typedef enum RendererFlag {
    RENDERERFLAG_NONE = 0x00000000,
    RENDERERFLAG_SOFTWARE = 0x00000001,         /**< The renderer is a software fallback */
    RENDERERFLAG_ACCELERATED = 0x00000002,      /**< The renderer uses hardware acceleration */
    RENDERERFLAG_PRESENTVSYNC = 0x00000004,     /**< Present is synchronized with the refresh rate */
    RENDERERFLAG_TARGETTEXTURE = 0x00000008     /**< The renderer supports rendering to texture */
} RendererFlag;

Window window_create(Alexandria* alexandria, const char* title, u32 x, u32 y, u32 width, u32 height, WindowFlag window_flags, RendererFlag renderer_flags);
void window_destroy(Window* self);
void window_mainloop(Window* self);
void window_center(Window* self);