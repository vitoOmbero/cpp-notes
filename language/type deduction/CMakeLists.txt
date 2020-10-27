cmake_minimum_required(VERSION 3.0)

project(first_lesson)
add_compile_options( -std=c++14 )
add_executable(${PROJECT_NAME} "main.cpp")
# add c++filt -t
