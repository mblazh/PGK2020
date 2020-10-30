#include <GL/freeglut.h>

/* inicjalizacja trójkąta */
GLfloat v[3][2]={
	{-1.0, -0.58},
	{1.0, -0.58},
	{0.0, 1.15}
};

int n; /* liczba kroków rekursywnych */

void triangle( GLfloat *a, GLfloat *b,GLfloat *c){
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
}

void divide_triangle(GLfloat *a, GLfloat *b,GLfloat *c, int m){
	GLfloat v1[3], v2[3], v3[3]; //punkty pomocnicze w 3D
	int j;

	if(m>0){
		for(j=0; j<3; j++)
			v1[j]=(a[j]+b[j])/2;

		for(j=0; j<3; j++)
			v2[j]=(a[j]+c[j])/2;

		for(j=0; j<3; j++)
			v3[j]=(b[j]+c[j])/2;
	
		divide_triangle(a, v1, v2, m-1);
		divide_triangle(c, v2, v3, m-1);
		divide_triangle(b, v3, v1, m-1);
	} else(triangle(a,b,c));
}

void tetrahedron(int m){ 
	/* generowanie czworościanu */
	glColor3f(1.0,0.0,0.0);
	divide_triangle(v[0], v[1], v[2], m);
	glColor3f(0.0,1.0,0.0);
	divide_triangle(v[3], v[2], v[1], m);
	glColor3f(0.0,0.0,1.0);
	divide_triangle(v[0], v[3], v[1], m);
	glColor3f(0.0,0.0,0.0);
	divide_triangle(v[0], v[2], v[3], m);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	tetrahedron(n); //generowanie czworościanu
	glEnd();
	glFlush();
}

void myinit(){
	//glEnable(GL_DEPTH_TEST); //generowanie przesloniec
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor (1.0, 1.0, 1.0,1.0);
	glColor3f(0.0,0.0,0.0);
}

int main(int argc, char **argv){
	n=4;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); //przydatne do generowaniaprzesloniec
	glutInitWindowSize(500, 500);
	glutCreateWindow("Trojkat sierpinskiego 3D");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}