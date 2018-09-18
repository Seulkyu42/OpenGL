#include <GL/freeglut.h>
GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("2017180003");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

// 윈도우 출력 함수
GLvoid drawScene(GLvoid)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	GLint p1[2] = { 0,-1 };
	GLint p2[2] = { 0,1 };
	GLint p3[2] = { -1,0.5 };
	GLint p4[2] = { 1,0.5 };

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
		glVertex2iv (p1);
		glVertex2iv (p2);
		glVertex2iv (p3);
		glVertex2iv (p4);
	glEnd();


	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
	glVertex3f(0 ,0.2 ,0);
	glVertex3f(-0.15,-0.2,0);
	glVertex3f(0.15, -0.2, 0);
	glEnd();

	//네모들
	{
		// 3사분면
		glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
		glRectf(-1.0f, -1.0f, -0.75f, -0.65f);

		// 2사분면
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
		glRectf(-1.0f, 1.0f, -0.75f, 0.65f);

		// 1사분면
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		glRectf(1.0f, 1.0f, 0.75f, 0.65f);

		// 4사분면
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glRectf(1.0f, -1.0f, 0.75f, -0.65f);
	}

	glFlush();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
}