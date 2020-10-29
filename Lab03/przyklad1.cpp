#include <GL/freeglut.h>

void mydisplay(){
	glClear(GL_COLOR_BUFFER_BIT); //czyszczenie bufora obrazu
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush(); //wyświetlenie bufora obrazu
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutCreateWindow("Okno OpenGL"); //tworzenie okna aplikacji
	glutDisplayFunc(mydisplay); //definiowanie funkcji callback do wyświetlania zawartości okna
	glutMainLoop(); //główna pętla aplikacji
}