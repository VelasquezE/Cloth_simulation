#include "constraints_JakobsenMethod.h"


void relaxConstraint(const int iter, glm::vec2 &part1, glm::vec2 &part2,const float d)
{
    //the vector that I'm proposing goes from particle 1 to particle 2
    float separation = std::sqrt((part2.x-part1.x)*(part2.x-part1.x) + (part2.y-part1.y)*(part2.y-part1.y));
    float direcx = (part2.x-part1.x)/separation;
    float direcy = (part2.y-part1.y)/separation;

    float delta = separation - d; //The distance that is exceeded or that need the separation to be the desired

    if(iter == 0)
    {
        part2.x = part2.x - delta*direcx;
        part2.y = part2.x - delta*direcy;
    }
    else
    {
        part1.x = part1.x + 0.5*delta*direcx;
        part1.y = part1.y + 0.5*delta*direcy;
        part2.x = part2.x - 0.5*delta*direcx;
        part2.y = part2.x - 0.5*delta*direcy;
    }
}


void jakobsen(std::vector<Particle> &system, const int n) //n is the number of particles
{
    float d = 0.5f; //Desired position, equal to ypostion in initializeParticles

    int m = 10; //The number of adjustin cycles
    for(int jj = 0 ; jj < m ; jj++) //adjustin cycles
    {
        for(int ii = 0 ; ii < n ; ii++) //Run over all couple of particles
        {
            relaxConstraint(ii, system[ii].actualPosition, system[ii + 1].actualPosition, d);
        }
    }
}