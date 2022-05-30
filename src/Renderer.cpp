
#include "Renderer.h"

#include <glad/glad.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl.h>

void DrawSystem(ecs_iter_t *pIt) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    ImGui::ShowDemoWindow();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    auto *pWindow = static_cast<SDL_Window *>(pIt->ctx);
    SDL_GL_SwapWindow(pWindow);
}

void Renderer::Init(ecs_world_t *pWorld, const Pipeline &pipeline, SDL_Window *pWindow) {
    ecs_system_desc_t drawSystemDesc = {
            .entity = {
                    .add = {pipeline.GetDrawPhase()}
            },
            .callback = DrawSystem,
            .ctx = pWindow
    };

    ecs_system_init(pWorld, &drawSystemDesc);
}