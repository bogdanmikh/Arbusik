cmake_minimum_required(VERSION 3.16)

project("Dincka")

set(CMAKE_CXX_STANDARD 14)

add_executable(Dincka 
    src/main.cpp 
    src/Game/Camera.hpp
    src/Game/Camera.cpp
    src/Renderer/Renderer.cpp
    src/Renderer/Renderer.hpp
    src/Renderer/IndexBuffer.cpp
    src/Renderer/IndexBuffer.hpp
    src/Renderer/Mesh.cpp
    src/Renderer/Mesh.hpp
    src/Renderer/Shader.cpp
    src/Renderer/Shader.hpp
    src/Renderer/Texture.cpp
    src/Renderer/Texture.hpp
    src/Renderer/VertexArray.cpp
    src/Renderer/VertexArray.hpp
    src/Renderer/VertexBuffer.cpp
    src/Renderer/VertexBuffer.hpp
    src/Renderer/VertexBufferLayout.hpp
    src/Window/Key.hpp
    src/Window/Window.cpp
    src/Window/Window.hpp
)
target_include_directories(Dincka PRIVATE src)

# GLFW
add_subdirectory(vendor/glfw)

target_link_libraries(Dincka glfw)
target_include_directories(Dincka PRIVATE vendor/glfw/include)

# GLAD
add_subdirectory(vendor/glad)

target_link_libraries(Dincka glad)
target_include_directories(Dincka PRIVATE vendor/glad/include)

# GLM
add_subdirectory(vendor/glm)

target_link_libraries(Dincka glm)
target_include_directories(Dincka PRIVATE vendor/glm)

# STB_IMAGE
add_subdirectory(vendor/stb_image)

target_link_libraries(Dincka stb_image)
target_include_directories(Dincka PRIVATE vendor/stb_image)