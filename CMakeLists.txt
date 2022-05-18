cmake_minimum_required(VERSION 3.21)
include(FetchContent)
project(sdl_imgui)

set(CMAKE_CXX_STANDARD 11)

# flecs
FetchContent_Declare(
        flecs
        GIT_REPOSITORY https://github.com/SanderMertens/flecs.git
        GIT_TAG ae3a6c08b62369a5c446f3755b5e364d638e7133
)
FetchContent_MakeAvailable(flecs)

# SDL2
set(SDL_STATIC OFF CACHE BOOL "Static SDL2")
set(SDL_SHARED ON CACHE BOOL "Shared SDL2")
FetchContent_Declare(
        SDL2
        URL https://www.libsdl.org/release/SDL2-2.0.20.tar.gz
)
FetchContent_MakeAvailable(SDL2)

# glad
FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
        GIT_TAG 1ecd45775d96f35170458e6b148eb0708967e402
)
FetchContent_MakeAvailable(glad)

add_subdirectory(third_party/imgui)

include_directories(include)

file(GLOB_RECURSE sdl_imgui_src src/*)
add_executable(sdl_imgui ${sdl_imgui_src})

target_link_libraries(sdl_imgui flecs SDL2main SDL2 imgui glad)