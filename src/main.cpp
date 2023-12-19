#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);

const unsigned int SCR_WIDTH = 1080;
const unsigned int SCR_HEIGHT = 720;

/*void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS);
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}*/


int main(void) 
{
    std::cout << "Hello World!" << std::endl;

    if(!glfwInit()) {
        std::cout << "oooh miiiiiince" << std::endl;
    }

    GLFWwindow* window = glfwCreateWindow(500, 500, "Yolo", nullptr, nullptr);
    glfwMakeContextCurrent( window );

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    return 0;
}
