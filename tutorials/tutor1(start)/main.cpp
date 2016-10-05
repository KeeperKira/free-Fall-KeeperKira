    #include <GL/glut.h>
    #include <iostream>


 //   #pragma


    using namespace std;

    void draw(void) {

        // Black background
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //Draw i
        glFlush();

    }
    //Main program
    int main(int argc, char **argv) {

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);

        glutInitWindowPosition(50, 25);

        glutInitWindowSize(480,480);

        glutCreateWindow("Hello OpenGL");

        glutDisplayFunc(draw);

        glutMainLoop();
        return 0;
    }
