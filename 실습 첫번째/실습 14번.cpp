#include <GL/freeglut.h> 
#include <math.h>
#include <random>

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);

struct draw
{
	int shape;
	int x;
	int y;
	float size;
	int turn;
	int dir;
	int R, G, B;
};

draw Box[20];
int count = 0;
int rotate = 0;

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'r':
		if (rotate == 0)
		{
			rotate = 1;
		}
		else
		{
			rotate = 0;
		}
	}
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		Box[count].x = x;
		Box[count].y = y;
		Box[count].size = rand() % 100 + 10;
		Box[count].R = rand() % 255;
		Box[count].G = rand() % 255;
		Box[count].B = rand() % 255;
		Box[count].dir = rand() % 3;
		Box[count].shape = rand() % 4;
		count++;

		printf("x : %d, y : %d, shape : %d \n", Box[count].x, Box[count].y, Box[count].shape);

		if (count == 20)
		{
			count = 0;
		}
	}
}
void Timer(int value)
{
	for (int i = 0; i < 20; i++)
	{
		if (Box[i].size > 0)
		{
			Box[i].size -= 0.5;
		}
		if (rotate == 0)
		{
			if (Box[i].turn < 360)
				Box[i].turn++;
			else
				Box[i].turn = 0;
		}
		else
		{
			if (Box[i].turn > 0)
				Box[i].turn--;
			else
				Box[i].turn = 360;
		}
	}


	glutPostRedisplay(); // 화면 재 출력 
	glutTimerFunc(50, Timer, 1); // 타이머함수 재 설정
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
	glutMouseFunc(Mouse);
	glutTimerFunc(100, Timer, 1);
	glutMainLoop();
}

// 윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 바탕색을 'blue' 로 지정
	glClear(GL_COLOR_BUFFER_BIT); // 설정된 색으로 전체를 칠하기 

	for (int i = 0; i < 20; i++)
	{
		glPushMatrix();
		glColor4f((float)Box[i].R / 255, (float)Box[i].G / 255, (float)Box[i].B / 255, 1.0f);
		glTranslatef(Box[i].x, Box[i].y, 0.0);

		if (Box[i].dir == 0)
		{
			glRotatef(Box[i].turn, 1.0, 1.0, 0.0);
		}
		else if (Box[i].dir == 1)
		{
			glRotatef(Box[i].turn, 0.0, 1.0, 1.0);
		}
		else
		{
			glRotatef(Box[i].turn, 1.0, 0.0, 1.0);
		}

		switch (Box[i].shape)
		{
		case 0:
		{
			glutWireCube(Box[i].size);
			break;
		}
		case 1:
		{
			glutWireSphere(Box[i].size, 10, 10);
			break;
		}
		case 2:
		{
			glutWireTorus(Box[i].size, Box[i].size * 2, 10, 10);
			break;
		}
		case 3:
		{
			glutWireTeapot(Box[i].size);
			break;
		}
		}

		glPopMatrix();
	}

	glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0.0, 800.0, 600.0, 0, -400.0, 400.0);
}