#include "Mundo.h"
#include "glut.h"

Mundo mundo;

void OnDraw(void); 
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y); 
void onSpecialKeyboardDown(int key, int x, int y);

int main(int argc,char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(onSpecialKeyboardDown);

	mundo.Inicializa();
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	mundo.Dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void onSpecialKeyboardDown(int key, int x, int y)
{
 mundo.teclaEspecial(key);
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	mundo.Tecla(key);
	glutPostRedisplay();
}

void OnTimer(int value)
{

	mundo.Mueve();
	//no borrar estas lineas
	glutTimerFunc(100,OnTimer,0);
	glutPostRedisplay();
}
