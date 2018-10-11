#include <GL/freeglut.h>
#include <stdio.h>
#include <random>
#include <time.h>
#define PI 3.1415926

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
	glutCreateWindow("2017180003 - 11");
	glutDisplayFunc(drawScene);
	glutMouseFunc(Mouse);
	glutTimerFunc(50, TimerFunction, 1);
	glutKeyboardFunc(Keyboard);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

float sin_y;
float s_sin_y, s_sin_x;
float s_degree = 0;
float degree = 0;
float move_x = 0, move_y = 0;
float plus = 0;

int move_switch = 0;
int Shape = 0;

void Keyboard(unsigned char key, int x, int y)   //키보드
{
	switch (key)
	{
	case '1':
		Shape = 1;
		break;
	case '2':
		Shape = 2;
		break;
	case '3':
		Shape = 3;
		break;
	case '4':
		Shape = 4;
		break;
	case 'x':
		move_x += 0.5;
		break;
	case 'X':
		move_x -= 0.5;
		break;
	case 'y':
		move_y += 0.5;
		break;
	case 'Y':
		move_y -= 0.5;
		break;
	case 's':
		plus += 10;
		break;
	case 'S':
		plus -= 10;
		break;
	case 'a':
		move_switch = 1;
		break;
	case 'A':
		move_switch = 2;
		break;
	case 'T':
		move_switch = 0;
		break;
	case 'Q':
		exit(0);
		break;
	}
}

void Mouse(int button, int state, int x, int y)   // 마우스
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

	}
}

void TimerFunction(int value)   // 타이머
{
	if (move_switch == 1)
	{
		move_x += 3;
	}
	else if (move_switch == 2)
	{
		move_x -= 3;
	}

	glutPostRedisplay();
	glutTimerFunc(100, TimerFunction, 1);
}


// 윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2i(0, 300);
	glVertex2i(800, 300);
	glVertex2i(400, 0);
	glVertex2i(400, 600);
	glEnd();


	glPointSize(5.0);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
	if (Shape == 1)   // 사인
	{
		for (int i = 0; i < 10000; ++i)
		{
			glPointSize(2);
			glBegin(GL_POINTS);
			glVertex2f(i + move_x,100 + move_y + 200 + plus * sin(i * 3.14  / 360));
			glEnd();
		}

	}
	else if (Shape == 2) // 스프링
	{
		for (int i = 0; i < 10000; ++i)
		{
			glPointSize(3);
			glBegin(GL_POINTS);
			glVertex2f(-200 + plus * cos(i * 6.14 / 180) + i + move_x, move_y + 300+ 200 * sin(i * 6.14 / 180));
			glEnd();
		}
	}
	else if (Shape == 3) // 리본
	{
		glBegin(GL_TRIANGLES);
		glVertex2f(300 + move_x - plus, 250 + move_y);
		glVertex2f(300 + move_x - plus, 350 + move_y);
		glVertex2f(400 + move_x, 300 + move_y);
		glVertex2f(500 + move_x + plus, 350 + move_y);
		glVertex2f(500 + move_x + plus, 250 + move_y);
		glVertex2f(400 + move_x, 300 + move_y);
		glEnd();
	}
	else if (Shape == 4) // 사각형
	{
		glBegin(GL_POLYGON);
		glVertex2f(300 + move_x - plus, 200 + move_y);
		glVertex2f(300 + move_x - plus, 400 + move_y);
		glVertex2f(500 + move_x + plus, 400 + move_y);
		glVertex2f(500 + move_x + plus, 200 + move_y);
		glEnd();
	}

	glFlush();
}


GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0.0, 800.0, 600, 0, -400.0, 400.0);
}