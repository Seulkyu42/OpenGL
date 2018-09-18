#include <GL/freeglut.h>
#include <stdio.h>
#include <random>
#include <time.h>
#include <math.h>
#define pi 3.141592


GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);

void Keyboard(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void TimerFunction(int value);

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("2017180003");
	glutDisplayFunc(drawScene);
	glutMouseFunc(Mouse);
	glutTimerFunc(50, TimerFunction, 1);
	glutKeyboardFunc(Keyboard);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}
// 좌표저장
int save_x[10], save_y[10];

int sin_degree = 0, cos_degree = 0;

int Point_x[10][1000], Point_y[10][1000];

// 색상 관련
int color_switch = 0;
float B = 0;

int count = 0;
// 반지름
float R[10];

int plus[10];

int Shape[10];

void Keyboard(unsigned char key, int x, int y)
{
	
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		for (int i = count; i < count + 1; ++i)
		{
			R[i] = 0;
			Shape[i] = rand() % 2;
		}
		save_x[count] = x;
		save_y[count] = y;

		count += 1;

		if (count == 10)
		{
			count = 0;
		}
	}
}

void TimerFunction(int value)
{

	// 색상 변경
	if (color_switch == 0)
	{
		B += 5;
		if (B == 255)
		{
			color_switch = 1;
		}
	}
	else if (color_switch == 1)
	{

		B -= 5;
		if (B == 10)
		{
			color_switch = 0;
		}
	}


	for (int i = 0; i < 10; ++i)
	{
		if (Shape[i] == 0)
		{
			R[i] += 5;
		}

		else if (Shape[i] == 1)
		{
			if (plus[i] == 0)
			{
				R[i] += 2;
				if (R[i] >= 200)
				{
					plus[i] = 1;
				}
			}
			else
			{
				R[i] -= 5;
				if (R[i] <= 0)
				{
					plus[i] = 0;
				}
			}
		}


		for (int j = 0; j < 1000; ++j)
		{
			sin_degree += 1532;
			cos_degree += 1532;

			Point_x[i][j] = save_x[i] + R[i] * sin(sin_degree);
			Point_y[i][j] = save_y[i] + R[i] * cos(cos_degree);
		}
	}

	glutPostRedisplay();
	glutTimerFunc(10, TimerFunction, 1);
}


// 윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			glColor4f((float)B / 255, 0.0f, 0.5f, 1.0f);
			glPointSize(7.0);
			glBegin(GL_POINTS);
			glVertex2i(Point_x[i][j], Point_y[i][j]);
			glEnd();
		}
	}



	glFlush();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0.0, 800.0, 600, 0, -1.0, 1.0);
}