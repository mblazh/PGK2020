#include <GL/freeglut.h>

int mainWindow;
int nesting;

void drawHole(float x, float y, float width, float height){
	glBegin(GL_QUADS);
	
	glColor3f(0.0f, 0.0f, 0.0f);
	
	glVertex2f(x, y);
	glVertex2f(x, y + height);
	glVertex2f(x + width, y + height);
	glVertex2f(x + width, y);
	
	glEnd();
}

void drawCarpet(float x, float y, float width, float height, int currentNesting){
	glBegin(GL_QUADS);

	glColor3f(0.2f, 0.6f, 0.4f);
	
	glVertex2f(x, y);
	glVertex2f(x, y + height);
	glVertex2f(x + width, y + height);
	glVertex2f(x + width, y);
	
	glEnd();

	if (currentNesting < nesting) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i != 1 || j != 1) {
					drawCarpet(x + i * (width / 3), y + j * (height / 3), width / 3, height / 3, currentNesting + 1);
				} else {
					drawHole(x + i * (width / 3), y + j * (height / 3), width / 3, height / 3);
				}
			}
		}
	}
}

void DrawScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	drawCarpet(-50, -50, 100, 100, 0);
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
	nesting = *argv[1] - '0';
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(150, 150);
	mainWindow = glutCreateWindow("Pierwsze Laboratorium");

	if(mainWindow == 0) {
		exit(-1);
	}

	glutSetWindow(mainWindow);

	glutDisplayFunc(DrawScene);
	glutReshapeFunc(ReshapeWindow);

	InitOpenGL();
	glutMainLoop();
}