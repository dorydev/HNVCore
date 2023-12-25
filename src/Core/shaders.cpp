#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>


#include <stdio.h>
#include <fstream>

static int CompileShaders( unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(GL_VERTEX_SHADER);

    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr); //glShaderSource(glCreateShader(), 1, ptr, ptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);


    //Shader info log (compile error)
    if (result == GL_FALSE)
    {
        int length;

        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));

        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "Failled to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shaders." << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    //ERROR handling:

    return(id);
}


static unsigned int createShaders(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShaders(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShaders(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}