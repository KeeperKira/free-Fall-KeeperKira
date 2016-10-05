//#include <cstdlib>
//#include <ctime>
#include <cmath>
#include <GL/glut.h>
#define WIDTH 800
#define HEIGHT 640

using namespace std;

//рисование точки с координатами (x, y) передаваемым в функцию цветом(RGB)
void draw_dot ( int x, int y, float  *clr ) {
	glColor4f (clr[0], clr[1], clr[2],1); //цвет рисования
	glVertex2i ( x, y );
}

void draw_biomorph () {
    static  float time=0;
    float f,d ;

    time+=0.5;
	float clr_black[] = { 0, 0, 0 }, new_clr[3];

    glClear ( GL_COLOR_BUFFER_BIT );//очищаем буфер
    glBegin ( GL_POINTS );//начинаем отрисовку

    //пробегаем все пиксели
    for ( int x = 0; x < WIDTH ; x++ )
    for ( int y = 0; y < HEIGHT ; y++ )
    {
        float px,py,a;
        a=1;

        px=x-400;
        px=y-320;
        px = (((float)x/WIDTH)*2-1);//преобразуем координаты к виду [-1;1]
        py = (((float)y/HEIGHT)*2-1);//преобразуем координаты к виду [-1;1]

        //создаём искажение в форме клевера и рябь на ней
        a = 3.5*atan(py/px);
        px/=0.5 + 0.02 * sin(5.0 * a - time * 16.0)*cos(50/a);
        py/=0.5 + 0.02 * sin(5.0 * a - time * 16.0)*cos(50/a);

        //добавляем дугу
        px*=1.0/sin(a) ;
        py*=1.0/sin(a) ;

        f = 1.40 + 0.2 * cos(time * 0.14);// добавляем уменьшение/увеличение дугии

        float lenght = (float)sqrt(px*px+py*py);
        d = (abs(lenght-f)*(abs(sin(time/10))*10.0+2));// добавляем колебание толщины дугии

        //добовляем новый вертекс.
        new_clr[0]=0./d;
        new_clr[1]=0.2/d;
        new_clr[2]=2.22/d;
        draw_dot ( x, y, new_clr );

    }
    glEnd ();
	glutSwapBuffers();
}

void init () {
	glClearColor ( 0.0, 0.0, 0.0, 0.0 ); //цвет фона(RGBA, чёрный)
	glPointSize ( 4.0 );
	glMatrixMode ( GL_PROJECTION ); //матрица проекций
	glLoadIdentity (); //замена текущей матрицы на единичную
	gluOrtho2D ( 0, WIDTH,HEIGHT, 0);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

int main ( int argc, char** argv ) {
	glutInit ( &argc, argv ); //инициализация OpenGL Utility Toolkit
	//режим окна(одиночный буфер и RGB-палитра)
	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGBA |GLUT_ALPHA );
	//установка размеров окна(ширина и высота в пикселях)
	glutInitWindowSize ( WIDTH, HEIGHT );
	//положение окна относительно левого верхнего угла экрана
	glutInitWindowPosition (500, 300);
	//создание окна c заголовком Biomorph
	glutCreateWindow ("Biomorph");
	//инициализация функции, отвечающей за рисование в окне
	glutDisplayFunc ( draw_biomorph );
	init (); // дополнительные параметры
	glutIdleFunc(draw_biomorph);
	glutMainLoop (); //вход в главный цикл
	return 0;
}
