#include <GL/freeglut.h>
#include <random>
#include <time.h>

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("2017180003");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

// 윈도우 출력 함수
GLvoid drawScene(GLvoid)
{

	srand(time(NULL));
	float x_size = rand() % 50 + 10;
	double width = 800 / x_size;

	printf("x_size = %f \n", x_size);

	int color = rand() % 3 + 1;

	float R = 1 / x_size;
	float G = 1 / x_size;
	float B = 1 / x_size;
	float A = 1 / x_size;

	for (int i = 0; i < x_size; ++i)
	{
		if (color == 1)
		{
			glColor4f(R * i, 0.0f, 0.0f, 1.0f);
		}
		else if (color == 2)
		{
			glColor4f(0.0f, G * i, 0.0f, 1.0f);
		}
		else
		{
			glColor4f(0.0f, 0.0f, B * i, 1.0f);
		}

		if (i == 0)
		{
			glRectf(0, 1.0, 800 / x_size, -1.0);
		}
		else
		{
			glRectf(width, 1.0, width * 2, -1.0);
			width += 800 / x_size;
		}
	}
	glFlush();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0, 800.0, -1.0, 1.0, -1.0, 1.0);
}