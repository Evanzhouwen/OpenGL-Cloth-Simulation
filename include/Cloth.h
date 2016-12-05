#ifndef CLOTH_H
#define CLOTH_H
#ifdef __APPLE__
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <OpenGL/glext.h>
#else
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib")
#endif

#include<glm/glm.hpp>
#include<Entity.h>
#include<vector>
#include<Mass.h>


static const int VERTEX_ATTRIBUTE_COUNT = 7;
class Cloth
{
    public:
        Cloth(glm::vec3 position,
              int sliceX,
              int sliceY);
        virtual ~Cloth();
        GLuint GetvaoID() { return vaoID; }
        void draw(float delta);
        void initCloth();
        void printVertices();
        void update(float delta);
    protected:

    private:
        int sliceX;
        int sliceY;
        int indicesSize;
        int positionSize;
        int normalsSize;
        float t;

        GLuint positionID;
        GLuint normalID;
        GLuint eboID;
        GLuint vaoID;

        GLuint* indices;
        GLfloat* positionCords;
        GLfloat* normalsCords;
        GLfloat* normalCoords2;

        void rebind();

        glm::vec3 position;

        std::vector<Mass*> masses;

        int sizeOfIndices();
        int byteSizeOfVertexArray();

        void createVertices(glm::vec3 position, int slicesX, int slicesY);
        void createIndices(int slicesX, int slicesY);
        void generateNormals();

        void fillMasses();
        void attachSprings(int sliceX, int sliceY);
        void stickTop(int sliceX, int sliceY);

};

#endif // CLOTH_H
