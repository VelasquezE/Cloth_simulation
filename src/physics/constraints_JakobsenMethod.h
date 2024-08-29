#pragma once
#include "../libraries.h"
#include "../rendering.h"
#include "systemDynamics.h"

void relaxConstraint(Particle &part1, Particle &part2, const float d);
void jakobsen(std::vector<Particle> &system, const float d, const int n); // n is the number of particles
