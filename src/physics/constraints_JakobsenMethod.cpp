/*
1. Calculate the distance between two points
2. If it's closer than the constraint requirement, push both away
3. If it's further then the constraint requirement, pull both together
4. Repeat

function relaxConstraint(particle1, particle2, desiredDistance)
         direction <- normalize(particle2.position - particle1.position)
         delta d <- distance(particle1, particle2) - desiredDistance
         particle1.position.add(delta d direction / 2)
         particle2.position.add(delta d direction / 2)

function jakobsen (constraints, n)
    d (desired distant between particles)
    repeat n times
        for all constraints (particle1, particle2, desiredDistance)
            relaxConstraint (particle1, particle2, desiredDistance)

if one particle is fixed, the other moves the entire distance
*/