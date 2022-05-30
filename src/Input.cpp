
#include "Input.h"

#include <imgui_impl_sdl.h>
#include <SDL.h>

void InputSystem(ecs_iter_t *pIt) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL2_ProcessEvent(&event);

        if (event.key.keysym.sym == SDLK_ESCAPE) {
            ecs_quit(pIt->world);
        }
    }
}

void Input::Init(ecs_world_t *pWorld, const Pipeline &pipeline) {
    ecs_system_desc_t inputSystemDesc = {
            .entity = {
                    .add = {pipeline.GetInputPhase()}
            },
            .callback = InputSystem
    };

    ecs_system_init(pWorld, &inputSystemDesc);
}
