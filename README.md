# Rope simulation
Final project for Introduction to C++ and Numerical Methods. GitHub repository: https://github.com/VelasquezE/Rope_simulation.

### General objective
Simulate a rope under the effect of gravity and the inner interactions between the segments. 

### Specific objectives
1. Install and get familiarize with the necessary libraries for rendering the rope with OpenGL
2. Visualize the system of particles as an static rope
3. Implement the Verlet integration method for updating the positions of the points that make up the rope
4. Implement the constraint between segments using the Jakobsen method
5. Visualize the movement of the rope using OpenGL and allowing the interaction with the user

# Windows building
All relevant libraries are found in /dependencies. It is necessary to download and configure CMake
(https://cmake.org/download/). Run CMake script and generate project of choice.

# Linux/WSL building
It is necessary to have CMake, Git and the required packages: Using root (sudo) and type ```apt-get install libsoil-dev
libglm-dev libglew-dev libglfw3-dev```

### Build through CMake command line:
```
cd /path/to
mkdir build && cd build
cmake ..
make
```
