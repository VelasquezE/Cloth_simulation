#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>

class Shader
{
public:
    // program ID
    unsigned int ID;

    // constructor reads and builds the shader
    Shader(const char *vertexPath, const char *fragmentPath, const char *geometryPath);
    // use/activate the shader
    void use();

    // Uniforms
    void set4FloatUniform(const std::string &name, float value1, float value2, float value3, float value4);
    void set2FloatUniform(const std::string &name, float value1, float value2);

private:
    void checkCompileErrors(unsigned int shader, std::string type);
};