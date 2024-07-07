#include "Shader.h"

Shader::Shader(const char *vertexPath, const char *fragmentPath, const char *geometryPath)
{
    // Retrieve vertex/fragment source code from filepath
    std::string vertexCode{};
    std::string fragmentCode{};
    std::string geometryCode{};
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    std::ifstream gShaderFile;
    //  Ensure ifstream objects can throw exceptions
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    gShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // Open files
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        gShaderFile.open(geometryPath);
        std::stringstream vShaderStream{};
        std::stringstream fShaderStream{};
        std::stringstream gShaderStream{};
        // Read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        gShaderStream << gShaderFile.rdbuf();
        //  Close file handlers
        vShaderFile.close();
        fShaderFile.close();
        gShaderFile.close();
        //  Convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
        geometryCode = gShaderStream.str();
    }
    catch (const std::ifstream::failure &e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << '\n';
    }
    // From string to char*
    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();
    const char *gShaderCode = geometryCode.c_str();

    // Compile shaders
    // Vertex Shader
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // Attach shader source code to shader object
    glShaderSource(vertexShader, 1, &vShaderCode, NULL);
    glCompileShader(vertexShader);
    checkCompileErrors(vertexShader, "VERTEX");

    // Create fragment shader object
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShader);
    checkCompileErrors(fragmentShader, "FRAGMENT");

    // Geometry shader
    unsigned int geometryShader;
    geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
    glShaderSource(geometryShader, 1, &gShaderCode, NULL);
    glCompileShader(geometryShader);
    checkCompileErrors(geometryShader, "GEOMETRY");

    // Create shader program
    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glAttachShader(ID, geometryShader);
    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");

    // Delete shader objects
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(geometryShader);
}

void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
    int success;
    char infoLog[512];

    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                      << infoLog << "\n";
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            std::cout << "ERROR::LINKING::SHADER_PROGRAM::COMPILATION_FAILED\n"
                      << infoLog << "\n";
        }
    }
}

void Shader::use()
{
    glUseProgram(ID);
}

void Shader::set4FloatUniform(const std::string &name, float value1, float value2, float value3, float value4)
{
    glUniform4f(glGetUniformLocation(ID, name.c_str()), value1, value2, value3, value4);
}

void Shader::set2FloatUniform(const std::string &name, float value1, float value2)
{
    glUniform2f(glGetUniformLocation(ID, name.c_str()), value1, value2);
}