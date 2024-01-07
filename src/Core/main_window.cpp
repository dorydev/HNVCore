#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>

//external paths

//other libs
#include <string>
#include <vector>
#include <stack>

//callback signatures
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

//GLOBAL variables
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
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "HNVCore", nullptr, nullptr);
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

    GLuint VertexArrayID; 
    glGenVertexArrays(1, &VertexArrayID); 
    glBindVertexArray(VertexArrayID);

    static const GLfloat g_vertex_buffer_data[] = { 
        -1.0f, -1.0f, 0.0f, 
        1.0f, -1.0f, 0.0f, 
        0.0f,  1.0f, 0.0f, 
    };

    // Ceci identifiera notre tampon de sommets
    GLuint vertexbuffer; 
    
    // Génère un tampon et place l'identifiant dans 'vertexbuffer'
    glGenBuffers(1, &vertexbuffer); 
    
    // Les commandes suivantes vont parler de notre tampon 'vertexbuffer'
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer); 
    
    // Fournit les sommets à OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        //update time
        dt = glfwGetTime() - lastframe;
        lastframe += dt;

        glfwWaitEventsTimeout(0.001);


        /* Render here */
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // premier tampon d'attributs : les sommets
        glEnableVertexAttribArray(0); 
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer); 
        glVertexAttribPointer( 
            0,                  // attribut 0. Aucune raison particulière pour 0, mais cela doit correspondre au « layout » dans le shader 
            3,                  // taille
            GL_FLOAT,           // type 
            GL_FALSE,           // normalisé ? 
            0,                  // nombre d'octets séparant deux sommets dans le tampon
            (void*)0            // décalage du tableau de tampon
        ); 
        
        // Dessine le triangle ! 
        glDrawArrays(GL_TRIANGLES, 0, 3); // Démarre à partir du sommet 0; 3 sommets au total -> 1 triangle 
        
        glDisableVertexAttribArray(0);


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
