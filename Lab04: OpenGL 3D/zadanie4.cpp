#include <GL/freeglut.h>
#include <cstdio>

GLfloat vertices[][3] = {
	{	1.0,	0.0,	0.75	},
	{	1.0,	0.0,	-0.75	},
	{	0.5,	0.5,	0.0		}, 
	{	1.5,	0.5,	0.0		}, 
	{	0.5,	-0.5,	0.0		}, 
	{	1.5,	-0.5,	0.0		}
};

// Texture
GLubyte my_texels[512][512][3];

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

void triangle(int a, int b, int c) {
	glBegin(GL_TRIANGLES);

	glTexCoord2f(0.0, 0.0);
	glVertex3fv(vertices[a]);

	glTexCoord2f(0.5, 1.0);
	glVertex3fv(vertices[b]);

	glTexCoord2f(1.0, 0.0);
	glVertex3fv(vertices[c]);

	glEnd();
}

void drawFigure() {
	triangle(2, 0, 3);
	triangle(2, 0, 4);
	triangle(5, 0, 3);
	triangle(5, 0, 4);
	triangle(2, 1, 3);
	triangle(2, 1, 4);
	triangle(5, 1, 3);
	triangle(5, 1, 4);
}

static GLfloat theta[] = { 0.0, 0.0, 0.0 };
static GLint axis = 2;

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	drawFigure();
	glFlush();
	glutSwapBuffers();
}

void spinCube() {
	theta[axis] += 2.0;
	
	if(theta[axis] > 360.0) {
		theta[axis] -= 360.0;
	}
	
	glutPostRedisplay();
}

void mouseHandler(int btn, int state, int x, int y) {
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
	if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
	if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) axis = 2;
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
	glutInitWindowSize(500, 500);
	glutCreateWindow("Sześcian");
	glutReshapeFunc(reshapeHandler);
	glutDisplayFunc(display);
	glutIdleFunc(spinCube);
	glutMouseFunc(mouseHandler);
	glEnable(GL_DEPTH_TEST);

	loadTextureImageData();
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, my_texels);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glEnable(GL_TEXTURE_2D);

	glutMainLoop();

	return 0;
}