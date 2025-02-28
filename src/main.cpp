//include OpenGL lib
#include <glad/glad.h>
#include <glm.hpp>
#include <glfw3.h>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <iostream>
//other libs
#include <string>
#include <vector>
#include <stack>

#include <iostream>
#include <fstream>
#include <sstream>
#include <streambuf>

#include <windows.h>
//#include <unistd.h>

// include paths
#include "Core/main_window.cpp"


int main(void) 
{
    std::cout << "Loading..." << std::endl;

    /*glm::vec4 vec(1.0f, 1.0f, 1.0f, 1.0f);
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 1.0f)); //translation
    trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0)); //rotation
    trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5)); //scaling
    vec = trans * vec;
    std::cout << vec.x << ' ' << vec.y << ' ' << vec.x << std::endl;*/

    //--------------------------------------------------------------

    mainWindow();
    return 0;
}

// catch errors

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

