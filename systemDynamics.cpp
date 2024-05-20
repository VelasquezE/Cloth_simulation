/*

function giveSecondInitialPosition
         Estimate second initial position for Verlet
         x(h) = x(0) + v(0) * h + 1/2 * a(0) * h^{2}



function getAcceleration
         This function must recibe the state vector
         and give the vector with the accelerations
         - gravity is the only force acting over each particle
         int G = 10;
         std::vector<double> G{0, G, 0};
         F = ma = -mg
         a = -g

*/