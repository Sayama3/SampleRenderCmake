cmake_minimum_required(VERSION 3.20)

#glad
add_subdirectory(glad)

#glfw
add_subdirectory(glfw)

set(IMGUI_GLFW ON)
set(IMGUI_OPENGL3 ON)
set(IMGUI_OPENGL3_LOADER ON)

#imgui
add_subdirectory(imgui)
target_link_libraries(imgui PUBLIC glfw)