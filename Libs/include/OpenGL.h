#ifndef OPENGL_H
#define OPENGL_H
#include <cmath>
#include <GL/glut.h>
#include "Vector.h"


class OpenGL
{
    public:
        OpenGL();
        virtual ~OpenGL();

        unsigned int dispayMode;


        Vec2 PosWin,WindowSize;

        int     argc;
        char** argv;

        void    Create(void);
        void    SetWindowSize(int x,int y);
        void    Loop( void (* callback)( void ) );
        void    SetRGB(float red,float green,float blue);
        void    DrawDot(float x,float y);

    protected:



    private:
};



#endif // OPENGL_H
