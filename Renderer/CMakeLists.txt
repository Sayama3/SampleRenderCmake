cmake_minimum_required(VERSION 3.20)

set(SRC
        src/main.cpp
)

add_executable(Renderer ${SRC})

target_include_directories(Renderer PUBLIC include)
target_include_directories(Renderer PRIVATE src)

target_link_libraries(Renderer PUBLIC glad glfw imgui)