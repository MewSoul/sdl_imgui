cmake_minimum_required(VERSION 3.21)
project(imgui)

add_library(imgui STATIC
        imgui/imgui.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp imgui/imgui_demo.cpp
        imgui/backends/imgui_impl_opengl3.cpp
        imgui/backends/imgui_impl_sdl.cpp
        imgui/misc/cpp/imgui_stdlib.cpp)
target_include_directories(imgui PUBLIC imgui/backends imgui)
target_link_libraries(imgui ${CMAKE_DL_LIBS} SDL2)