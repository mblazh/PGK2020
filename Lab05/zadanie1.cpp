#include <GL/freeglut.h>
#include <cstdio>
#include <math.h>

#define DEG 0.0174533

static int window;
static int menu_id;
static int submenu_id[4];

static GLfloat theta[] = { 0.0, 0.0, 0.0, 0.0 };

GLfloat verticesA[][3] = {
	{	-1.0,	-1.0,	-1.0	},
	{	1.0,	-1.0,	-1.0	},
	{	1.0,	1.0,	-1.0	}, 
	{	-1.0,	1.0,	-1.0	}, 
	{	-1.0,	-1.0,	1.0		}, 
	{	1.0,	-1.0,	1.0		}, 
	{	1.0,	1.0,	1.0		}, 
	{	-1.0,	1.0,	1.0		}
};

GLfloat verticesB[][3] = {
	{	0.0,	0.0,	1.5		},
	{	0.0,	0.0,	-1.5	},
	{	-1.0,	1.0,	0.0		}, 
	{	1.0,	1.0,	0.0		}, 
	{	-1.0,	-1.0,	0.0		}, 
	{	1.0,	-1.0,	0.0		}
};

GLfloat colours[][3] = {
	{	1.0,	0.0,	0.0		},
	{	0.0,	1.0,	0.0		},
	{	0.0,	0.0,	1.0		},
	{	1.0,	1.0,	1.0		},
	{	1.0,	1.0,	0.0		},
	{	0.0,	1.0,	1.0		},
	{	1.0,	0.0,	1.0		},
	{	0.0,	0.0,	0.0		}
};

// Texture
GLubyte my_texels[512][512][3];

int figure = 0;
int displayMode = 0;
int trajectoryRadius = 0;
int animationSpeed = 2;

void menu(int num) {
	if (num == 0) {
		glutDestroyWindow(window);
		exit(0);
	} else {
		if (num < 20) {
			figure = num - 10;
		} else if (num < 30) {
			displayMode = num - 20;

			if (displayMode == 0) {
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			} else {
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}

			if (displayMode == 3) {
				glEnable(GL_TEXTURE_2D);
			} else {
				glDisable(GL_TEXTURE_2D);
			}
		} else if (num < 40) {
			trajectoryRadius = num - 30;
		} else if (num < 50) {
			animationSpeed = num - 40;
		} else if (num < 60) {
			theta[0] = 0.;
			theta[1] = 0.;
			theta[2] = 0.;
			theta[3] = 0.;
		}
	}

	glutPostRedisplay();
}

void createMenu() {
	submenu_id[0] = glutCreateMenu(menu);
	glutAddMenuEntry("Cube", 10);
	glutAddMenuEntry("Octahedron", 11);

	submenu_id[1] = glutCreateMenu(menu);
	glutAddMenuEntry("Wireframe", 20);
	glutAddMenuEntry("Monochrome", 21);
	glutAddMenuEntry("Multicolor", 22);
	glutAddMenuEntry("Checkerboard", 23);

	submenu_id[2] = glutCreateMenu(menu);
	glutAddMenuEntry("None", 30);
	glutAddMenuEntry("Small", 32);
	glutAddMenuEntry("Big", 34);

	submenu_id[3] = glutCreateMenu(menu);
	glutAddMenuEntry("Pause", 40);
	glutAddMenuEntry("Slow", 41);
	glutAddMenuEntry("Normal", 42);
	glutAddMenuEntry("Fast", 43);

	menu_id = glutCreateMenu(menu);
	glutAddSubMenu("Shape", submenu_id[0]);
	glutAddSubMenu("Display mode", submenu_id[1]);
	glutAddSubMenu("Trajectory", submenu_id[2]);
	glutAddSubMenu("Speed", submenu_id[3]);

	glutAddMenuEntry("Reset rotation", 50);
	glutAddMenuEntry("Quit", 0);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void loadTextureImageData() {
	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			int c = ((((i&0x80) == 0) ^ ((j&0x80)) == 0)) * 255;
			
			my_texels[i][j][0] = (GLubyte) c;
			my_texels[i][j][1] = (GLubyte) c;
			my_texels[i][j][2] = (GLubyte) c;
		}
	}   
}

void setPigment(int colourIndex, float textureX, float textureY) {
	switch(displayMode) {
		case 0:
			// wireframe
			glColor3fv(colours[3]);
			break;
		case 1:
			// ściany jednokolorowe
			glColor3fv(colours[5]);
			break;
		case 2:
			// ściany wielokolorowe
			glColor3fv(colours[colourIndex]);
			break;
		case 3:
			// tekstury
			glColor3fv(colours[3]);
			glTexCoord2f(textureX, textureY);
			break;
	}
}

void polygon(int a, int b, int c , int d){
	glBegin(GL_POLYGON);

	setPigment(a, 0.0, 1.0);
	glVertex3fv(verticesA[a]);
	
	setPigment(b, 1.0, 1.0);
	glVertex3fv(verticesA[b]);

	setPigment(c, 1.0, 0.0);
	glVertex3fv(verticesA[c]);

	setPigment(d, 0.0, 0.0);
	glVertex3fv(verticesA[d]);

	glEnd();
}

void triangle(int a, int b, int c) {
	glBegin(GL_TRIANGLES);

	setPigment(a, 0.0, 0.0);
	glVertex3fv(verticesB[a]);

	setPigment(b, 0.5, 1.0);
	glVertex3fv(verticesB[b]);

	setPigment(c, 1.0, 0.0);
	glVertex3fv(verticesB[c]);

	glEnd();
}

void drawFigure() {
	if (figure == 0) {
		polygon(0, 3, 2, 1);
		polygon(2, 3, 7, 6);
		polygon(0, 4, 7, 3);
		polygon(1, 2, 6, 5);
		polygon(4, 5, 6, 7);
		polygon(0, 1, 5, 4);
	} else if (figure == 1) {
		triangle(2, 0, 3);
		triangle(2, 0, 4);
		triangle(5, 0, 3);
		triangle(5, 0, 4);
		triangle(2, 1, 3);
		triangle(2, 1, 4);
		triangle(5, 1, 3);
		triangle(5, 1, 4);
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glScalef(0.25, 0.25, 0.25);
	glTranslatef(trajectoryRadius * cos(theta[3] * DEG), trajectoryRadius * sin(theta[3] * DEG), 0.0);

	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	
	drawFigure();

	glFlush();
	glutSwapBuffers();
}

void spinCube() {
	theta[0] = (int(theta[0]) + animationSpeed) % 360;
	theta[1] = (int(theta[1]) + animationSpeed) % 360;
	theta[2] = (int(theta[2]) + animationSpeed) % 360;
	theta[3] = (int(theta[3]) + animationSpeed) % 360;

	glutPostRedisplay();
}

void reshapeHandler(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h) {
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w, 2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
	} else {
		glOrtho(-2.0 * (GLfloat) w / (GLfloat) h, 2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
	}
	
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1280, 720);
	window = glutCreateWindow("Lab04");
	createMenu();
	glutReshapeFunc(reshapeHandler);
	glutDisplayFunc(display);
	glutIdleFunc(spinCube);
	glEnable(GL_DEPTH_TEST);

	loadTextureImageData();
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, my_texels);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glutMainLoop();

	return 0;
}