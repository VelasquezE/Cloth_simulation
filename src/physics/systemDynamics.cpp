#include "systemDynamics.h"

void initializeParticles(std::vector<Particle> &system, const float particleSeparation)
{
    int n = system.size();
    float yPosition = 0.5f;

    for (int ii = 0; ii < n; ii++)
    {
        // Prevent first particle for moving
        if (ii == 0)
        {
            system[ii].fixed = true;
        }

        // Initialize position
        system[ii].actualPosition.x = 0.0f;
        system[ii].actualPosition.y = yPosition;

        yPosition -= particleSeparation;

        if (ii == (n - 1))
        {
            system[ii].initialVelocity.x = 4.5f;
        }
    }
}

void vertexArrayCreation(const std::vector<Particle> &system,
                         std::vector<glm::vec2> &vertices)
{
    for (int ii = 0; ii < system.size(); ii++)
    {
        vertices[ii] = system[ii].actualPosition;
    }
}

void giveForces(std::vector<Particle> &system)
{
    // Reset forces
    for (auto &particle : system)
    {
        particle.force = glm::vec2(0.0);
    }

    // Gravity
    float G = 9.81; // m/s^2

    for (auto &particle : system)
    {
        particle.force.y -= particle.mass * G;
    }
}