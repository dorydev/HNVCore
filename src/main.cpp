#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>

#define GLFW_INCLUDE_NONE
#define GLFW_DLL


void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}


int main(void) {

    if (glfwInit())
    {
        std::cout << "GLFW init success !" << std::endl;

        GLFWwindow* window = glfwCreateWindow(1080, 720, "HNVCore", nullptr, nullptr);
        glfwMakeContextCurrent(window);

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Can't link glad" << std::endl;
        }
    }

    std::cout << "Build done" << std::endl;
    return 0;
}

