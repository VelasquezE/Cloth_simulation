#include "updatePositions_verletIntegration.h"

void initialStep(std::vector<Particle> &system, const float &h)
{
    for (auto &p : system)
    {
        if (!p.fixed)
        {
            for (int ii = 0; ii < 2; ii++)
            {
                // Save current position to previous position
                p.previousPosition[ii] = p.actualPosition[ii];

                p.actualPosition[ii] = p.actualPosition[ii] + (p.initialVelocity[ii] * h) +
                                       (0.5 * (p.force[ii] / p.mass) * h * h);
            }
        }
    }
}

void verletIntegration(std::vector<Particle> &system, const float &h)
{
    for (auto &p : system)
    {
        if (!p.fixed)
        {
            // Temporal vector to save new position
            glm::vec2 newPosition = glm::vec2(0.0);

            for (int ii = 0; ii < 2; ii++)
            {
                newPosition[ii] = (2 * p.actualPosition[ii]) - p.previousPosition[ii] +
                                  (h * h * (p.force[ii] / p.mass));
            }

            p.previousPosition = p.actualPosition;
            p.actualPosition = newPosition;
        }
    }
}
