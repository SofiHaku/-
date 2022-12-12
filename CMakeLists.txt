cmake_minimum_required(VERSION 3.12) # version can be different

project(my_cpp_project) #name of your project

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(mytests tests.cpp string.cpp string.hpp) # add this executable

target_link_libraries(mytests PRIVATE gtest) # link google test to this executable

add_compile_options(-pedantic -Werror -Wextra -fsanitize=address -fsanitize=undefined -std=c++17)

add_link_options(-pedantic -Werror -Wextra -fsanitize=address -fsanitize=undefined -std=c++17)