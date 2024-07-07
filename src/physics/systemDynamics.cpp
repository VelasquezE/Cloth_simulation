#include "systemDynamics.h"

void initializeParticles(const int n, std::vector<Particle> &system, const float particleSeparation)
{
    float yPosition = 0.5f;

    for (int ii = 0; ii <= n; ii++)
    {
        if (ii == 0)
        {
            system[ii].fixed = true;
        }
        system[ii].actualPosition.x = 0.0f;
        system[ii].actualPosition.y = yPosition;

        yPosition -= particleSeparation;
    }
}

void vertexArrayCreation(const int n, const std::vector<Particle> system,
                         std::vector<glm::vec2> &vertices)
{
    for (int ii = 0; ii <= n; ii++)
    {
        vertices[ii] = system[ii].actualPosition;
    }
}

/*

function giveSecondInitialPosition
         Estimate second initial position for Verlet
         x(h) = x(0) + v(0) * h + 1/2 * a(0) * h^{2}

function computeForce
         This function must recibe the system
         and fill the force on each particle
         - gravity is the "only" force acting over each particle
         int G = 10; We can add a map
         F = ma = -mg
*/