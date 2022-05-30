
#ifndef SDL_IMGUI_INPUT_H
#define SDL_IMGUI_INPUT_H

#include <flecs.h>

#include "Pipeline.h"

class Input {
public:
    static void Init(ecs_world_t *pWorld, const Pipeline &pipeline);
};


#endif //SDL_IMGUI_INPUT_H
