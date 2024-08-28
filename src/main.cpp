#include "rendering.h"
#include "libraries.h"
#include "physics/systemDynamics.h"
#include "physics/updatePositions_verletIntegration.h"

int main(void)
{
    initializeGLFW();

    // Constants
    int N = 90;
    float particleSeparation = 0.0125;

    // Create system
    std::vector<Particle> system(N);
    initializeParticles(system, particleSeparation);

    std::vector<glm::vec2> vertices(N);
    vertexArrayCreation(system, vertices);

    float width = 800.0;
    float height = 800.0;

    GLFWwindow *window = glfwCreateWindow(width, height, "RopeSimulation", NULL, NULL);
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

    // Time step variables
    float h = 0.0f; // Delta time
    float lastFrame = 0.0f;

    // To know when to do the first step for Verlet
    int counter = 0;

    while (!glfwWindowShouldClose(window))
    {
        // Calculate delta time
        float currentFrame = glfwGetTime();
        h = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glfwPollEvents();

        processInput(window);

        // Update the system
        if (counter == 1) // Make initial step after static view
        {
            giveForces(system);
            initialStep(system, h);
        }
        if (counter > 1)
        {
            giveForces(system);
            verletIntegration(system, h);
        }

        // Update vertex positions
        vertexArrayCreation(system, vertices);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(glm::vec2), vertices.data());

        // Render
        glClearColor(0.733f, 0.733f, 0.733f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.use();

        glBindVertexArray(VAO);
        glDrawArrays(GL_POINTS, 0, vertices.size());

        glfwSwapBuffers(window);

        counter++;
    }

    glfwTerminate();

    return 0;
}
