cmake_minimum_required(VERSION 3.21)
include(FetchContent)
project(sdl_imgui)

set(CMAKE_CXX_STANDARD 11)

FetchContent_Declare(
        flecs
        URL https://github.com/SanderMertens/flecs/archive/3e34ea3acc88b182cd3277fae13d1b596affe07d.tar.gz # master
)
FetchContent_MakeAvailable(flecs)

set(SDL_STATIC OFF CACHE BOOL "Static SDL2")
set(SDL_SHARED ON CACHE BOOL "Shared SDL2")
FetchContent_Declare(
        SDL2
        URL https://www.libsdl.org/release/SDL2-2.0.20.tar.gz
)
FetchContent_MakeAvailable(SDL2)

FetchContent_Declare(
        glad
        URL https://github.com/Dav1dde/glad/archive/1ecd45775d96f35170458e6b148eb0708967e402.tar.gz # master
)
FetchContent_MakeAvailable(glad)

add_subdirectory(third_party/imgui)

include_directories(include)

file(GLOB_RECURSE sdl_imgui_src src/*)
add_executable(sdl_imgui ${sdl_imgui_src})

target_link_libraries(sdl_imgui flecs SDL2main SDL2 imgui glad)