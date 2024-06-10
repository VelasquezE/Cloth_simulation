#include "rendering.h"
#include "libraries.h"

int main(void)
{
    /*
    Constants
    ----------
    h (timestep)
    N (number of particles)
    */

    /*
    Initial state vector (initial positions)
    ------------------------------------------------------
    std::vector<double> initialState(N);
        -Each element must be a vector with the data of x, y and z
    */

    initializeGLFW();

    int width = 800;
    int height = 600;

    GLFWwindow *window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
    checkWindowCreation(window);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    initializeGlad();

    glViewport(0, 0, width, height);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
