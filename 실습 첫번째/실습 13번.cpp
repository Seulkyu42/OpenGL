#include <GL/freeglut.h> 
#include <math.h>

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);

void Keyboard(unsigned char key, int x, int y);
void Timer(int value);

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // 디스플레이 모드 설정 
	glutInitWindowPosition(100, 100); // 윈도우의 위치지정
	glutInitWindowSize(800, 600); // 윈도우의 크기 지정
	glutCreateWindow("2017180003"); // 윈도우 생성 (윈도우 이름) 
	glutDisplayFunc(drawScene); // 출력 함수의 지정
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(100, Timer, 1);
	glutMainLoop();
}

float time = 0;
float spin = 0;
float size = 1;

int dir1 = 0, dir2 = 0, dir3 = 0;

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'y':
		spin += 1.5;
		break;
	case 'Y':
		spin -= 1.5;
		break;
	case 's':
		size += 10;
		break;
	case 'S':
		size -= 10;
	}
}

void Timer(int value)
{
	if (time < 200)
	{
		time++;
		dir1++;
	}
	else if (time < 400)
	{
		time++;
		dir2++;
	}
	else if (time < 600)
	{
		time++;
		dir3++;
	}
	else
	{
		time = 0;
		dir1 = 0;
		dir2 = 0;
		dir3 = 0;
	}
	glutPostRedisplay(); // 화면 재 출력 
	glutTimerFunc(10, Timer, 1); // 타이머함수 재 설정
}

// 윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // 바탕색을 'blue' 로 지정
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

	// 큰삼각형 1
	glBegin(GL_LINE_LOOP);
	glVertex3f(0, -100 - size, 0);
	glVertex3f(-100 - size, 100 + size, 0);
	glVertex3f(100 + size, 100 + size, 0);
	glEnd();

	// 큰삼각형 2
	glBegin(GL_LINE_LOOP);
	glVertex3f(0, -100 - size, 0);
	glVertex3f(0, 100 + size, -100 - size);
	glVertex3f(0, 100 + size, 100 + size);
	glEnd();

	// 작은 삼각형 1
	glPushMatrix();

	if (time < 200)
	{
		glTranslatef(-dir1 / 2 - dir1 * size / 200, -size - 100 + dir1 + dir1 * size / 100, 0);
	}
	else if (time < 400)
	{
		glTranslatef(-100 - size + (dir2 + dir2 * size / 100), 100 + size, 0);
	}
	else
	{
		glTranslatef(100 + size - dir3 / 2 - dir3 * size / 200, 100 + size - dir3 - dir3 * size / 100, 0);
	}
	glRotatef(spin, 0.0, 1.0, 0.0);

	glBegin(GL_LINE_LOOP);
	glVertex3f(0, -10, 0);
	glVertex3f(-10, 10, 0);
	glVertex3f(10, 10, 0);
	glEnd();

	glPopMatrix();

	glPushMatrix();

	if (time < 200)
	{
		glTranslatef(0, -size - 100 + dir1 + dir1 * size / 100, -dir1 / 2 - dir1 * size / 200);
	}
	else if (time < 400)
	{
		glTranslatef(0, 100 + size, -100 - size + (dir2 + dir2 * size / 100));
	}
	else
	{
		glTranslatef(0, 100 + size - dir3 - dir3 * size / 100, 100 + size - dir3 / 2 - dir3 * size / 200);
	}
	glRotatef(spin, 0.0, 1.0, 0.0);

	glBegin(GL_LINE_LOOP);
	glVertex3f(0, -10, 0);
	glVertex3f(-10, 10, 0);
	glVertex3f(10, 10, 0);
	glEnd();

	glPopMatrix();
	glPopMatrix();

	glFlush(); // 화면에 출력하기 
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0.0, 800.0, 600.0, 0.0, -400.0, 400.0);
}