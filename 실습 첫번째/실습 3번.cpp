#include <GL/freeglut.h>
#include <time.h>
#include <random>

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);

void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(900, 600);
	glutCreateWindow("2017180003");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}

// 윈도우 출력 함수
GLvoid drawScene(GLvoid)
{

	glClear(GL_COLOR_BUFFER_BIT);

	srand(time(NULL));

	int point = rand() % 4 + 1;
	int swit = 0;
	printf("point : %d\n", point);

	for (int j = 0; j < 3; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			// 그리드
			{
				glBegin(GL_LINES);
				glVertex2i(300 * i, 200 * j);
				glVertex2i(300 * (i + 1), 200 * j);

				glVertex2i(300 * i, 200 * j);
				glVertex2i(300 * i, 200 * (j + 1));
				glEnd();
			}

			// 직선
			if (point == 1)
			{
				glBegin(GL_LINES);
				glVertex2i(50 + (300 * i), 50 + (200 * j));
				glVertex2i(250 + (300 * i), 150 + (200 * j));
				glEnd();
			}

			// 삼각형
			else if (point == 2)
			{
				glBegin(GL_POLYGON);
				glVertex2i(150 + (300 * i), 50 + (200 * j));
				glVertex2i(50 + (300 * i), 150 + (200 * j));
				glVertex2i(250 + (300 * i), 150 + (200 * j));
				glEnd();
			}

			// 사각형
			else if (point == 3)
			{
				glBegin(GL_POLYGON);
				glVertex2i(50 + (300 * i), 50 + (200 * j));
				glVertex2i(50 + (300 * i), 150 + (200 * j));
				glVertex2i(250 + (300 * i), 150 + (200 * j));
				glVertex2i(250 + (300 * i), 50 + (200 * j));
				glEnd();
			}

			// 오각형
			else if (point == 4)
			{
				swit = 1;
				glBegin(GL_POLYGON);
				glVertex2i(50  + (300 * i), 50 + (200 * j));
				glVertex2i(50  + (300 * i), 150 + (200 * j));
				glVertex2i(225  + (300 * i), 150 + (200 * j));
				glVertex2i(250  + (300 * i), 100 + (200 * j));
				glVertex2i(225  + (300 * i), 50 + (200 * j));
				glEnd();
			}


			if (point < 5 && swit == 0)
			{
				point++;
				if (point == 4)
				{
					swit = 1;
				}
			}
			else if (swit == 1)
			{
				point--;
				if (point == 1)
				{
					swit = 0;
				}
			}

		}
	}



	glFlush();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0, 900, 600, 0, 0, 1.0);
}