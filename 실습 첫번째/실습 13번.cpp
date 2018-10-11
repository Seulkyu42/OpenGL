#include <GL/freeglut.h> 
#include <math.h>

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);

void Keyboard(unsigned char key, int x, int y);
void Timer(int value);

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // ���÷��� ��� ���� 
	glutInitWindowPosition(100, 100); // �������� ��ġ����
	glutInitWindowSize(800, 600); // �������� ũ�� ����
	glutCreateWindow("2017180003"); // ������ ���� (������ �̸�) 
	glutDisplayFunc(drawScene); // ��� �Լ��� ����
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
	glutPostRedisplay(); // ȭ�� �� ��� 
	glutTimerFunc(10, Timer, 1); // Ÿ�̸��Լ� �� ����
}

// ������ ��� �Լ�
GLvoid drawScene(GLvoid)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // �������� 'blue' �� ����
	glClear(GL_COLOR_BUFFER_BIT); // ������ ������ ��ü�� ĥ�ϱ� 

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

	// ū�ﰢ�� 1
	glBegin(GL_LINE_LOOP);
	glVertex3f(0, -100 - size, 0);
	glVertex3f(-100 - size, 100 + size, 0);
	glVertex3f(100 + size, 100 + size, 0);
	glEnd();

	// ū�ﰢ�� 2
	glBegin(GL_LINE_LOOP);
	glVertex3f(0, -100 - size, 0);
	glVertex3f(0, 100 + size, -100 - size);
	glVertex3f(0, 100 + size, 100 + size);
	glEnd();

	// ���� �ﰢ�� 1
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

	glFlush(); // ȭ�鿡 ����ϱ� 
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0.0, 800.0, 600.0, 0.0, -400.0, 400.0);
}