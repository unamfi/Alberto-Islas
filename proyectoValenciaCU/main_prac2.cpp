//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
#include "Main.h"

float rot=0;

void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	
	//Poner aqui codigo a dibujar

		glBegin(GL_POLYGON); //Iniciar opcion de dibujo como puntos individuales
	//glBegin(GL_LINE_LOOP); //Iniciar opcion de dibujo como puntos individuales
		glColor3f(0.0,0.0,0.0+rot);
		glVertex3f(10.0,0.0,-0.2);	//Crea un punto, lista de vertices
		glColor3f(1.0,0.0+rot,0.0);
		glVertex3f(10.0,4.0,-0.2);	//Crea un punto
		glVertex3f(11.0,4.0,-0.2);	//Crea un punto
		glVertex3f(11.0,0.0,-0.2);	//Crea un punto
			glEnd(); //Termina la opcion de POINTS
				glBegin(GL_POLYGON); //Iniciar opcion de dibujo como puntos individuales
		glColor3f(0.6,0.6,0.6);
		glVertex3f(11.0,4.0,-0.2);	//Crea un punto
		glVertex3f(13.0+(2*rot),4.0,-0.2);	//Crea un punto
		glColor3f(0.0,1.0,1.0);
		glVertex3f(13.0,2.0,-0.2);	//Crea un punto
		glVertex3f(11.0,2.0,-0.2);	//Crea un punto
			glEnd(); //Termina la opcion de POINTS
				glBegin(GL_POLYGON); //Iniciar opcion de dibujo como puntos individuales
		glVertex3f(12.0,0.0,-0.2);	//Crea un punto
		glColor3f(1.0,1.0+rot,0.0);
		glVertex3f(11.0,2.0,-0.2);	//Crea un punto
		glVertex3f(12.0,2.0,-0.2);	//Crea un punto
		glVertex3f(13.0,0.0,-0.2);	//Crea un punto
	glEnd(); //Termina la opcion de POINTS

	glBegin(GL_POLYGON); //Iniciar opcion de dibujo como puntos individuales
		glColor3f(0.0,0.0,0.0);
		glVertex3f(11.0,3.0,-0.2);	//Crea un punto
		glVertex3f(12.0+(2*rot),3.0,-0.2);	//Crea un punto
		glVertex3f(12.0,2.0,-0.2);	//Crea un punto
		glVertex3f(11.0,2.0,-0.2);	//Crea un punto
			glEnd(); //Termina la opcion de POINTS


	glBegin(GL_POLYGON); //Iniciar opcion de dibujo como puntos individuales
	//glBegin(GL_LINE_LOOP); //Iniciar opcion de dibujo como puntos individuales
		glColor3f(0.0,0.0,0.0+rot);
		glVertex3f(0.0,0.0,-0.2);	//Crea un punto, lista de vertices
		glColor3f(1.0,0.0+rot,0.0);
		glVertex3f(0.0,4.0,-0.2);	//Crea un punto
		glVertex3f(1.0,4.0,-0.2);	//Crea un punto
		glVertex3f(1.0,0.0,-0.2);	//Crea un punto
			glEnd(); //Termina la opcion de POINTS
				glBegin(GL_POLYGON); //Iniciar opcion de dibujo como puntos individuales
		glColor3f(0.6,0.6,0.6);
		glVertex3f(1.0,4.0,-0.2);	//Crea un punto
		glVertex3f(3.0+(2*rot),4.0,-0.2);	//Crea un punto
		glColor3f(0.0,1.0,1.0);
		glVertex3f(3.0,2.0,-0.2);	//Crea un punto
		glVertex3f(1.0,2.0,-0.2);	//Crea un punto
			glEnd(); //Termina la opcion de POINTS
				glBegin(GL_POLYGON); //Iniciar opcion de dibujo como puntos individuales
		glVertex3f(2.0,0.0,-0.2);	//Crea un punto
		glColor3f(1.0,1.0+rot,0.0);
		glVertex3f(1.0,2.0,-0.2);	//Crea un punto
		glVertex3f(2.0,2.0,-0.2);	//Crea un punto
		glVertex3f(3.0,0.0,-0.2);	//Crea un punto
	glEnd(); //Termina la opcion de POINTS

	glBegin(GL_POLYGON); //Iniciar opcion de dibujo como puntos individuales
		glColor3f(0.0,0.0,0.0);
		glVertex3f(1.0,3.0,-0.2);	//Crea un punto
		glVertex3f(2.0+(2*rot),3.0,-0.2);	//Crea un punto
		glVertex3f(2.0,2.0,-0.2);	//Crea un punto
		glVertex3f(1.0,2.0,-0.2);	//Crea un punto
			glEnd(); //Termina la opcion de POINTS

	glBegin(GL_POLYGON); //Iniciar opcion de dibujo como puntos individuales
	//glBegin(GL_LINE_LOOP); //Iniciar opcion de dibujo como puntos individuales
		glColor3f(0.0,0.0,0.0-rot);
		glVertex3f(4.0-(2*rot),5.0,-0.2);	//Crea un punto, lista de vertices
		glColor3f(1.0,0.0-rot,0.0);
		glVertex3f(4.0,9.0+(2*rot),-0.2);	//Crea un punto
		glColor3f(0.6+rot,0.6+rot,0.6);
		glVertex3f(9.0,9.0,-0.2);	//Crea un punto
		glColor3f(0.0,1.0-rot,1.0);
		glVertex3f(9.0,8.0,-0.2);	//Crea un punto
		glVertex3f(5.0,8.0-(2*rot),-0.2);	//Crea un punto
		glColor3f(1.0,1.0-rot,0.0+rot);
		glVertex3f(5.0,6.0,-0.2);	//Crea un punto
		glVertex3f(9.0-(2*rot),6.0,-0.2);	//Crea un punto
		glVertex3f(9.0,5.0,-0.2-(2*rot));	//Crea un punto
	glEnd(); //Termina la opcion de POINTS

	glBegin(GL_POLYGON); //Iniciar opcion de dibujo como puntos individuales
	//glBegin(GL_LINE_LOOP); //Iniciar opcion de dibujo como puntos individuales
		glColor3f(0.0,0.0,0.0-rot);
		glVertex3f(4.0,0.0,-0.2);	//Crea un punto, lista de vertices
		glColor3f(1.0,0.0-rot,0.0);
		glVertex3f(9.0,0.0,-0.2);	//Crea un punto
		glColor3f(0.6+rot,0.6+rot,0.6);
		glVertex3f(9.0,1.0,-0.2);	//Crea un punto
		glColor3f(0.0,1.0-rot,1.0);
		glVertex3f(5.0,1.0,-0.2);	//Crea un punto
	glEnd(); //Termina la opcion de POINTS

	glBegin(GL_POLYGON); //Iniciar opcion de dibujo como puntos individuales
		glVertex3f(4.0,4.0,-0.2);	//Crea un punto
		glColor3f(1.0,1.0-rot,0.0+rot);
		glVertex3f(5.0,3.0,-0.2);	//Crea un punto
		glVertex3f(9.0,3.0,-0.2);	//Crea un punto
		glVertex3f(9.0,4.0,-0.2);	//Crea un punto
	glEnd(); //Termina la opcion de POINTS
	
		glBegin(GL_POLYGON); //Iniciar opcion de dibujo como puntos individuales
		glVertex3f(4.0,4.0,-0.2);	//Crea un punto
		glColor3f(1.0,1.0-rot,0.0+rot);
		glVertex3f(5.0,3.0,-0.2);	//Crea un punto
		glVertex3f(5.0,1.0,-0.2);	//Crea un punto
		glVertex3f(4.0,0.0,-0.2);	//Crea un punto
	
	glEnd(); //Termina la opcion de POINTS

	glFlush();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
	if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-1,15,-1,10,0.1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
		case 'x': rot += .02;
				break;
		case 'y': rot -= .02;
				break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

