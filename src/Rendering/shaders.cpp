#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>

#include "shaders.h"

#include <stdio.h>
#include <fstream>

static int Shaders(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShaders(vertexShader, GL_VERTEX_SHADER);
}

static int CompileShaders(const std::string& source, unsigned int type)
{
    unsigned int id = glCreateShader(GL_VERTEX_SHADER);
}

/*
std::string loadShadersSrc(const char* filename)
{
    std::ifstream file;
    std::stringstream buf;

    std::string ret = "";

    file.open(filename);
    
    if(file.is_open())
    {
        buf << file.rdbuf();
        ret = buf.str();
    }
    else
    {
        std::cout << "Cannot open" << filename << std::endl;
    }

    file.close();
    return ret;
}*/