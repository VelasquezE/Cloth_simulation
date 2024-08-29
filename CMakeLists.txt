cmake_minimum_required(VERSION 3.29.3)
project(rope_simulation VERSION 1.0.0)

find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME} 
               src/libraries.h 
               src/rendering.h
               src/rendering.cpp
               src/glad.c
               src/shaders/Shader.cpp
               src/physics/systemDynamics.h
               src/physics/systemDynamics.cpp
               src/physics/updatePositions_verletIntegration.h
               src/physics/updatePositions_verletIntegration.cpp
               src/physics/constraints_JakobsenMethod.cpp
               src/physics/constraints_JakobsenMethod.h
               src/main.cpp
               )

target_include_directories(${PROJECT_NAME} PRIVATE dependencies)

target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL)