#include <GL/freeglut.h>
#include <stdio.h>
#include <random>
#include <time.h>
#include <math.h>

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);

void Keyboard(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void TimerFunction(int value);

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("2017180003");
	glutDisplayFunc(drawScene);
	glutMouseFunc(Mouse);
	glutTimerFunc(50, TimerFunction, 1);
	glutKeyboardFunc(Keyboard);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

int spin_x = 0, spin_y = 0, spin_z = 0;
int spin_left = 0, spin_right = 0;
int spin = 0;
int shape = 0;
int tea = 0;

int change = 0;
int y_change = 0;
int y_change2 = 0;
void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{

	case 'x':
		spin_x -= 2;
		break;
	case 'X':
		spin_x += 2;
		break;

	case 'y':
		spin_y -= 2;
		break;
	case 'Y':
		spin_y += 2;
		break;

	case 'z':
		spin_z -= 2;
		break;
	case 'Z':
		spin_z += 2;
		break;

	case 'l':
		spin_left -= 2;
		break;
	case 'L':
		spin_left += 2;
		break;

	case 'r':
		spin_right -= 2;
		break;
	case 'R':
		spin_right += 2;
		break;

	case 'o':
		spin -= 2;
		break;

	case 'C':
		if (shape == 0)
		{
			shape = 1;
		}
		else
		{
			shape = 0;
		}
		break;


	case 't':
		tea -= 2;
		break;

	case 'T':
		tea += 2;
		break;

	case 'I':
		change += 1;
		break;

	case 'O':
		change -= 1;
		break;

	case '+':
		y_change += 10;
		break;

	case '-':
		y_change -= 10;
		break;
	case '1':
		y_change2 += 10;
		break;

	case '2':
		y_change2 -= 10;
		break;
	}
	glutPostRedisplay();
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

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

	glClearColor((float)167/255, (float)226 / 255, (float)245 / 255, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	

	glPushMatrix();
	glTranslatef(0, y_change2, -300);
	gluLookAt(0, 100 +sin(y_change * 3.14), change, 0, 0, -300, 0, 1.0, 0);
	

	glRotatef(30, 1, 0, 0);
	glRotatef(spin_x, 1, 0, 0);
	glRotatef(spin_y, 0, 1, 0);
	glRotatef(spin_z, 0, 0, 1);
	// 바닥
	{
		glPushMatrix();
		glColor3f(1.0, 1.0, 11.0);
		glScalef(3, 0.1, 3);
		glutSolidCube(100);
		glColor3f(1.0, 0.0, 0.0);
		glutWireCube(100);

		glPopMatrix();
	}


	// 박스
	{
		glPushMatrix();

		glTranslatef(-30, 80, 40);
		glRotatef(spin_left, 0, 1, 0);
		glRotatef(spin, 0, 1, 0);

		if (shape == 0)
		{
			glScalef(1, 5, 1);
			glColor3f(1.0, 1.0, 0.0);
			glutSolidCube(30);
			glColor3f(1.0, 0.0, 0.0);
			glutWireCube(30);
		}
		else
		{
			glRotatef(tea, 0, 0, 1);
			glScalef(1, 1, 1);
			glTranslatef(30, 0, 0);
			glRotatef(spin_left, 0, 1, 0);
			glColor3f((float)195 / 255, (float)195 / 255, (float)195 / 255);
			glutSolidTeapot(30);
			glColor3f(0, 0, 0);
			glutWireTeapot(30);
		}

		glPopMatrix();
	}
	// 주전자
	{
		glPushMatrix();

		glTranslatef(50, 30, -40);
		glRotatef(spin_right, 0, 1, 0);
		glRotatef(spin, 0, 1, 0);

		if (shape == 0)
		{
			glScalef(1, 1, 1);
			glTranslatef(30, 0, 0);
			glColor3f((float)195 / 255, (float)195 / 255, (float)195 / 255);
			glutSolidTeapot(30);
			glColor3f(0, 0, 0);
			glutWireTeapot(30);
		}
		else
		{
			glColor3f((float)222 / 255, (float)222 / 255, (float)222 / 255);
			glutSolidTeacup(50);
			glColor3f(0, 0, 0);
			glutWireTeacup(50);
		}

		glPopMatrix();
	}

	glPopMatrix();


	glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();

	gluPerspective(60, 1, 1, 1000);
	glTranslatef(0, 0, -300);
	glMatrixMode(GL_MODELVIEW);
	//glOrtho(0.0, 800.0, 600, 0, -400.0, 400.0);
}