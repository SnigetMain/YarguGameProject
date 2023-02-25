#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

struct Player {
    GLdouble verticles[4][2]  = {
        {0.5, 0.5},
        {-0.5, 0.5},
        {-0.5, -0.5},
        {0.5, -0.5},
    };
    GLdouble textCoords[4][2] = {
        {0, 1},
        {1, 1},
        {1, 0},
        {0, 0},
    };
    unsigned int texture;
    void make_texture() {
        int width, height, cnt;
        // unsigned char *data = stbi_load("01.png", &width, &height, &cnt, 0);
        /* if (!data) {
            cout << "fail";
        }*/
        /* glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
                     0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glBindTexture(GL_TEXTURE_2D, 0);
        // stbi_image_free(data);*/
    };
    void render() {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);
        glColor3d(1, 1, 1);
        glPushMatrix();
            glEnableClientState(GL_VERTEX_ARRAY);
            glEnableClientState(GL_TEXTURE_COORD_ARRAY);

            glVertexPointer(2, GL_DOUBLE, 0, verticles);
            glTexCoordPointer(2, GL_DOUBLE, 0, textCoords);
            glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            glDisableClientState(GL_VERTEX_ARRAY);
        glPopMatrix();
    };
};

Player p;

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    p.render();
    glutSwapBuffers();
}

int width, height;
unsigned char* image = SOIL_load_image("eblan.jpg", &width, &height, 0, SOIL_LOAD_RGBA);
// SOIL_load_OGL_texture();
// SOIL_load_image("eblan.jpg", &width, &height, 0, SOIL_LOAD_RGB);

int main(int argc, char **argv)
{
    if (image == NULL) {
        cout << "bad";
    }
    // int width, height;
    // unsigned char* image = ("eblan.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    // cout << width;
    /*if (data == NULL) {
        cout << "bad";
    }*/
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(400,400);		//Указываем размер окна
    glutInitWindowPosition(100,100);	//Позиция окна
    glutCreateWindow("GameProject");		//Имя окна
    // p.make_texture();
    // glutDisplayFunc(renderScene);				//Вызов функции отрисовки
    // glutMainLoop();
    return 0;
}
