cmake_minimum_required(VERSION 3.16)

project("Arbusik")

set(CMAKE_CXX_STANDARD 14)

add_executable(Arbusik src/main.cpp)

# GLFW
add_subdirectory(vendor/glfw)

target_link_libraries(Arbusik glfw)
target_include_directories(Arbusik PRIVATE vendor/glfw/include)

# GLAD
add_subdirectory(vendor/glad)

target_link_libraries(Arbusik glad)
target_include_directories(Arbusik PRIVATE vendor/glad/include)