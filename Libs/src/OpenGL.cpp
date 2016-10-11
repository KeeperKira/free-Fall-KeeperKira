#include "OpenGL.h"


OpenGL::OpenGL()
{
    dispayMode = GLUT_DOUBLE | GLUT_RGBA ;


    WindowSize.x = 1280;
    WindowSize.y = 720;

    PosWin.x=200;
    PosWin.y=200;

    argc =0;
    argv = NULL;

}

void    OpenGL::Create(void)
{

    glutInit ( &argc, argv ); //инициализация OpenGL Utility Toolkit
	//режим окна(одиночный буфер и RGB-палитра)

	glutInitDisplayMode (dispayMode);
	//установка размеров окна(ширина и высота в пикселях)
	glutInitWindowSize ( WindowSize.x, WindowSize.y );
	//положение окна относительно левого верхнего угла экрана
	glutInitWindowPosition (PosWin.x, PosWin.y);
	//создание окна c заголовком Biomorph
	glutCreateWindow ("Biomorph");

    glClearColor ( 0.0, 0.0, 0.0, 0.0 ); //цвет фона(RGBA, чёрный)

	glPointSize ( 5 );

	gluOrtho2D ( 0, WindowSize.x,WindowSize.y, 0);

}

void    OpenGL::SetWindowSize(int x,int y)
{
    WindowSize.x = x;
    WindowSize.y = y;
}

void    OpenGL::DrawDot(float x,float y)
{
    glVertex2i ( x, y );
}

void    OpenGL::SetRGB(float red,float green,float blue)
{
    glColor4f (red, green, blue,1); //цвет рисования
}

void   OpenGL::Loop( void (* callback)( void ) )
{
    	//инициализация функции, отвечающей за рисование в окне
	glutDisplayFunc ( callback );
	glutIdleFunc(callback);

	glutMainLoop (); //вход в главный цикл
}

OpenGL::~OpenGL()
{
    //dtor
}
