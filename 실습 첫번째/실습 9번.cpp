#include <GL/freeglut.h>
#include <stdio.h>
#include <random>
#include <time.h>

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);

void Keyboard(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void Motion(int x, int y);
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
	glutMotionFunc(Motion);
	glutTimerFunc(50, TimerFunction, 1);
	glutKeyboardFunc(Keyboard);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

int save_x = 0, save_y = 0;
int rand_x[100],rand_y[100];
int R[100], G[100], B[100];
bool click;


void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'n':
	{
		for (int i = 0; i < 100; ++i)
		{
			R[i] = rand() % 255;
			G[i] = rand() % 255;
			B[i] = rand() % 255;

			rand_x[i] = rand() % 800;
			rand_y[i] = rand() % 600;
		}
		break;
	}
	}
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		click = true;

		save_x = x;
		save_y = y;
	}
	else 
	{
		click = false;
	}
}

void Motion(int x, int y)
{
	if (click == true)
	{
		save_x = x;
		save_y = y;		
	}
}

void TimerFunction(int value)
{
	glutPostRedisplay();
	glutTimerFunc(50, TimerFunction, 1);
}


// 윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 100; ++i)
	{
		glColor4f((float)R[i] /255, (float)G[i] / 255, (float)B[i] / 255, 1.0f);

		glBegin(GL_POLYGON);
		glVertex2i(rand_x[i] - 5, rand_y[i] - 5);
		glVertex2i(rand_x[i] - 5, rand_y[i] + 5);
		glVertex2i(rand_x[i] + 5, rand_y[i] + 5);
		glVertex2i(rand_x[i] + 5, rand_y[i] - 5);
		glEnd();
		

		if (click == true)
		{
			glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
			glBegin(GL_POLYGON);
			glVertex2i(save_x - 10, save_y - 10);
			glVertex2i(save_x - 10, save_y + 10);
			glVertex2i(save_x + 10, save_y + 10);
			glVertex2i(save_x + 10, save_y - 10);
			glEnd();

			// 충돌체크 부분
			// 위
			if ((save_x - 10 < rand_x[i] && rand_x[i] < save_x + 10) && (save_y - 10 < rand_y[i] + 5 && rand_y[i] + 5 < save_y + 10))
			{
				rand_x[i] = -100;
				rand_y[i] = -100;
			}
			// 왼쪽
			if ((save_x + 10 == rand_x[i] - 10) && (save_y - 10 < rand_y[i] && rand_y[i] < save_y + 10))
			{
				rand_x[i] = -100;
				rand_y[i] = -100;
			}
			// 아래
			if ((save_x - 10 < rand_x[i] && rand_x[i] < save_x + 10) && (save_y - 10 < rand_y[i] - 5 && rand_y[i] - 5 < save_y + 10))
			{
				rand_x[i] = -100;
				rand_y[i] = -100;
			}
			// 오른쪽
			if ((save_x - 10 == rand_x[i] + 10) && (save_y - 10 < rand_y[i] && rand_y[i] < save_y + 10))
			{
				rand_x[i] = -100;
				rand_y[i] = -100;
			}
		}
	
	}


	glFlush();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0.0, 800.0, 600, 0, -1.0, 1.0);
}