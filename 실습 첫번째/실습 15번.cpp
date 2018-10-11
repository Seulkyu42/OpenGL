#include <GL/freeglut.h> 
#include <math.h>
#include <time.h>
#include <random>

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);

int spin = 0;
int Font[6];
int sec;

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'y':
		spin++;
		break;
	case 'Y':
		spin--;
		break;
	}
}

void Motion(int x, int y)
{
	spin = x;
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

	}
}
int R, G, B;
void Timer(int value)
{
	R = rand() % 255;
	G = rand() % 255;
	B = rand() % 255;

	sec++;

	glutPostRedisplay(); // 화면 재 출력 
	glutTimerFunc(10, Timer, 1); // 타이머함수 재 설정
}

void one()
{
	// -l
	glPushMatrix();
	glTranslatef(40, 40, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 120, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
}
void two()
{
	// -
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 40, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -
	glPushMatrix();
	glTranslatef(0, 80, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// l-
	glPushMatrix();
	glTranslatef(-40, 120, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -
	glPushMatrix();
	glTranslatef(0, 160, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
}
void three()
{
	// -
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 40, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -
	glPushMatrix();
	glTranslatef(0, 80, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 120, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -
	glPushMatrix();
	glTranslatef(0, 160, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
}
void four()
{
	// l-
	glPushMatrix();
	glTranslatef(-40, 40, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 40, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -
	glPushMatrix();
	glTranslatef(0, 80, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 120, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
}
void five()
{
	// -
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// l-
	glPushMatrix();
	glTranslatef(-40, 40, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -
	glPushMatrix();
	glTranslatef(0, 80, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 120, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -
	glPushMatrix();
	glTranslatef(0, 160, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
}
void six()
{
	// -
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -
	glPushMatrix();
	glTranslatef(0, 80, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -
	glPushMatrix();
	glTranslatef(0, 160, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// l-
	glPushMatrix();
	glTranslatef(-40, 40, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// l-
	glPushMatrix();
	glTranslatef(-40, 120, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 120, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
}
void seven()
{
	// -
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// l-
	glPushMatrix();
	glTranslatef(-40, 40, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 40, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 120, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
}
void eight()
{
	// -
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -
	glPushMatrix();
	glTranslatef(0, 80, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -
	glPushMatrix();
	glTranslatef(0, 160, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// l-
	glPushMatrix();
	glTranslatef(-40, 40, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 40, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// l-
	glPushMatrix();
	glTranslatef(-40, 120, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 120, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
}
void nine()
{
	// -
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -
	glPushMatrix();
	glTranslatef(0, 80, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// l-
	glPushMatrix();
	glTranslatef(-40, 40, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 40, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 120, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
}
void zero()
{
	// -
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -
	glPushMatrix();
	glTranslatef(0, 160, 0);
	glScalef(3, 1, 1);
	glutSolidCube(20);
	glPopMatrix();
	// l-
	glPushMatrix();
	glTranslatef(-40, 40, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 40, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// l-
	glPushMatrix();
	glTranslatef(-40, 120, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
	// -l
	glPushMatrix();
	glTranslatef(40, 120, 0);
	glScalef(1, 3, 1);
	glutSolidCube(20);
	glPopMatrix();
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

	time_t timer;
	struct tm *t;

	timer = time(NULL); // 현재 시각을 초 단위로 얻기

	t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기

	system("cls");
	printf("현재 시: %d\n", t->tm_hour);
	printf("현재 분: %d\n", t->tm_min);
	printf("현재 초: %d\n\n", t->tm_sec);


	{ // 시계
		Font[0] = t->tm_hour / 10;
		Font[1] = t->tm_hour % 10;
		Font[2] = t->tm_min / 10;
		Font[3] = t->tm_min % 10;
		Font[4] = t->tm_sec / 10;
		Font[5] = t->tm_sec % 10;
	}

	{
		glPushMatrix();
		glTranslatef(350, 100, 0.0);
		glRotatef(30, 1.0, 1.0, 0.0);
		glRotatef(spin, 0.0, 1.0, 0.0);
		glColor3f((float)R / 255, (float)G / 255, (float)B / 255);

		// 초
		{
			glPushMatrix();
			glTranslatef(-150, 190, 0.0);
			glScalef(1, 2, 1);
			glutSolidCube(20);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-150, 270, 0.0);
			glScalef(1, 2, 1);
			glutSolidCube(20);
			glPopMatrix();

			if (sec % 24 == 0)
			{
				glPushMatrix();
				glTranslatef(110, 190, 0.0);
				glScalef(1, 2, 1);
				glutSolidCube(20);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(110, 270, 0.0);
				glScalef(1, 2, 1);
				glutSolidCube(20);
				glPopMatrix();
			}
		}

		for (int i = 0; i < 6; ++i)
		{
			if (i == 0)
			{
				glPushMatrix();
				glTranslatef(-350, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
			if (i == 1)
			{
				glPushMatrix();
				glTranslatef(-240, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
			if (i == 2)
			{
				glPushMatrix();
				glTranslatef(-80, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
			if (i == 3)
			{
				glPushMatrix();
				glTranslatef(30, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
			if (i == 4)
			{
				glPushMatrix();
				glTranslatef(190, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
			if (i == 5)
			{
				glPushMatrix();
				glTranslatef(300, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
		}
		glPopMatrix();
	}

	{
		glPushMatrix();
		glTranslatef(350, -100, 0.0);
		glRotatef(30, 1.0, 1.0, 0.0);
		glRotatef(spin, 0.0, 1.0, 0.0);
		glColor3f((float)R / 255, (float)G / 255, (float)B / 255);

		// 초
		{
			glPushMatrix();
			glTranslatef(-150, 190, 0.0);
			glScalef(1, 2, 1);
			glutSolidCube(20);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-150, 270, 0.0);
			glScalef(1, 2, 1);
			glutSolidCube(20);
			glPopMatrix();

			if (sec % 24 == 0)
			{
				glPushMatrix();
				glTranslatef(110, 190, 0.0);
				glScalef(1, 2, 1);
				glutSolidCube(20);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(110, 270, 0.0);
				glScalef(1, 2, 1);
				glutSolidCube(20);
				glPopMatrix();
			}
		}

		for (int i = 0; i < 6; ++i)
		{
			if (i == 0)
			{
				glPushMatrix();
				glTranslatef(-350, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
			if (i == 1)
			{
				glPushMatrix();
				glTranslatef(-240, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
			if (i == 2)
			{
				glPushMatrix();
				glTranslatef(-80, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
			if (i == 3)
			{
				glPushMatrix();
				glTranslatef(30, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
			if (i == 4)
			{
				glPushMatrix();
				glTranslatef(190, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
			if (i == 5)
			{
				glPushMatrix();
				glTranslatef(300, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
		}
		glPopMatrix();
	}

	{
		glPushMatrix();
		glTranslatef(350, 300, 0.0);
		glRotatef(30, 1.0, 1.0, 0.0);
		glRotatef(spin, 0.0, 1.0, 0.0);
		glColor3f((float)R / 255, (float)G / 255, (float)B / 255);

		// 초
		{
			glPushMatrix();
			glTranslatef(-150, 190, 0.0);
			glScalef(1, 2, 1);
			glutSolidCube(20);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-150, 270, 0.0);
			glScalef(1, 2, 1);
			glutSolidCube(20);
			glPopMatrix();

			if (sec % 24 == 0)
			{
				glPushMatrix();
				glTranslatef(110, 190, 0.0);
				glScalef(1, 2, 1);
				glutSolidCube(20);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(110, 270, 0.0);
				glScalef(1, 2, 1);
				glutSolidCube(20);
				glPopMatrix();
			}
		}

		for (int i = 0; i < 6; ++i)
		{
			if (i == 0)
			{
				glPushMatrix();
				glTranslatef(-350, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
			if (i == 1)
			{
				glPushMatrix();
				glTranslatef(-240, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
			if (i == 2)
			{
				glPushMatrix();
				glTranslatef(-80, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
			if (i == 3)
			{
				glPushMatrix();
				glTranslatef(30, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
			if (i == 4)
			{
				glPushMatrix();
				glTranslatef(190, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
			if (i == 5)
			{
				glPushMatrix();
				glTranslatef(300, 150, 0.0);
				switch (Font[i])
				{
				case 0:
					zero();
					break;
				case 1:
					one();
					break;
				case 2:
					two();
					break;
				case 3:
					three();
					break;
				case 4:
					four();
					break;
				case 5:
					five();
					break;
				case 6:
					six();
					break;
				case 7:
					seven();
					break;
				case 8:
					eight();
					break;
				case 9:
					nine();
					break;

				}
				glPopMatrix();
			}
		}
		glPopMatrix();
	}

	glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glOrtho(0.0, 800.0, 600.0, 0, -800.0, 800.0);
}