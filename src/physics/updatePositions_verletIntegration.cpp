/*
f(t + h) = 2 * f(t) - f(t - h) + h^{2} * a(t)

- we do not use velocity explicity
- we must have two position values

function verletIntegration(particles, h)
         for all particles p do
         positionCopy <- p.position
         p.position <- 2 * p.position - p.previousPosition + h^{2} p.getAcceleration()
         p.previousPosition <- positionCopy

*/