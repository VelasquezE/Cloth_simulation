#pragma once
#include "../libraries.h"
#include "../rendering.h"
#include "systemDynamics.h"

void relaxConstraint(const int iter, glm::vec2 &part1, glm::vec2 &part2,const float d);
void jakobsen(std::vector<Particle> &system, const int n);
