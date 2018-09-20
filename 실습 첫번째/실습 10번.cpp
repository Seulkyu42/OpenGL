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

// 레프트 버튼
bool left_button;

// 좌표저장고
int save_x[30];
int save_y[30];

// 카운트
int count = 0;

// Width / Height
int width[30] = { 0 };

// 반전
int reverse[30];

int draw_cnt = 0;

// 색상 관련
int color_switch = 0;
float R[30], G[30], B[30];

// 삼각형 사각형
int Shape = 0;
int direct[30];

// 스피드
int Speed = 5;

// 회전 스위치
int Spin_switch[30];
int Direct_Switch[30];
int cnt = 0;
int loc_x[30], loc_y[30];

// 마우스 위치
int mouse_x = -100, mouse_y = -100;

// 애니메이션 스위치
int animation[30];
int form_tri[30];
int change[30];

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'n':
		cnt = 0;
		count = 0;
		for (int i = 0; i < 30; ++i)
		{
			R[i] = rand() % 255;
			G[i] = rand() % 255;
			B[i] = rand() % 255;

			direct[i] = rand() % 4 + 1;
			save_x[i] = rand() % 800;
			save_y[i] = rand() % 600;
			change[i] = 0;
			animation[i] = 0;
		}
		break;
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
	case 'm':

		if (cnt == 30)
		{
			cnt = 0;
		}

		loc_x[cnt] = save_x[cnt];
		loc_y[cnt] = save_y[cnt];
		Spin_switch[cnt] = 1;
		Direct_Switch[cnt] = 1;

		cnt += 1;

		break;
	}
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		left_button = true;
	}
	else
	{
		mouse_x = -100;
		mouse_y = -100;

		left_button = false;
	}
}
void Motion(int x, int y)
{
	if (left_button == true)
	{
		mouse_x = x;
		mouse_y = y;
	}
}

void TimerFunction(int value)
{

	// 크기 변경
	for (int i = 0; i < 30; ++i)
	{
		
		if (reverse[i] == 0 && animation[i] == 0)
		{
			width[i] += 5;
			if (width[i] >= 20)
			{
				reverse[i] = 1;
			}
		}
		else if (reverse[i] == 1 && animation[i] == 0)
		{
			width[i] -= 5;
			if (width[i] <= 0)
			{
				reverse[i] = 0;
			}
		}

		if (animation[i] == 1 && Shape == 0)
		{
			R[i] = rand() % 255;
			G[i] = rand() % 255;
			B[i] = rand() % 255;

			width[i] = 50;

			if (change[i] == 0)
			{
				form_tri[i] += 1;
				if ((save_x[i] - 5 - width[i] + form_tri[i]) == (save_x[i] + 5 + width[i] - form_tri[i]))
				{
					change[i] = 1;
				}
			}
			else
			{
				form_tri[i] -= 1;
				if (form_tri[i] <= 0)
				{
					form_tri[i] = 0;
					animation[i] = 0;
				}
			}
		}

	}

	for (int i = 0; i < 30; ++i)
	{
		if (Spin_switch[i] == 1)
		{
			if (Direct_Switch[i] == 1)
			{
				save_x[i] -= Speed;
				if (save_x[i] <= 20)
				{
					Direct_Switch[i] = 2;
				}
				else if (save_x[i] == loc_x[i] + Speed)
				{
					Spin_switch[i] = 0;
				}
			}
			if (Direct_Switch[i] == 2)
			{
				save_y[i] += Speed;
				if (save_y[i] >= 580)
				{
					Direct_Switch[i] = 3;
				}
			}
			if (Direct_Switch[i] == 3)
			{
				save_x[i] += Speed;
				if (save_x[i] >= 780)
				{
					Direct_Switch[i] = 4;
				}
			}
			if (Direct_Switch[i] == 4)
			{
				save_y[i] -= Speed;
				if (save_y[i] <= loc_y[i])
				{
					Direct_Switch[i] = 1;
				}
			}
		}


		if (direct[i] == 1 && Spin_switch[i] == 0)
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
		if (direct[i] == 2 && Spin_switch[i] == 0)
		{
			save_x[i] += Speed;
			save_y[i] -= Speed;
			if (save_x[i] >= 800)
			{
				direct[i] = 1;
			}
			else if (save_y[i] <= 0)
			{
				direct[i] = 4;
			}
		}
		if (direct[i] == 3 && Spin_switch[i] == 0)
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
		if (direct[i] == 4 && Spin_switch[i] == 0)
		{
			save_x[i] += Speed;
			save_y[i] += Speed;
			if (save_x[i] >= 800)
			{
				direct[i] = 3;
			}
			else if (save_y[i] >= 600)
			{
				save_x[i] += Speed;
				save_y[i] -= Speed;
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
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 30; ++i)
	{
		if (left_button == true)
		{
			glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
			glBegin(GL_POLYGON);
			glVertex2i(mouse_x - 20, mouse_y - 20);
			glVertex2i(mouse_x - 20, mouse_y + 20);
			glVertex2i(mouse_x + 20, mouse_y + 20);
			glVertex2i(mouse_x + 20, mouse_y - 20);
			glEnd();
		}

		glColor4f((float)R[i] / 255, (float)G[i] / 255, (float)B[i] / 255, 1.0f);
		glBegin(GL_POLYGON);
		if (Shape == 0)
		{
			glVertex2i(save_x[i] - 5 - width[i] + form_tri[i], save_y[i] - 5 - width[i]);
		}
		else if (Shape == 1)
		{
			glVertex2i(save_x[i] - 5 - width[i], save_y[i] - 5 - width[i]);
		}
		glVertex2i(save_x[i] - 5 - width[i], save_y[i] + 5 + width[i]);
		if (Shape == 0)
		{
			glVertex2i(save_x[i] + 5 + width[i], save_y[i] + 5 + width[i]);
		}
		glVertex2i(save_x[i] + 5 + width[i] - form_tri[i], save_y[i] - 5 - width[i]);
		glEnd();

		// 충돌체크
		if ((mouse_x - 20 < save_x[i] && save_x[i] < mouse_x + 20) && (mouse_y - 20 < save_y[i] + 5 && save_y[i] + 5 < mouse_y + 20) && Shape == 0)
		{
			animation[i] = 1;
		}
		// 왼쪽
		if ((mouse_x + 20 == save_x[i] - 20) && (mouse_y - 20 < save_y[i] && save_y[i] < mouse_y + 20) && Shape == 0)
		{
			animation[i] = 1;
		}
		// 아래
		if ((mouse_x - 20 < save_x[i] && save_x[i] < mouse_x + 20) && (mouse_y - 20 < save_y[i] - 5 && save_y[i] - 5 < mouse_y + 20) && Shape == 0)
		{
			animation[i] = 1;
		}
		// 오른쪽
		if ((mouse_x - 20 == save_x[i] + 20) && (mouse_y - 20 < save_y[i] && save_y[i] < mouse_y + 20) && Shape == 0)
		{
			animation[i] = 1;
		}
	}

	glFlush();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0.0, 800.0, 600, 0, -1.0, 1.0);
}