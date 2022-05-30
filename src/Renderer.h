
#ifndef SDL_IMGUI_RENDERER_H
#define SDL_IMGUI_RENDERER_H

#include <flecs.h>
#include <SDL.h>

#include "Pipeline.h"

class Renderer {
public:
    static void Init(ecs_world_t *pWorld, const Pipeline &pipeline, SDL_Window *pWindow);
};


#endif //SDL_IMGUI_RENDERER_H
