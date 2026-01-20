cmake_minimum_required(VERSION 3.10)
project(TaskManager)

file(GLOB_RECURSE srcs
    src/*.h
    src/*.cpp
)

add_executable(task-manager
    ${srcs}
)

target_compile_options(task-manager
    PRIVATE
        -std=c++17
        -Wall
        -Wextra
        -Werror
)