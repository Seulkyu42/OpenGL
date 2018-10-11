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


GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0.0, 800.0, 600, 0, -1.0, 1.0);
}

// ��ǥ����
int save_x[10], save_y[10];

double Point_x[10][1000], Point_y[10][1000];
double temp_x[10][1000], temp_y[10][1000];
double degree[10];

// ���� ����
int color_switch = 0;
float B = 0;

int count = 0;
// ������
double R[10];
int Spin[10];
int reverse[10];
double plus[10];

int cnt[10];

void Keyboard(unsigned char key, int x, int y)
{
	
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//for (int i = count; i < count + 1; ++i)
		//{
		//	R[i] = 0;
		//}
		R[count] = 0;
		save_x[count] = x;
		save_y[count] = y;
		Spin[count] = 1; //  rand() % 2 + 1;
		count += 1;

		if (count == 10)
		{
			count = 0;
		}
	}
}

void TimerFunction(int value)
{
	glutPostRedisplay();
	// ���� ����
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
		cnt[i] += 1;
		//for (int j = 0; j < 100; ++j)
		//{
		//}
	}
	
	glutTimerFunc(10, TimerFunction, 1);
}


// ������ ��� �Լ�
GLvoid drawScene(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	glColor4f(1.0f, 0.0f, 0.5f, 1.0f);
	glPointSize(7.0);
	glBegin(GL_POINTS);
	for (int i = 0; i < 10; ++i)
	{
		if (Spin[i] == 1)
		{
			Point_x[i][cnt[i]] = save_x[i] + R[i] * cos(degree[i]);
			Point_y[i][cnt[i]] = save_y[i] + R[i] * sin(degree[i]);
			for (int j = 0; j < cnt[i]; ++j)
			{

				if (reverse[i] == 0) {
					R[i] += 0.1;
					degree[i] += 10;
					glVertex2d(Point_x[i][j] + plus[i], Point_y[i][j]);
					if (R[i] >= 100)
					{
						reverse[i] = 1;
					}
				}
				
				else if (reverse[i] == 1) {
					plus[i] += 0.1;
					if (plus[i] >= 200)
					{
						reverse[i] = 2;
					}
				}
				else {
					R[i] -= 0.5;
					degree[i] -= 10;
					if (R[i] <= 0)
					{
						cnt[i] = 0;
						plus[i] = 0;
						Spin[i] = 0;
						reverse[i] = 0;
					}
				}

		
			}
		}
		else if (Spin[i] == 2)
		{
			for (int j = 0; j < cnt[i]; ++j)
			{
				Point_x[i][j] = save_x[i] + R[i] * cos(degree[i]);
				Point_y[i][j] = save_y[i] + R[i] * sin(degree[i]);

				if (reverse[i] == 0) {
					R[i] += 0.5;
					degree[i] -= 10;
					glVertex2d(Point_x[i][j] - plus[i], Point_y[i][j]);
					if (R[i] >= 100)
					{
						reverse[i] = 1;
					}
				}
				else if (reverse[i] == 1) {
					plus[i] += 0.02;
					if (plus[i] >= 200)
					{
						reverse[i] = 2;
					}
				}
				else {
					R[i] -= 0.5;
					degree[i] += 10;
					if (R[i] <= 0)
					{
						cnt[i] = 0;
						plus[i] = 0;
						Spin[i] = 0;
						reverse[i] = 0;
					}
				}

		
			}
		}
	}
	glEnd();
	glFlush();
}
