cmake_minimum_required(VERSION 3.16)

project("Dincka")

set(CMAKE_CXX_STANDARD 14)

add_executable(Dincka src/main.cpp)

# GLFW
add_subdirectory(vendor/glfw)

target_link_libraries(Dincka glfw)
target_include_directories(Dincka PRIVATE vendor/glfw/include)

# GLAD
add_subdirectory(vendor/glad)

target_link_libraries(Dincka glad)
target_include_directories(Dincka PRIVATE vendor/glad/include)