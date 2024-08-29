#include "constraints_JakobsenMethod.h"

void relaxConstraint(Particle &part1, Particle &part2, const float d)
{
    // The vector that I'm proposing goes from particle 1 to particle 2
    float dx = part2.actualPosition.x - part1.actualPosition.x;
    float dy = part2.actualPosition.y - part1.actualPosition.y;
    float separation = std::sqrt((dx * dx) + (dy * dy));

    // Avoid dividing by zero by exiting the function
    if (separation == 0.0f)
    {
        return;
    }

    // Normalize vector
    float direcx = dx / separation;
    float direcy = dy / separation;

    float delta = separation - d; // The distance that is exceeded

    if (delta == 0)
    {
        return;
    }

    float adjustment = 0.5 * delta;

    if (part1.fixed)
    {
        part2.actualPosition.x -= delta * direcx;
        part2.actualPosition.y -= delta * direcy;
    }
    else
    {
        part1.actualPosition.x += adjustment * direcx;
        part1.actualPosition.y += adjustment * direcy;

        part2.actualPosition.x -= adjustment * direcx;
        part2.actualPosition.y -= adjustment * direcy;
    }
}

void jakobsen(std::vector<Particle> &system, const float d, const int n) // n is the number of particles
{
    int m = 3000; // The number of adjusting cycles

    for (int jj = 0; jj < m; jj++) // adjusting cycles
    {
        for (int ii = 0; ii < (n - 1); ii++) // Run over all couple of particles
        {
            relaxConstraint(system[ii], system[ii + 1], d);
        }
    }
}