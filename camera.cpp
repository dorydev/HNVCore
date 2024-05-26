#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <iostream>

//other libs
#include <string>
#include <vector>
#include <stack>
#include <cmath>

void keyboardMouseIO()
{

    double currentTime = glfwGetTime();
    float deltaTime = float(currentTime - lastTime);

    glm::vec3 pos = glm::vec3(0 , 0, 0, 5);

    float horizontal = 3.14f;
    float vertical = 0.0f;
    float initFov = 45.0f;

    float speed = 3.0f;
    float mouseSpeed = 0.005f;

    int xPos;
    int yPos;

    glfwGetMousePos(&xPos, &yPos);
    glfwSetMousePos(1024/2, 768/2);


    horizontal += mouseSpeed * deltaTime * float(1024/2 - xPos);
    vertical += mouseSpeed * deltaTime * float(768/2 - yPos);

    glm::vec3 direction(
        cos(vertical) * sin(horizontal),
        sin(vertical),
        cos(vertical) * cos(horizontal)
    );

    glm::vec3 right(
        sin(horizontal - 3.14f/2.0f),
        0,
        cos(horizontal - 3.14f/2.0f)
    );

    glm::vec3 up = glm::cross(right, direction);

    //Move:

    if (glfwGetKey(GLFW_KEY_UP) == GLFW_PRESS)
    {
        pos += direction * deltaTime * speed;
    }

}   