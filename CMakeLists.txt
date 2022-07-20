cmake_minimum_required(VERSION 3.16)

project("Dincka")

set(CMAKE_CXX_STANDARD 14)

set(BIN_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(Dincka 
    src/main.cpp 
    src/Application/Application.hpp
    src/Application/Application.cpp
    src/Game/World.hpp
    src/Game/World.cpp
    src/Game/Level.hpp
    src/Game/Direction.hpp
    src/Game/GameObject/GameObject.hpp
    src/Game/GameObject/GameObject.cpp
    src/Game/Core/Camera.hpp
    src/Game/Core/Camera.cpp
    src/Game/Core/CollisionDetector.hpp
    src/Game/Core/CollisionDetector.cpp
    src/Game/Core/Sprite.hpp
    src/Game/Core/Sprite.cpp
    src/Game/Levels/FirstLevel.hpp
    src/Game/Levels/FirstLevel.cpp
    src/Game/Scripts/Player.hpp
    src/Game/Scripts/Player.cpp
    src/Game/Scripts/Ground.hpp
    src/Game/Scripts/Ground.cpp
    src/Game/Scripts/Enemy.hpp
    src/Game/Scripts/Enemy.cpp
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

# set output directories for all builds (Debug, Release, etc.)
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set_target_properties(Dincka
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${BIN_DIRECTORY}
    )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )