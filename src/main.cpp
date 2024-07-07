#include "rendering.h"
#include "libraries.h"
#include "physics/systemDynamics.h"

int main(void)
{
    initializeGLFW();

    const int N = 100; // Has to be an even value
    const float particleSeparation = 0.0125;
    std::vector<Particle> system(N);
    initializeParticles(N, system, particleSeparation);

    std::vector<glm::vec2> vertices(N);
    vertexArrayCreation(N, system, vertices);

    float width = 800.0;
    float height = 800.0;

    GLFWwindow *window = glfwCreateWindow(width, height, "ClothSimulation", NULL, NULL);
    checkWindowCreation(window);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    initializeGlad();

    glViewport(0, 0, width, height);

    Shader shaderProgram("../src/shaders/vertexShader.vs",
                         "../src/shaders/fragmentShader.fs",
                         "../src/shaders/geometryShader.gs");

    // Create vertex buffer/array object
    unsigned int VBO;
    unsigned int VAO;
    // Generate a buffer ID
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);
    // Specify the type of the buffer object
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // Initializes a buffer object's data
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec2), vertices.data(), GL_DYNAMIC_DRAW);

    //  Interpret vertex data
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void *)0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.733f, 0.733f, 0.733f, 1.0f);
        processInput(window);

        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.use();

        glBindVertexArray(VAO);
        glDrawArrays(GL_POINTS, 0, vertices.size());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
