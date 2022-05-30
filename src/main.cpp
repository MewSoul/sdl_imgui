#include <iostream>

#include <flecs.h>
#include <glad/glad.h>
#include <imgui.h>
#include <imgui_impl_sdl.h>
#include <imgui_impl_opengl3.h>
#include <SDL.h>

#include "Input.h"
#include "Pipeline.h"
#include "Renderer.h"

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 720

bool InitSDL();
void ClearSDL(SDL_Window **pWindow, void **pContext);
void InitImGui(SDL_Window **pWindow, void **pContext);
void ClearImGui();

int main() {
    SDL_Window *pWindow;
    SDL_GLContext pContext;

    if (!InitSDL()) {
        std::cout << "Failed to initialize SDL2: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    pWindow = SDL_CreateWindow(
            "sdl_window",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );

    if (pWindow == nullptr) {
        std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    pContext = SDL_GL_CreateContext(pWindow);
    SDL_GL_MakeCurrent(pWindow, pContext);
    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

    InitImGui(&pWindow, &pContext);

    ecs_world_t *pWorld = ecs_init();
    Pipeline pipeline(pWorld);

    Input::Init(pWorld, pipeline);
    Renderer::Init(pWorld, pipeline, pWindow);

    ecs_set_pipeline(pWorld, pipeline.GetPipeline());

    while (ecs_progress(pWorld, 0.0)) {
    }

    ecs_fini(pWorld);
    ClearImGui();
    ClearSDL(&pWindow, &pContext);

    return EXIT_SUCCESS;
}

bool InitSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return false;

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    SDL_GL_SetAttribute(
            SDL_GL_CONTEXT_PROFILE_MASK,
            SDL_GL_CONTEXT_PROFILE_CORE
    );

#ifdef __APPLE__
    SDL_GL_SetAttribute(
            SDL_GL_CONTEXT_FLAGS,
            SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG
    );
#else
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
#endif

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    return true;
}

void ClearSDL(SDL_Window **pWindow, SDL_GLContext *pContext) {
    SDL_GL_DeleteContext(*pContext);
    SDL_DestroyWindow(*pWindow);
    SDL_Quit();
}

void InitImGui(SDL_Window **pWindow, SDL_GLContext *pContext) {
    ImGui::CreateContext();
    ImGui_ImplSDL2_InitForOpenGL(*pWindow, *pContext);
    ImGui_ImplOpenGL3_Init();
}

void ClearImGui() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}