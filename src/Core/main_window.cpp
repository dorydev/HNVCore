#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 1080;
const unsigned int SCR_HEIGHT = 720;


int mainWindow(void) 
{
    std::cout << "Window creation has started...." << std::endl;

    // check if glfw initialize
    if(!glfwInit()) {
        std::cout << "Failled to initialize glfw." << std::endl; // oh miiiiiinnceeeee ;)
    }

    //setup glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //create window
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Yolo", nullptr, nullptr);
    glfwMakeContextCurrent( window );

    // check if window
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    //glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    double dt = 0.0;
    double lastframe = 0.0;
    // Render loop

    while (!glfwWindowShouldClose(window))
    {
        //update time
        dt = glfwGetTime() - lastframe;
        lastframe += dt;

        /* Render here */
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwSwapInterval(1);
    //glfwSetInputMode();

    glfwTerminate();


    return 0;
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
