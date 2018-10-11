#include <GL/freeglut.h>
#include <stdio.h>
#include <random>
#include <math.h>
#define pi 3.141592

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);

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
	glutTimerFunc(100, TimerFunction, 1);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

float save_x[10], save_y[10];
int count = 0;

float Rad[10];
float degree[10];
float draw_x[10][100], draw_y[10][100];

int reverse[10];

int cnt[10];
int Spin[10];
float temp_x[10];

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (count == 10)
		{
			count = 0;
		}
		save_x[count] = x;
		save_y[count] = y;
		Rad[count] = 0;
		degree[count] = 0;
		Spin[count] = 1;
		reverse[count] = 0;
		for (int i = 0; i < 10; ++i)
		{

			for (int j = 0; j < 100; ++j)
			{
				draw_x[i][j] = -100;
				draw_y[i][j] = -100;
			}
		}
		count++;
	}
}

void TimerFunction(int value)
{
	for (int i = 0; i < count; ++i)
	{

		if (reverse[i] == 0) {
			Rad[i] += 0.5;
			degree[i] += 3.6;
			if (Rad[i] >= 100) {
				reverse[i] = 1;
				degree[i] = degree[i] - 90;
			}
			draw_x[i][cnt[i]] = save_x[i] + Rad[i] * cos((degree[i] / 360) * (pi * 2));
			draw_y[i][cnt[i]] = save_y[i] + Rad[i] * sin((degree[i] / 360) * (pi * 2));
		}
		else if(reverse[i] == 1) 
		{
			Rad[i] -= 0.5;
			
			degree[i] += 3.6;
			if (Rad[i] <= 0 ) {
				reverse[i] = 2;
				degree[i] = degree[i] + 90;
			}
			draw_x[i][cnt[i]] = save_x[i] + 200 +  Rad[i] * sin((degree[i] / 360) * (pi * 2));
			draw_y[i][cnt[i]] = save_y[i] + Rad[i] * cos((degree[i] / 360) * (pi * 2));
		}


		cnt[i]++;
	}


	glutPostRedisplay();
	glutTimerFunc(10, TimerFunction, 1);
}

GLvoid drawScene(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor4f(1.0f, 0.0f, 0.5f, 1.0f);
	glPointSize(7.0);
	glBegin(GL_POINTS);
	
	for (int i = 0; i < 10; ++i)
	{	
	
			for (int j = 0; j < 100; ++j)
			{
				glVertex2f(draw_x[i][j], draw_y[i][j]);
			}
		
	}
	glEnd();

	glFlush();
}


GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0.0, 800.0, 600, 0, -1.0, 1.0);
}