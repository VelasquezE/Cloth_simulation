#pragma once
#include "../libraries.h"
#include "../rendering.h"
#include "systemDynamics.h"

void initialStep(std::vector<Particle> &system, const float &h);
void verletIntegration(std::vector<Particle> &system, const float &h);