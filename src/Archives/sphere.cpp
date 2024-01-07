//OpenGL library
#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>
#include <math.h>

//global include
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <cmath>

//other libs
#include <string>
#include <vector>
#include <stack>

//Include path
#include "sphere.h"

const float steps = 10;
const float angle = 3.1415926 * 2.f /steps;

float xPos = 0;
float yPos = 0;
float radius = 1.0f;

void drawCercle()
{

    float prevX = xPos;
    float prevY = yPos - radius;

    for (int i=0; i<=steps; i++)
    {
        float newX = radius * sin(angle*i);
        float newY = -radius * cos(angle*i);

        glBegin(GL_TRIANGLES);
        glColor3f(0, 0.5f, 0);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(prevX, prevY, 0.0f);
        glVertex3f(newX, newY, 0.0f);
        glEnd();

        float prevX = newX;
        float prevY = newY;

    }
}

/*void Sphere::printSelf() const
{
    std::cout << "===== Sphere =====\n"
              << "        Radius: " << radius << "\n"
              << "  Sector Count: " << sectorCount << "\n"
              << "   Stack Count: " << stackCount << "\n"
              << "Smooth Shading: " << (smooth ? "true" : "false") << "\n"
              << "       Up Axis: " << (upAxis == 1 ? "X" : (upAxis == 2 ? "Y" : "Z")) << "\n"
              << "Triangle Count: " << getTriangleCount() << "\n"
              << "   Index Count: " << getIndexCount() << "\n"
              << "  Vertex Count: " << getVertexCount() << "\n"
              << "  Normal Count: " << getNormalCount() << "\n"
              << "TexCoord Count: " << getTexCoordCount() << std::endl;
}*/