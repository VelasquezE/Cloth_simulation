#pragma once
#include "../libraries.h"
#include "../rendering.h"

struct Particle
{
    glm::vec2 actualPosition = glm::vec2(0.0f, 0.0f);
    glm::vec2 previousPosition = glm::vec2(0.0f, 0.0f);
    glm::vec2 force = glm::vec2(0.0f, 0.0f);
    double mass{1};
    bool fixed{false};
};

void initializeParticles(const int n, std::vector<Particle> &system, const float particleSeparation);
void vertexArrayCreation(const int n, const std::vector<Particle> system, std::vector<glm::vec2> &vertices);