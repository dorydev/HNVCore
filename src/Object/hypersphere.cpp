#include <iostream>
#include <glad/glad.h>
#include <glfw3.h>
#include <glm.hpp>

void objectHyperSphere(float radius, int rings,int slices)
{
    int faces = slices * rings;
    int nbV = slices * rings;
 
    //Allocation de mémoire
    float * v = new float[3 * nbV];
    float * n = new float[3 * nbV];
    float * tex = new float[2 * nbV];
    unsigned int * id = new unsigned int[6 * faces];
 
    //GENERATION DE LA SPHERE
    float x,y,z,r,s;
    int idx = 0, tidx = 0;
 
    float const R = 1.f/(float)(rings-1);
    float const S = 1.f/(float)(slices-1);
 
    for(r = 0; r < rings; ++r) {
        for(s = 0; s < slices; ++s) {
            x = cos( 2 * M_PI * s * S) * sin( M_PI * r * R );
            z = sin( 2 * M_PI * s * S) * sin( M_PI * r * R );
            y = sin(-M_PI_2 + (M_PI * r * R));
 
            verts[idx]     = x * radius;
            verts[idx + 1] = y * radius;
            verts[idx + 2] = z * radius;
 
            norms[idx]     = x;
            norms[idx + 1] = y;
            norms[idx + 2] = z;
 
            idx += 3;
 
            tex[tidx] = s*S;
            tex[tidx+1] = r*R;
            tidx += 2;
        }
    }
 
    idx = 0;
    int ringStart, nextRingStart,nextslice;
    for( r = 0; r < rings; r++ ) {
        ringStart = r * slices;
        nextRingStart = (r + 1) * slices;
        for( s = 0; s < slices; s++ ) {
            nextslice = s+1;
            // The quad
            id[idx]   = ringStart + s;
            id[idx+1] = nextRingStart + s;
            id[idx+2] = nextRingStart + nextslice;
            id[idx+3] = ringStart + s;
            id[idx+4] = nextRingStart + nextslice;
            id[idx+5] = ringStart + nextslice;
            idx += 6;
        }
    }
 
    //CREATION DU VBO ET VAO (pour plus d'infos, regardez le tuto sur Opengl 3.1 de Boouh section vbo et vao
 
    unsigned int handle[4];
    glGenBuffers(4, handle);
 
    glBindBuffer(GL_ARRAY_BUFFER, handle[0]);
    glBufferData(GL_ARRAY_BUFFER, (3 * nVerts) * sizeof(float), v, GL_STATIC_DRAW);
 
    glBindBuffer(GL_ARRAY_BUFFER, handle[1]);
    glBufferData(GL_ARRAY_BUFFER, (3 * nVerts) * sizeof(float), n, GL_STATIC_DRAW);
 
    glBindBuffer(GL_ARRAY_BUFFER, handle[2]);
    glBufferData(GL_ARRAY_BUFFER, (2 * nVerts) * sizeof(float), tex, GL_STATIC_DRAW);
 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle[3]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * faces * sizeof(unsigned int), id, GL_STATIC_DRAW);
 
    delete [] v;
    delete [] n;
    delete [] id;
    delete [] tex;
 
    // Create the VAO
    glGenVertexArrays( 1, &vaoHandle );
    glBindVertexArray(vaoHandle);
 
    glEnableVertexAttribArray(0);  // Vertex position
    glBindBuffer(GL_ARRAY_BUFFER, handle[0]);
    glVertexAttribPointer( (GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)) );
 
    glEnableVertexAttribArray(1);  // Vertex normal
    glBindBuffer(GL_ARRAY_BUFFER, handle[1]);
    glVertexAttribPointer( (GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)) );
 
    glBindBuffer(GL_ARRAY_BUFFER, handle[2]);
    glEnableVertexAttribArray(2);  // Texture coords
    glVertexAttribPointer( (GLuint)2, 2, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)) );
 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle[3]);
 
    glBindVertexArray(0);

    std::cout << "Initialise 3d objects" << std::endl;
}
