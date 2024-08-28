#pragma once
#include "../libraries.h"
#include "../rendering.h"

struct Particle
{
    glm::vec2 actualPosition = glm::vec2(0.0);
    glm::vec2 previousPosition = glm::vec2(0.0);
    glm::vec2 force = glm::vec2(0.0);
    glm::vec2 initialVelocity = glm::vec2(0.0);
    float mass{1};
    bool fixed{false};
};

void initializeParticles(std::vector<Particle> &system, const float particleSeparation);
void vertexArrayCreation(const std::vector<Particle> &system, std::vector<glm::vec2> &vertices);
void giveForces(std::vector<Particle> &system);