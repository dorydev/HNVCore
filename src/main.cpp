//include lib
#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>

#include <string>
#include <vector>
#include <stack>

// include paths
#include "Core/main_window.cpp"


int main(void) 
{
    std::cout << "Running code" << std::endl;

    mainWindow();
    return 0;
}

// catch errors

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS);
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}
