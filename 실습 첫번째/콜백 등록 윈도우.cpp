#include <GL/freeglut.h>
GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(250, 250);
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
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glFlush();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
}