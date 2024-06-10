#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shaders/Shader.h"

void framebufferSizeCallback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
void initializeGLFW(void);
void initializeGlad(void);
bool checkWindowCreation(GLFWwindow *window);
