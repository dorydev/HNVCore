//OpenGL library
#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>

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
#include "hypersphère.h"

//Global variables

const int MIN_SECTOR_COUNT = 3;
const int MIN_STACK_COUNT  = 2;

void Sphere::printSelf() const
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
}