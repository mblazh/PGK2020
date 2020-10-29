#include <GL/freeglut.h>

/* dane inicjalizacyjne trójkąta */
GLfloat v[3][2]={
	{-1.5, 	-0.87},
	{1.5, 	-0.87}, 
	{0.0, 	1.625}
};

int n; /* liczba kroków rekursywnych */

void triangle( GLfloat *a, GLfloat *b,GLfloat *c)/* wyświetlenie trójkąta */{
	glVertex2fv(a);
	glVertex2fv(b);
	glVertex2fv(c);
}

void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c,int m){
	/* podział trójkąta */
	GLfloat v0[2], v1[2], v2[2];
	int j;
	
	if(m>0){
		for(j=0; j<2; j++) 
			v0[j]=(a[j]+b[j])/2;

		for(j=0; j<2; j++) 
			v1[j]=(a[j]+c[j])/2;

		for(j=0; j<2; j++)
			v2[j]=(b[j]+c[j])/2;

		divide_triangle(a, v0, v1, m-1);
		divide_triangle(c, v1, v2, m-1);
		divide_triangle(b, v2, v0, m-1);
	} else(triangle(a,b,c));
		/* wyświetlenie pojedyńczego trójkąta */
}

void display(){ 
	/*funkcja wyświetlania*/
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	divide_triangle(v[0], v[1], v[2], n);
	glEnd();
	glFlush();
}

void myinit(){ 
	/*funkcja inicjująca mechanizmy OpenGL */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor (1.0, 1.0, 1.0,1.0);
	glColor3f(0.0,0.0,0.0);
}

int main(int argc, char **argv){
	n=4;
	glutInit(&argc, argv); //konfuguracja mechanizmów bibl. Glut
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //inicjowanie trybu wyświetlania
	glutInitWindowSize(500, 500); //inicjowanie rozmiaru okna
	glutCreateWindow("Trójkąt Sierpińskiego"); //tworzenie okna aplikacji
	glutDisplayFunc(display); //wskazanie funkcji wyświetlania
	myinit(); //inicjowanie mechanizmówOpenGL
	glutMainLoop();
}