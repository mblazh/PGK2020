#include <GL/freeglut.h>

int mainWindow;

void drawPrimitives() {
	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.5f, 0.5f, 1.0f);
	glVertex2f(-30.0f, -30.0f);
	glVertex2f(-30.0f, 30.0f);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.5f, 1.0f, 1.0f);
	glVertex2f(-35.0f, -30.0f);
	glVertex2f(-35.0f, 30.0f);
	glVertex2f(-40.0f, 30.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex2f(-45.0f, -30.0f);
	glVertex2f(-45.0f, 30.0f);
	glVertex2f(-50.0f, 30.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(2.0f, -12.0f);
	glVertex2f(8.0f, -2.0f);
	glVertex2f(14.0f, -12.0f);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0f, 0.5f, 1.0f);
	glVertex2f(2.0f, -25.0f);
	glVertex2f(8.0f, -15.0f);
	glVertex2f(14.0f, -25.0f);
	glVertex2f(20.0f, -15.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.0f, 1.0f);
	glVertex2f(28.0f, -15.0f);
	glVertex2f(22.0f, -25.0f);
	glVertex2f(34.0f, -25.0f);
	glVertex2f(40.0f, -20.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-16.0f, 2.0f);
	glVertex2f(-4.0f, 2.0f);
	glVertex2f(-4.0f, 14.0f);
	glVertex2f(-16.0f, 14.0f);
	glEnd();

	glBegin(GL_QUAD_STRIP);
	glColor3f(1.0f, 0.5f, 0.5f);
	glVertex2f(-4.0f, 22.0f);
	glVertex2f(-16.0f, 22.0f);
	glVertex2f(-6.0f, 34.0f);
	glVertex2f(-18.0f, 34.0f);
	glVertex2f(-4.0f, 46.0f);
	glVertex2f(-16.0f, 46.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(20.0f, 10.0f);
	glVertex2f(12.0f, 4.0f);
	glVertex2f(14.0f, 8.0f);
	glVertex2f(12.0f, 12.0f);
	glVertex2f(8.0f, 12.0f);
	glVertex2f(6.0f, 8.0f);
	glEnd();
}

void DrawScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	drawPrimitives();
	glFlush();
}

void InitOpenGL(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void ReshapeWindow(int width, int height) {
	int aspectRatio;
	
	if (height == 0) {
		height = 1;
	}

	aspectRatio = width / height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	
	if(width <= height) {
		glOrtho(-100.0, 100.0, -100.0 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);  
	} else {
		glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	gluOrtho2D(0,640,480,0);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(150, 150);
	mainWindow = glutCreateWindow("Laboratorium GLUT");

	if(mainWindow == 0) {
		exit(-1);
	}

	glutSetWindow(mainWindow);

	glutDisplayFunc(DrawScene);
	glutReshapeFunc(ReshapeWindow);

	InitOpenGL();
	glutMainLoop();
}
