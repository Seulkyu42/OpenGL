#include <GL/freeglut.h> 
#include <math.h>
#include <random>

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);

int spin = 0;
int spin_t = 0;
int shape = 0;

float Mx[5], My[5];

int count = 0;
int time = 0;
int go = 0;
float go_x[5], go_y[5];

int box = 0;

int dir = 0;
int size = 0;
int size_switch = 0;

bool click = false;

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '0':
		dir = 0;
		shape = 0;
		break;
	case '1':
		dir = 0;
		shape = 1;
		break;
	case '2':
		dir = 0;
		shape = 2;
		break;
	case '3':
		dir = 0;
		shape = 3;
		break;
	case '4':
		dir = 0;
		shape = 4;
		break;

	case 't':
		box = 1;
		break;
	case 'r':
		box = 2;
		break;
	case 'x':
		spin_t += 5;
		break;
	case 'X':
		spin_t -= 5;
		break;
	case 'y':
		spin += 5;
		break;
	case 'Y':
		spin -= 5;
		break;
	}
}

void Motion(int x, int y)
{
	if (click)
	{

	}
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		click = true;
		Mx[count] = x;
		My[count] = y;
		count++;
		if (count == 5)
		{
			count = 0;
		}

	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		for (int i = 0; i < 5; ++i)
		{
			go_x[i] = 0;
			go_y[i] = 0;
		}
		time = 0;
		click = false;
	}
}

void Timer(int value)
{
	if (size_switch == 0)
	{
		size++;
		if (size > 10)
		{
			size_switch = 1;
		}
	}
	else
	{
		size--;
		if (size < 0)
		{
			size_switch = 0;
		}
	}

	dir++;

	if (dir == 720)
	{
		dir = 0;
	}



	time++;
	if (time < 100)
	{
		go_x[3] = 0;
		go_y[3] = 0;
		go_x[0] += (Mx[0] - Mx[1]) / 100;
		go_y[0] += (My[0] - My[1]) / 100;
	}
	else if (time < 200)
	{
		go_x[0] = 0;
		go_y[0] = 0;
		go_x[1] += (Mx[1] - Mx[2]) / 100;
		go_y[1] += (My[1] - My[2]) / 100;
	}
	else if (time < 300)
	{
		go_x[1] = 0;
		go_y[1] = 0;
		go_x[2] += (Mx[2] - Mx[3]) / 100;
		go_y[2] += (My[2] - My[3]) / 100;
	}
	else if (time < 400)
	{
		go_x[2] = 0;
		go_y[2] = 0;
		go_x[3] += (Mx[3] - Mx[4]) / 100;
		go_y[3] += (My[3] - My[4]) / 100;
	}
	else
	{
		time = 0;
	}

	glutPostRedisplay(); // 화면 재 출력 
	glutTimerFunc(10, Timer, 1); // 타이머함수 재 설정
}

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100); // 윈도우의 위치지정
	glutInitWindowSize(800, 600); // 윈도우의 크기 지정
	glutCreateWindow("2017180003"); // 윈도우 생성 (윈도우 이름) 
	glutDisplayFunc(drawScene); // 출력 함수의 지정
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutMotionFunc(Motion);
	glutMouseFunc(Mouse);
	glutTimerFunc(100, Timer, 1);
	glutMainLoop();
}

// 윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 바탕색을 'blue' 로 지정
	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기 

	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2i(0, 300);
	glVertex2i(800, 300);
	glVertex2i(400, 0);
	glVertex2i(400, 600);
	glEnd();

	glPushMatrix();
	glTranslatef(400.0, 300.0, 0.0);
	glRotatef(spin, 0.0, 1.0, 0.0);

	switch (shape)
	{
	case 0:
		for (int i = 0; i < 720; ++i)
		{
			glPointSize(3);
			glBegin(GL_POINTS);
			glVertex2f(200 * cos(i * 6.28 / 180), 200 * sin(i * 6.28 / 180));
			glEnd();

			glPushMatrix();
			glTranslatef(200 * cos(dir * 6.28 / 180), 200 * sin(dir * 6.28 / 180), 0);

			if (box == 1)
			{
				glPushMatrix();
				glRotatef(spin_t, 0.0, 0.0, 1.0);
				glBegin(GL_TRIANGLES);
				glVertex3f(0, -10 - size, 0);
				glVertex3f(-10 - size, 10 + size, 0);
				glVertex3f(10 + size, 10 + size, 0);
				glEnd();
				glPopMatrix();
			}
			else
			{
				glBegin(GL_POLYGON);
				glVertex3f(-10 - size, -10 - size, 0);
				glVertex3f(-10 - size, 10 + size, 0);
				glVertex3f(10 + size, 10 + size, 0);
				glVertex3f(10 + size, -10 - size, 0);
				glEnd();
			}

			glPopMatrix();
		}
		break;
	case 1:
		for (int i = 0; i < 720; ++i)
		{
			glPointSize(2);
			glBegin(GL_POINTS);
			glVertex2f(-360 + i, 200 * sin(i * 3.14 / 360));
			glEnd();

			glPushMatrix();
			glTranslatef(-360 + dir, 200 * sin(dir * 3.14 / 360), 0);

			if (box == 1)
			{
				glBegin(GL_TRIANGLES);
				glVertex3f(0, -10 - size, 0);
				glVertex3f(-10 - size, 10 + size, 0);
				glVertex3f(10 + size, 10 + size, 0);
				glEnd();
			}
			else
			{
				glBegin(GL_POLYGON);
				glVertex3f(-10 - size, -10 - size, 0);
				glVertex3f(-10 - size, 10 + size, 0);
				glVertex3f(10 + size, 10 + size, 0);
				glVertex3f(10 + size, -10 - size, 0);
				glEnd();
			}

			glPopMatrix();
		}
		break;
	case 2:
		for (int i = 0; i < 720; ++i)
		{
			glPointSize(2);
			glBegin(GL_POINTS);
			glVertex2f(-360 + 100 * cos(i * 6.28 / 180) + i, 100 * sin(i * 6.28 / 180));
			glEnd();

			glPushMatrix();
			glTranslatef(-360 + 100 * cos(dir * 6.28 / 180) + dir, 100 * sin(dir * 6.28 / 180), 0);

			if (box == 1)
			{
				glBegin(GL_TRIANGLES);
				glVertex3f(0, -10 - size, 0);
				glVertex3f(-10 - size, 10 + size, 0);
				glVertex3f(10 + size, 10 + size, 0);
				glEnd();
			}
			else
			{
				glBegin(GL_POLYGON);
				glVertex3f(-10 - size, -10 - size, 0);
				glVertex3f(-10 - size, 10 + size, 0);
				glVertex3f(10 + size, 10 + size, 0);
				glVertex3f(10 + size, -10 - size, 0);
				glEnd();
			}

			glPopMatrix();
		}
		break;
	case 3:
		for (int i = 0; i < 720; ++i)
		{
			glBegin(GL_POINTS);
			if (i < 180)
			{
				glVertex2f(-360 + i, -90 + i);
			}
			else if (i < 360)
			{
				glVertex2f(-360 + i, 270 - i);
			}
			else if (i < 540)
			{
				glVertex2f(-360 + i, -450 + i);
			}
			else
			{
				glVertex2f(-360 + i, 630 - i);
			}
			glEnd();

			glPushMatrix();
			if (dir < 180)
			{
				glTranslatef(-360 + dir, -90 + dir, 0);
			}
			else if (dir < 360)
			{
				glTranslatef(-360 + dir, 270 - dir, 0);
			}
			else if (dir < 540)
			{
				glTranslatef(-360 + dir, -450 + dir, 0);
			}
			else
			{
				glTranslatef(-360 + dir, 630 - dir, 0);
			}

			if (box == 1)
			{
				glBegin(GL_TRIANGLES);
				glVertex3f(0, -10 - size, 0);
				glVertex3f(-10 - size, 10 + size, 0);
				glVertex3f(10 + size, 10 + size, 0);
				glEnd();
			}
			else
			{
				glBegin(GL_POLYGON);
				glVertex3f(-10 - size, -10 - size, 0);
				glVertex3f(-10 - size, 10 + size, 0);
				glVertex3f(10 + size, 10 + size, 0);
				glVertex3f(10 + size, -10 - size, 0);
				glEnd();
			}

			glPopMatrix();

		}
		break;
	case 4:
		if (click == false)
		{
			for (int i = 0; i < 5; ++i)
			{
				glPointSize(6);
				glBegin(GL_POINTS);
				glVertex2f(-400 + Mx[i], -300 + My[i]);
				glEnd();
				for (int j = 0; j < 4; ++j)
				{
					glBegin(GL_LINES);
					glVertex2f(-400 + Mx[j], -300 + My[j]);
					glVertex2f(-400 + Mx[j + 1], -300 + My[j + 1]);
					glEnd();
				}

				glPushMatrix();
				if (time < 100)
				{
					glTranslatef(-400 + Mx[0] - go_x[0], -300 + My[0] - go_y[0], 0);
				}
				else if (time < 200)
				{
					glTranslatef(-400 + Mx[1] - go_x[1], -300 + My[1] - go_y[1], 0);
				}
				else if (time < 300)
				{
					glTranslatef(-400 + Mx[2] - go_x[2], -300 + My[2] - go_y[2], 0);
				}
				else if (time < 400)
				{
					glTranslatef(-400 + Mx[3] - go_x[3], -300 + My[3] - go_y[3], 0);
				}

				if (box == 1)
				{
					glBegin(GL_TRIANGLES);
					glVertex3f(0, -10 - size, 0);
					glVertex3f(-10 - size, 10 + size, 0);
					glVertex3f(10 + size, 10 + size, 0);
					glEnd();
				}
				else 
				{
					glBegin(GL_POLYGON);
					glVertex3f(-10 - size, -10 - size, 0);
					glVertex3f(-10 - size, 10 + size, 0);
					glVertex3f(10 + size, 10 + size, 0);
					glVertex3f(10 + size, -10 - size, 0);
					glEnd();
				}

				glPopMatrix();
			}
		}
		break;
	}

	glPopMatrix();

	glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0, 800, 600, 0, -400.0, 400.0);
}