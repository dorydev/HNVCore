#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>


void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS);
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}


int main(void) 
{

    if (!glfwInit())
    {
        // Initialization failed
        std::cout << "Window initialisation failed." << std::endl;
        return -1;
    }

    
    glfwWindowHint(GLFW_SAMPLES, 4); // AA
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow * window;

    window = glfwCreateWindow(1080, 720, "HNVCore", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create window with GLFW." << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent( window );

    /*if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }*/


    std::cout << "Build done" << std::endl;
    return 0;
}
