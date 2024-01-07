#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

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

//shaders

bool loadShaders(GLuint &program)
{
	char infoLog[512];
	GLuint success;

	//load shaders from file:

	std::string temp = "";
	std::string src = "";

	std::ifstream in_file;

	//vertex
	in_file.open("Ressources_files/vertex.glsl");

	if (in_file.is_open())
	{
		while (std::getline(in_file, temp))
		{
			src += temp + "\n";
		}
	} else {
		std::cout << "(-) Failed to load Shaders::COULD_NOT_OPEN_VERTEX_FILE" << "\n" << std::endl;
	}

	in_file.close();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	const GLchar* vertexSrc = src.c_str();
	glShaderSource(vertexShader, 1, &vertexSrc, NULL);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "(-) Failed to load Shaders::COULD_NOT_COMPILE_VERTEX_SHADERS" << "\n" << std::endl;
		std::cout << infoLog << "\n" << std::endl;
	}

	temp = "";
	src = "";

	//fragment

	in_file.open("Ressources_files/fragment.glsl");

	if (in_file.is_open())
	{
		while (std::getline(in_file, temp))
		{
			src += temp + "\n";
		}
	} else {
		std::cout << "(-) Failed to load Shaders::COULD_NOT_OPEN_FRAGMENT_FILE" << "\n" << std::endl;
	}

	in_file.close();

	GLuint fragmentShader = glCreateShader(GL_VERTEX_SHADER);

	const GLchar* fragmentSrc = src.c_str();
	glShaderSource(fragmentShader, 1, &vertexSrc, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "(-) Failed to load Shaders::COULD_NOT_COMPILE_FRAGMENT_SHADERS" << "\n" << std::endl;
		std::cout << infoLog << "\n" << std::endl;
	}

	temp = "";
	src = "";

	//program
	program = glCreateProgram();

	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);

	//end

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return;
}


int mainWindow() 
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
    //update time
    dt = glfwGetTime() - lastframe;
    lastframe += dt;
    glfwWaitEventsTimeout(0.001);


    // Render loop
    while (!glfwWindowShouldClose(window))
    {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/* Render here */
    	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		//shader init:

		GLuint core_program;
		loadShaders(core_program);

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
