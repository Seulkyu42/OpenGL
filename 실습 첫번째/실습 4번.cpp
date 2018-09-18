#include <GL/freeglut.h>
#include <stdio.h>
#include <random>
#include <time.h>

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);

void Keyboard(unsigned char key,int x,int y);
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

// 레프트 버튼
bool left_button;

// 좌표저장고
int save_x[10];
int save_y[10];

// 카운트
int count = 0;

// Width / Height
int width[10] = { 0 };

// 반전
int reverse[10];

int draw_cnt = 0;

// 색상 관련
int color_switch = 0;
float R = 0, G = 0, B = 0;

// 삼각형 사각형
int Shape = 0;
int direct[10];

// 스피드

int Speed = 5;

void Keyboard(unsigned char key,int x ,int y)
{
	switch (key)
	{
	case 't':
		Shape = 1;
		break;

	case 'r':
		Shape = 0;
		break;
	case '+':
		Speed += 1;
		break;
	case '-':
		Speed -= 1;
		break;
	case 's':
		Speed = 0;
		break;
	case 'p':
		Speed = 5;
		break;
	}
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	
		if (count == 10)
		{
			count = 0;
		}
		left_button = true;

		direct[count] = rand() % 4 + 1;
		save_x[count] = x;
		save_y[count] = y;

		count += 1;
		printf("x : %d , y : %d \n", save_x[count], save_y[count]);
		printf("count : %d\n", count);
	}
	else
	{
		left_button = false;
	}
}

void TimerFunction(int value)
{
	// 색상 변경
	if (color_switch == 0)
	{
		R += 5;
		G += 5;
		B += 5;
		if (R == 255)
		{
			color_switch = 1;
		}
	}
	else if (color_switch == 1)
	{
		R -= 5;
		G -= 5;
		B -= 5;
		if (R == 10)
		{
			color_switch = 0;
		}
	}

	// 크기 변경
	for (int i = 0; i < 10; ++i)
	{
		if (reverse[i] == 0)
		{
			width[i] += 5;
			if (width[i] == 30)
			{
				reverse[i] = 1;
			}
		}
		if (reverse[i] == 1)
		{
			width[i] -= 5;
			if (width[i] == 0)
			{
				reverse[i] = 0;
			}
		}

	}


	for (int i = 0; i < 10; ++i)
	{
		if (direct[i] == 1)
		{
			save_x[i] -= Speed;
			save_y[i] -= Speed;
			if (save_x[i] <= 0)
			{
				direct[i] = 2;
			}
			else if (save_y[i] <= 0)
			{
				direct[i] = 3;
			}
		}
		if (direct[i] == 2)
		{
			save_x[i] += Speed;
			save_y[i] -= Speed;
			if (save_x[i] >= 800)
			{
				direct[i] = 1;
			}
			else if (save_y[i] >= 0)
			{
				direct[i] = 4;
			}
		}
		if (direct[i] == 3)
		{
			save_x[i] -= Speed;
			save_y[i] += Speed;
			if (save_x[i] <= 0)
			{
				direct[i] = 4;
			}
			else if (save_y[i] >= 600)
			{
				direct[i] = 1;
			}
		}
		if (direct[i] == 4)
		{
			save_x[i] += Speed;
			save_y[i] += Speed;
			if (save_x[i] >= 800)
			{
				direct[i] = 3;
			}
			else if (save_y[i] >= 600)
			{
				direct[i] = 2;
			}
		}
	}

	glutPostRedisplay();
	glutTimerFunc(50, TimerFunction, 1);
}


// 윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	int x[10] = { 0 };
	int y[10] = { 0 };

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 10; ++i)
	{
		x[i] = save_x[i];
		y[i] = save_y[i];

		glColor4f((float)R, 0.0f, 0.0f, 1.0f);
		glBegin(GL_POLYGON);
		if (Shape == 0)
		{
			glVertex2i(x[i] - 5 - width[i], y[i] - 5 - width[i]);
		}
		else if (Shape == 1)
		{
			glVertex2i(x[i] -5 -width[i], y[i] -5 - width[i]);
		}
		glVertex2i(x[i] - 5 -width[i], y[i] + 5 + width[i]);
		if (Shape == 0)
		{
			glVertex2i(x[i] +5+ width[i], y[i] + 5 + width[i]);
		}
		glVertex2i(x[i] +5+ width[i], y[i] - 5 - width[i]);
		glEnd();
	}

	glFlush();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0.0, 800.0, 600, 0, -1.0, 1.0);
}