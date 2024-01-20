/*#ifndef CAMERA_H
#define CAMERA_H

//include libs
#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

class OrbitalCamera
{
    public:

        glm::vec3 Position;
        glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);   
        glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

        int width;
        int height;

        float speed = 0.1f;
        float sensivity = 100.0f;

        OrbitalCamera(int width, int height, glm::vec3 position);
        void Matrix(float FOVdeg, float nearPlane, float farPlane, const char* uniform);
        void Inputs(GLFWwindow* window);

    private: 
};

#endif*/