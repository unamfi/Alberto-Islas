
		 //#include <gl/gl.h>     // The GL Header File
		 //#include <windows.h>	//Solo para Windows
		 //#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
		 //#include <stdlib.h>		// Descomentar para Linux
		 //#include <stdio.h>
		 //#include <string.h>
		 //#include <malloc.h>		// Solo para Windows

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"

		 CModel facultadD;
CModel biblioteca;
CModel islas;
CModel torreHumanidades;
CModel torreHumanidades2;
CModel inge;
CTexture tree;
GLfloat razon = 3.141592 * 2;

float rotate = 0.0f;
float def = 0.1f;
float elev = 0.0f;
float desp = 0.0f;
float rot = 0.0f;
float asp = 0.0f;
float ond = 0.0f;
float ang = 0.0f;
float des = 0.0f;
float despX = 0.0f;
float despY = 0.0f;
float despZ = 0.0f;
float dY = 0.0f;
float t = -3.0f;
int edo_pel = 0;
int edo_agua = 0;
int edo = 0;
int edo_asp = 0;
bool anim = false;


float lluviaY = 0.0f;
float caida = 0.0f;


CFiguras pasto;
CFiguras isla;
CFiguras camino;
CTexture t_placasRectoria;
CTexture t_escalerasIslas;
CTexture t_piedra;
CTexture t_caminoIslas;
CTexture texturaPasto;

CTexture lluvia; //Textura de lluvia
CTexture v_arqT; //Textura de ventanas en talleres de Arquitectura
CTexture ladrillos; //Textura de ladrillos de edificios
CTexture vent2_arq;	//Textura de ventanas en talleres de arquitectura v2
CTexture techo; //Textura impermeable en techo
CTexture grass; //Textura de pasto
CTexture piso_arq1; //Textura de piso por DGOSE y talleres
CTexture v_DGOSE; //Textura de ventanas en DGOSE
CTexture m_DGOSE; //Textura de muro de piedra en DGOSE
CTexture m_Amarillo; //Textura de muro amarillo
CTexture piedra_Dext; //Textura de piedra en muros DGOSE aledaños
CTexture piso_l; //Textura de piso de ladrillos
CTexture v_gen; //Textura genérica de ventanas
CTexture f_arq; //Textura de frente de Arquitectura
CTexture lados_arq; //Textura de costados en edificio principal Arquitectura
CTexture izq_arq; //Textura del lado izquierdo del edificio principal Arquitectura
CTexture piso_p; //Textura de piso de piedra
CTexture est_arqui; //Textura de estacionamiento de arquitectura
CTexture p_arq; //Textura de pared arquitectura
CTexture ent_arq; //Textura de entrada a Arquitectura
CTexture pared_t; //Textura de paredes en tallres arquitectura
CTexture v_MUCA; //Textura de entrada a MUCA
CTexture p_gen; //Textura de piedra genérica
CTexture t_MUCA; //Textura de techo MUCA
CTexture t_zc; //Textura de tiendas en zona comercial
CTexture v_zc; //Textura de vidrios en zona comercial
CTexture cajas; //Textura de cajas en zona comercial
CTexture p_cajas; //Textura de piso por zona comercial
CTexture exp_rect; //Textura de la explanada de Rectoría
CTexture m1; //Textura de muro enfrente de zona comercial
CTexture pared_r; //Textura de pared aledaña a Torre de Rectoría
CTexture mbaja; //Textura de muro en parte baja edificio en Rectoría
CTexture v1; //Textura superior edificio por Rectoría
CTexture v_rect; //Textura de ventanas en Rectoría
CTexture i_rect; //Textura de intermedio en Rectoría
CTexture m_rect; //Textura de mural en Rectoría
CTexture l_rect; //Textura de logo en Rectoría
CTexture m_atras; //Textura de mural atrás en Rectoría
CTexture p_tar; //Textura de tarima por Rectoría
CTexture p_gral; //Textura general de piso
CTexture v_der; //Textura de ventanas en Derecho
CTexture p_marg; //Textura de piso en alrededores de las Islas
CTexture salones; //Textura de salones en Principal
CTexture front; //Textura frontal edificio A Principal
CTexture bib; //Textura de biblioteca en Principal
CTexture bar_princ; //Textura de muro en Principal
CTexture a_di; //Textura de persianas en Diseño Industrial
CTexture t_di; //Textura de techo en Diseño Industrial
CTexture v_di; //Textura de ventanas en Diseño Industrial
CTexture m_arquiIslas;
CTexture r_arquiIslas;
CTexture cielo;
CTexture agua;
CTexture metal;
CTexture frac;

CFiguras fig1;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
CCamera objCamera;

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 
//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int font = (int)GLUT_BITMAP_HELVETICA_18;

//Otras opciones son:
/*GLUT_BITMAP_8_BY_13
GLUT_BITMAP_9_BY_15
GLUT_BITMAP_TIMES_ROMAN_10
GLUT_BITMAP_TIMES_ROMAN_24
GLUT_BITMAP_HELVETICA_10
GLUT_BITMAP_HELVETICA_12
GLUT_BITMAP_HELVETICA_18*/



GLUquadricObj *quadratic;				// Storage For Our Quadratic Objects ( NEW )


//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = { 18 };

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = { 22 };



float colorR = 0.0;
float colorG = 0.0;
float colorB = 0.0;


void InitGL()     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);

	glEnable(GL_COLOR_MATERIAL);					//Habilitar GlColor3f
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glPolygonMode(GL_BACK, GL_LINE);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE);			// Set The Blending Function For Translucency
	//glColor4f(1.0f, 1.0f, 1.0f, 0.5); 


	biblioteca._3dsLoad("biblioteca/biblioteca.3ds");
	biblioteca.LoadTextureImages();
	biblioteca.GLIniTextures();
	biblioteca.ReleaseTextureImages();

	inge._3dsLoad("principal/ingenieria.3ds");
	inge.LoadTextureImages();
	inge.GLIniTextures();
	inge.ReleaseTextureImages();

	torreHumanidades._3dsLoad("torreHumanidades/torreHumanidades.3ds");
	torreHumanidades.LoadTextureImages();
	torreHumanidades.GLIniTextures();
	torreHumanidades.ReleaseTextureImages();

	torreHumanidades2._3dsLoad("torreHumanidades2/torreHumanidades2.3ds");
	torreHumanidades2.LoadTextureImages();
	torreHumanidades2.GLIniTextures();
	torreHumanidades2.ReleaseTextureImages();

	frac.LoadTGA("frac.tga");
	frac.BuildGLTexture();
	frac.ReleaseImage();

	agua.LoadTGA("water.tga");
	agua.BuildGLTexture();
	agua.ReleaseImage();

	metal.LoadBMP("metal2.bmp");
	metal.BuildGLTexture();
	metal.ReleaseImage();

	tree.LoadTGA("Tree.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	cielo.LoadBMP("01.bmp");
	cielo.BuildGLTexture();
	cielo.ReleaseImage();

	texturaPasto.LoadTGA("pasto.tga");
	texturaPasto.BuildGLTexture();
	texturaPasto.ReleaseImage();

	facultadD._3dsLoad("derecho3DS/derecho.3ds");
	facultadD.LoadTextureImages();
	facultadD.GLIniTextures();
	facultadD.ReleaseTextureImages();

	t_placasRectoria.LoadTGA("city/pasto01.tga");
	t_placasRectoria.BuildGLTexture();
	t_placasRectoria.ReleaseImage();

	t_escalerasIslas.LoadTGA("cuadrosrectoria/texturaEsc.tga");
	t_escalerasIslas.BuildGLTexture();
	t_escalerasIslas.ReleaseImage();

	lluvia.LoadTGA("rain.tga");
	lluvia.BuildGLTexture();
	lluvia.ReleaseImage();

	v_arqT.LoadTGA("ventanas_arquitalleres.tga");
	v_arqT.BuildGLTexture();
	v_arqT.ReleaseImage();

	ladrillos.LoadTGA("ladrillos_edificios.tga");
	ladrillos.BuildGLTexture();
	ladrillos.ReleaseImage();

	vent2_arq.LoadTGA("ventanas_arqui.tga");
	vent2_arq.BuildGLTexture();
	vent2_arq.ReleaseImage();

	techo.LoadTGA("techo.tga");
	techo.BuildGLTexture();
	techo.ReleaseImage();

	grass.LoadTGA("pasto.tga");
	grass.BuildGLTexture();
	grass.ReleaseImage();

	piso_arq1.LoadTGA("piso_arqui1.tga");
	piso_arq1.BuildGLTexture();
	piso_arq1.ReleaseImage();

	v_DGOSE.LoadTGA("ventanas_DGOSE.tga");
	v_DGOSE.BuildGLTexture();
	v_DGOSE.ReleaseImage();

	m_DGOSE.LoadTGA("muro_DGOSE.tga");
	m_DGOSE.BuildGLTexture();
	m_DGOSE.ReleaseImage();

	m_Amarillo.LoadTGA("muroAmarillo.tga");
	m_Amarillo.BuildGLTexture();
	m_Amarillo.ReleaseImage();

	piedra_Dext.LoadTGA("piedra_DGOSE_ext.tga");
	piedra_Dext.BuildGLTexture();
	piedra_Dext.ReleaseImage();

	piso_l.LoadTGA("piso_ladrillo.tga");
	piso_l.BuildGLTexture();
	piso_l.ReleaseImage();

	v_gen.LoadTGA("ventanas_gen.tga");
	v_gen.BuildGLTexture();
	v_gen.ReleaseImage();

	f_arq.LoadTGA("frente_arq.tga");
	f_arq.BuildGLTexture();
	f_arq.ReleaseImage();

	lados_arq.LoadTGA("vent_arq.tga");
	lados_arq.BuildGLTexture();
	lados_arq.ReleaseImage();

	izq_arq.LoadTGA("izq_arqui.tga");
	izq_arq.BuildGLTexture();
	izq_arq.ReleaseImage();

	piso_p.LoadTGA("piso_piedra.tga");
	piso_p.BuildGLTexture();
	piso_p.ReleaseImage();

	est_arqui.LoadTGA("est_arqui.tga");
	est_arqui.BuildGLTexture();
	est_arqui.ReleaseImage();

	p_arq.LoadTGA("pared_arq.tga");
	p_arq.BuildGLTexture();
	p_arq.ReleaseImage();

	ent_arq.LoadTGA("ent_arq.tga");
	ent_arq.BuildGLTexture();
	ent_arq.ReleaseImage();

	pared_t.LoadTGA("pared_taller.tga");
	pared_t.BuildGLTexture();
	pared_t.ReleaseImage();

	v_MUCA.LoadTGA("v_MUCA.tga");
	v_MUCA.BuildGLTexture();
	v_MUCA.ReleaseImage();

	p_gen.LoadTGA("piedra_gen.tga");
	p_gen.BuildGLTexture();
	p_gen.ReleaseImage();

	t_MUCA.LoadTGA("techo_MUCA.tga");
	t_MUCA.BuildGLTexture();
	t_MUCA.ReleaseImage();

	t_zc.LoadTGA("tiendas_zc.tga");
	t_zc.BuildGLTexture();
	t_zc.ReleaseImage();

	v_zc.LoadTGA("vidrio_zc.tga");
	v_zc.BuildGLTexture();
	v_zc.ReleaseImage();

	cajas.LoadTGA("cajas.tga");
	cajas.BuildGLTexture();
	cajas.ReleaseImage();

	p_cajas.LoadTGA("piso_cajas.tga");
	p_cajas.BuildGLTexture();
	p_cajas.ReleaseImage();

	exp_rect.LoadTGA("exp_rect.tga");
	exp_rect.BuildGLTexture();
	exp_rect.ReleaseImage();

	m1.LoadTGA("mural1.tga");
	m1.BuildGLTexture();
	m1.ReleaseImage();

	pared_r.LoadTGA("muro1_Rect.tga");
	pared_r.BuildGLTexture();
	pared_r.ReleaseImage();

	mbaja.LoadTGA("mbaja_Rect.tga");
	mbaja.BuildGLTexture();
	mbaja.ReleaseImage();

	v1.LoadTGA("v1.tga");
	v1.BuildGLTexture();
	v1.ReleaseImage();

	v_rect.LoadTGA("v_rect.tga");
	v_rect.BuildGLTexture();
	v_rect.ReleaseImage();

	i_rect.LoadTGA("inter_rect.tga");
	i_rect.BuildGLTexture();
	i_rect.ReleaseImage();

	m_rect.LoadTGA("mural_rect.tga");
	m_rect.BuildGLTexture();
	m_rect.ReleaseImage();

	l_rect.LoadTGA("logo_rect.tga");
	l_rect.BuildGLTexture();
	l_rect.ReleaseImage();

	m_atras.LoadTGA("m_atras.tga");
	m_atras.BuildGLTexture();
	m_atras.ReleaseImage();

	p_tar.LoadTGA("p_tarima.tga");
	p_tar.BuildGLTexture();
	p_tar.ReleaseImage();

	p_gral.LoadTGA("piso_gral.tga");
	p_gral.BuildGLTexture();
	p_gral.ReleaseImage();

	v_der.LoadTGA("vent_der.tga");
	v_der.BuildGLTexture();
	v_der.ReleaseImage();

	p_marg.LoadTGA("piso_margen.tga");
	p_marg.BuildGLTexture();
	p_marg.ReleaseImage();

	a_di.LoadTGA("arriba_disint.tga");
	a_di.BuildGLTexture();
	a_di.ReleaseImage();

	t_di.LoadTGA("techo_disint.tga");
	t_di.BuildGLTexture();
	t_di.ReleaseImage();

	v_di.LoadTGA("v_disint.tga");
	v_di.BuildGLTexture();
	v_di.ReleaseImage();

	salones.LoadTGA("salones.tga");
	salones.BuildGLTexture();
	salones.ReleaseImage();

	t_piedra.LoadTGA("biblioteca/volcan.tga");
	t_piedra.BuildGLTexture();
	t_piedra.ReleaseImage();

	t_caminoIslas.LoadTGA("biblioteca/techo_2.tga");
	t_caminoIslas.BuildGLTexture();
	t_caminoIslas.ReleaseImage();

	m_arquiIslas.LoadTGA("muroArquiIslas.tga");
	m_arquiIslas.BuildGLTexture();
	m_arquiIslas.ReleaseImage();

	r_arquiIslas.LoadTGA("rampaArquiIslas.tga");
	r_arquiIslas.BuildGLTexture();
	r_arquiIslas.ReleaseImage();

	quadratic = gluNewQuadric();			// Create A Pointer To The Quadric Object ( NEW )
	gluQuadricNormals(quadratic, GLU_SMOOTH);	// Create Smooth Normals ( NEW )
	gluQuadricTexture(quadratic, GL_TRUE);		// Create Texture Coords ( NEW )


	objCamera.Position_Camera(0, 2.5f, 3, 0, 2.5f, 0, 0, 1, 0);



}

void prisma(float x, float y, float z, GLuint tfront, GLuint tback, GLuint tleft, GLuint tright, GLuint tup, GLuint tdown, float vx_f, float vy_f, float vx_b, float vy_b, float vx_l, float vy_l, float vx_r, float vy_r, float vx_u, float vy_u, float vx_d, float vy_d){

	glBindTexture(GL_TEXTURE_2D, tright);
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0, vy_r); glVertex3f(x / 2, y / 2, z / 2); 	//Cara derecha
	glTexCoord2f(0.0, 0.0); glVertex3f(x / 2, -y / 2, z / 2);
	glTexCoord2f(vx_r, 0.0); glVertex3f(x / 2, -y / 2, -z / 2);
	glTexCoord2f(vx_r, vy_r); glVertex3f(x / 2, y / 2, -z / 2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tup);
	glBegin(GL_QUADS);
	glNormal3f(0.0, 1.0, 0.0);
	glTexCoord2f(vx_u, vy_u); glVertex3f(x / 2, y / 2, -z / 2);	//Cara superior
	glTexCoord2f(0.0, vy_u); glVertex3f(-x / 2, y / 2, -z / 2);
	glTexCoord2f(0.0, 0.0); glVertex3f(-x / 2, y / 2, z / 2);
	glTexCoord2f(vx_u, 0.0); glVertex3f(x / 2, y / 2, z / 2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tleft);
	glBegin(GL_QUADS);
	glNormal3f(-1.0, 0.0, 0.0);
	glTexCoord2f(vx_l, vy_l); glVertex3f(-x / 2, y / 2, z / 2);	//Cara izquierda
	glTexCoord2f(0.0, vy_l); glVertex3f(-x / 2, y / 2, -z / 2);
	glTexCoord2f(0.0, 0.0); glVertex3f(-x / 2, -y / 2, -z / 2);
	glTexCoord2f(vx_l, 0.0); glVertex3f(-x / 2, -y / 2, z / 2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tdown);
	glBegin(GL_QUADS);
	glNormal3f(0.0, -1.0, 0.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-x / 2, -y / 2, -z / 2);	//Cara inferior
	glTexCoord2f(vx_l, 0.0); glVertex3f(x / 2, -y / 2, -z / 2);
	glTexCoord2f(vx_l, vy_l); glVertex3f(x / 2, -y / 2, z / 2);
	glTexCoord2f(0.0, vy_l); glVertex3f(-x / 2, -y / 2, z / 2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tfront);
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(vx_f, 0.0); glVertex3f(x / 2, -y / 2, z / 2);	//Cara frontal
	glTexCoord2f(vx_f, vy_f); glVertex3f(x / 2, y / 2, z / 2);
	glTexCoord2f(0.0, vy_f); glVertex3f(-x / 2, y / 2, z / 2);
	glTexCoord2f(0.0, 0.0); glVertex3f(-x / 2, -y / 2, z / 2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tback);
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, -1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(x / 2, -y / 2, -z / 2);	//Cara posterior
	glTexCoord2f(vx_b, 0.0); glVertex3f(-x / 2, -y / 2, -z / 2);
	glTexCoord2f(vx_b, vy_b); glVertex3f(-x / 2, y / 2, -z / 2);
	glTexCoord2f(0.0, vy_b); glVertex3f(x / 2, y / 2, -z / 2);
	glEnd();
}


void plano(GLuint textura, float vx, float vy)
{
	glBindTexture(GL_TEXTURE_2D, textura);
	glBegin(GL_QUADS);
	glNormal3f(0.0, 1.0, 0.0);
	glTexCoord2f(0.0, vy); glVertex3f(-1.0, 0.0, -1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, 0.0, 1.0);
	glTexCoord2f(vx, 0.0); glVertex3f(1.0, 0.0, 1.0);
	glTexCoord2f(vx, vy); glVertex3f(1.0, 0.0, -1.0);
	glEnd();
}

void medioCilindro(GLfloat y, GLfloat r, GLint  div, GLuint t1, GLuint t2, GLuint t3){
	int i;

	for (i = 1; i <= div; i++){

		glBindTexture(GL_TEXTURE_2D, t1);
		glBegin(GL_TRIANGLES);

		//Plano de circunferencia base inferior
		glNormal3f(0.0, -1.0, 0.0);
		glTexCoord2f(0.5, 1.0); glVertex3f(0, -y / 2, 0);
		glTexCoord2f(0.0, 0.0); glVertex3f(r*cos((i - 1)*3.141592 / div), -y / 2, r*sin((i - 1)*3.141592 / div));
		glTexCoord2f(1.0, 0.0); glVertex3f(r*cos(i*3.141592 / div), -y / 2, r*sin(i*3.141592 / div));
		glEnd();

		glBindTexture(GL_TEXTURE_2D, t2);
		glBegin(GL_TRIANGLES);
		//Plano de circunferencia base superior
		glNormal3f(0.0, 1.0, 0.0);
		glTexCoord2f(0.5, 1.0); glVertex3f(0, y / 2, 0);
		glTexCoord2f(1.0, 0.0); glVertex3f(r*cos(i*3.141592 / div), y / 2, r*sin(i*3.141592 / div));
		glTexCoord2f(0.0, 0.0); glVertex3f(r*cos((i - 1)*3.141592 / div), y / 2, r*sin((i - 1)*3.141592 / div));
		glEnd();

		glBindTexture(GL_TEXTURE_2D, t3);
		//Plano lateral asociado a cada división
		glBegin(GL_QUADS);
		glNormal3f(r*cos((i - 0.5)*3.141592 / div), 0, r*sin((i - 0.5)*3.141592 / div));
		glTexCoord2f(1.0, 1.0); glVertex3f(r*cos(i*3.141592 / div), y / 2, r*sin(i*3.141592 / div));
		glTexCoord2f(1.0, 0.0); glVertex3f(r*cos(i*3.141592 / div), -y / 2, r*sin(i*3.141592 / div));
		glTexCoord2f(0.0, 0.0); glVertex3f(r*cos((i - 1)*3.141592 / div), -y / 2, r*sin((i - 1)*3.141592 / div));
		glTexCoord2f(0.0, 1.0); glVertex3f(r*cos((i - 1)*3.141592 / div), y / 2, r*sin((i - 1)*3.141592 / div));
		glEnd();
	}
}

void medioCilindroPuente(GLfloat y, GLfloat r1, GLfloat r2, GLint  div){
	int i;

	for (i = 1; i <= div; i++){

		glBegin(GL_QUADS);

		//Plano de circunferencia base inferior
		glVertex3f(r2*cos(i*3.141592*0.5 / div), -y / 2, r2*sin(i*3.141592*0.5 / div));
		glVertex3f(r2*cos((i - 1)*3.141592*0.5 / div), -y / 2, r2*sin((i - 1)*3.141592*0.5 / div));
		glVertex3f(r1*cos((i - 1)*3.141592*0.5 / div), -y / 2, r1*sin((i - 1)*3.141592*0.5 / div));
		glVertex3f(r1*cos(i*3.141592*0.5 / div), -y / 2, r1*sin(i*3.141592*0.5 / div));

		//Plano de circunferencia base superior
		glVertex3f(r2*cos((i - 1)*3.141592*0.5 / div), y / 2, r2*sin((i - 1)*3.141592*0.5 / div));
		glVertex3f(r2*cos(i*3.141592*0.5 / div), y / 2, r2*sin(i*3.141592*0.5 / div));
		glVertex3f(r1*cos(i*3.141592*0.5 / div), y / 2, r1*sin(i*3.141592*0.5 / div));
		glVertex3f(r1*cos((i - 1)*3.141592*0.5 / div), y / 2, r1*sin((i - 1)*3.141592*0.5 / div));

		//Plano lateral asociado a cada división
		glVertex3f(r1*cos(i*3.141592*0.5 / div), y / 2, r1*sin(i*3.141592*0.5 / div));
		glVertex3f(r1*cos(i*3.141592*0.5 / div), -y / 2, r1*sin(i*3.141592*0.5 / div));
		glVertex3f(r1*cos((i - 1)*3.141592*0.5 / div), -y / 2, r1*sin((i - 1)*3.141592*0.5 / div));
		glVertex3f(r1*cos((i - 1)*3.141592*0.5 / div), y / 2, r1*sin((i - 1)*3.141592*0.5 / div));

		//Plano lateral asociado a cada división
		glVertex3f(r2*cos(i*3.141592*0.5 / div), y / 2, r2*sin(i*3.141592*0.5 / div));
		glVertex3f(r2*cos((i - 1)*3.141592*0.5 / div), y / 2, r2*sin((i - 1)*3.141592*0.5 / div));
		glVertex3f(r2*cos((i - 1)*3.141592*0.5 / div), -y / 2, r2*sin((i - 1)*3.141592*0.5 / div));
		glVertex3f(r2*cos(i*3.141592*0.5 / div), -y / 2, r2*sin(i*3.141592*0.5 / div));

		glEnd();
	}
}

void cilindro(GLfloat y, GLfloat r, GLint  div){
	int i;
	glPushMatrix();

	for (i = 1; i <= div; i++){
		glBegin(GL_TRIANGLES);

		//Plano de circunferencia base inferior
		glVertex3f(0, -y / 2, 0);
		glVertex3f(r*cos((i - 1)*razon / div), -y / 2, r*sin((i - 1)*razon / div));
		glVertex3f(r*cos(i*razon / div), -y / 2, r*sin(i*razon / div));

		//Plano de circunferencia base superior
		glVertex3f(0, y / 2, 0);
		glVertex3f(r*cos(i*razon / div), y / 2, r*sin(i*razon / div));
		glVertex3f(r*cos((i - 1)*razon / div), y / 2, r*sin((i - 1)*razon / div));
		glEnd();

		//Plano lateral asociado a cada división
		glBegin(GL_QUADS);
		glVertex3f(r*cos(i*razon / div), y / 2, r*sin(i*razon / div));
		glVertex3f(r*cos(i*razon / div), -y / 2, r*sin(i*razon / div));
		glVertex3f(r*cos((i - 1)*razon / div), -y / 2, r*sin((i - 1)*razon / div));
		glVertex3f(r*cos((i - 1)*razon / div), y / 2, r*sin((i - 1)*razon / div));
		glEnd();
	}
	glPopMatrix();
}


void cono(GLfloat y, GLfloat r, GLint div){
	int i;
	for (i = 1; i <= div; i++){
		glBegin(GL_TRIANGLES);

		//Plano de circunferencia de base
		glVertex3f(0, -y / 2, 0);
		glVertex3f(r*cos((i - 1)*razon / div), -y / 2, r*sin((i - 1)*razon / div));
		glVertex3f(r*cos(i*razon / div), -y / 2, r*sin(i*razon / div));

		//Plano lateral
		glVertex3f(0, y / 2, 0);
		glVertex3f(r*cos(i*razon / div), -y / 2, r*sin(i*razon / div));
		glVertex3f(r*cos((i - 1)*razon / div), -y / 2, r*sin((i - 1)*razon / div));
		glEnd();
	}
}
void esfera(GLfloat r, GLint merid, GLint par, GLuint text)
{
	glBindTexture(GL_TEXTURE_2D, text);
	for (int i = 0; i<par; i++)
	{
		for (int j = 0; j < merid / 2; j++)
		{
			glBegin(GL_QUADS);
			glTexCoord2f(j / par, i / merid);
			glVertex3f(r*sin(2 * 3.141592*(i) / merid)*cos(2 * 3.141592*(j) / par), r*cos(i * 2 * 3.141592 / merid), r*sin(2 * 3.141592*(i) / merid)*sin(2 * 3.141592*(j) / par));

			glTexCoord2f(j / par, (i + 1) / merid);
			glVertex3f(r*sin(2 * 3.141592*(i + 1) / merid)*cos(2 * 3.141592*(j) / par), r*cos((i + 1) * 2 * 3.141592 / merid), r*sin(2 * 3.141592*(i + 1) / merid)*sin(2 * 3.141592*(j) / par));

			glTexCoord2f((j + 1) / par, (i + 1) / merid);
			glVertex3f(r*sin(2 * 3.141592*(i + 1) / merid)*cos(2 * 3.141592*(j + 1) / par), r*cos((i + 1) * 2 * 3.141592 / merid), r*sin(2 * 3.141592*(i + 1) / merid)*sin(2 * 3.141592*(j + 1) / par));

			glTexCoord2f((j + 1) / par, i / merid);
			glVertex3f(r*sin(2 * 3.141592*(i) / merid)*cos(2 * 3.141592*(j + 1) / par), r*cos((i)* 2 * 3.141592 / merid), r*sin(2 * 3.141592*(i) / merid)*sin(2 * 3.141592*(j + 1) / par));

			glEnd();
		}
	}

}

void escaleras(int numEscalones, float altura, float largo, float ancho, int hueco, GLuint text)
{
	for (int i = 0; i<numEscalones; i++)
	{
		glPushMatrix();
		glTranslatef(0.0, i*altura / (2.0*numEscalones), -i*ancho / numEscalones);
		if (hueco == 0) prisma(largo, i*altura / numEscalones, ancho / numEscalones, text, text, text, text, text, text, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
		else prisma(largo, altura / numEscalones, ancho / numEscalones, text, text, text, text, text, text, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
		glPopMatrix();
	}
}

void talleresArqui()
{
	glPushMatrix();
	prisma(7, 7, 7, vent2_arq.GLindex, pared_t.GLindex, vent2_arq.GLindex, vent2_arq.GLindex, techo.GLindex, 0, 1, 2, 1, 2, 1, 2, 3, 2, 1, 1, 0, 0);
	glTranslatef(4.0, 0.1, -2.5);
	prisma(12, 7.2, 6, v_arqT.GLindex, v_arqT.GLindex, pared_t.GLindex, pared_t.GLindex, techo.GLindex, 0, 5, 2, 6, 2, 4, 4, 4, 4, 1, 1, 0, 0);
	glPopMatrix();
}

void tallerArqui()
{
	glPushMatrix();

	prisma(12, 7.2, 6, v_arqT.GLindex, v_arqT.GLindex, pared_t.GLindex, pared_t.GLindex, techo.GLindex, 0, 5, 2, 6, 2, 4, 4, 4, 4, 1, 1, 0, 0);
	glTranslatef(5.0, -0.1, 2.5);
	prisma(7, 7, 7, vent2_arq.GLindex, pared_t.GLindex, vent2_arq.GLindex, vent2_arq.GLindex, techo.GLindex, 0, 1, 2, 1, 2, 1, 2, 3, 2, 1, 1, 0, 0);
	glPopMatrix();
}

void tallerArquiDist1()
{
	talleresArqui();
	glPushMatrix();
	glTranslatef(7.2, 0.05, 2.5);
	prisma(7.5, 7.1, 4.5, v_arqT.GLindex, pared_t.GLindex, pared_t.GLindex, v_arqT.GLindex, techo.GLindex, 0, 5, 2, 1, 1, 4, 4, 4, 2, 3, 3, 0, 0);
	glPopMatrix();
}

void arquitectura()
{
	glPushMatrix();

	glPushMatrix();
	glTranslatef(21.0, -3.65, 23.0);
	glScalef(33, 0, 3);
	plano(est_arqui.GLindex, 6, 1);
	glPopMatrix();

	//Pasillos entre talleres
	glTranslatef(21.0, -3.65, -1.0);
	glScalef(33, 0, 22);
	plano(piso_p.GLindex, 10, 10);
	glPopMatrix();


	//Piso por DGOSE y talleres
	glPushMatrix();
	glTranslatef(33.0, -3.6, -13.0);
	glScalef(17.5, 1.0, 7.0);
	plano(piso_arq1.GLindex, 5, 5);
	glPopMatrix();



}

void Rectoria()
{
	//Edificio principal
	glPushMatrix();


	//Explanada en Rectoría
	glPushMatrix();
	glTranslatef(0.0, 0.0, 16);
	glScalef(39, 1, 50);
	plano(exp_rect.GLindex, 15, 15);
	glPopMatrix();

	//Escaleras a explanada
	glPushMatrix();
	glTranslatef(41.0, -0.5, 15.0);
	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	escaleras(8, 1, 101.2, 2.5, 1, techo.GLindex);
	glPopMatrix();

	//Previo a explanada
	glTranslatef(7.0, -0.6, 0.0);
	glPushMatrix();
	glTranslatef(0.0, 0.0, 16);
	prisma(14, 1, 86, 0, 0, 0, 0, exp_rect.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 18, 0, 0);
	glPopMatrix();
	//Saliente por rampa a explanada
	glTranslatef(11.0, -1.7, 11.5);
	prisma(18, 4, 47.5, piedra_Dext.GLindex, piedra_Dext.GLindex, piso_p.GLindex, piso_p.GLindex, piso_p.GLindex, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);

	//Rampa a explanada
	/*glPushMatrix();
	glTranslatef(-1.3, -2.0, -5.0);
	glPushMatrix();
	glRotatef(-30, 0.0, 0.0, 1.0);
	prisma(9, 5, 60, piedra_Dext.GLindex, piedra_Dext.GLindex, piedra_Dext.GLindex, piedra_Dext.GLindex, piedra_Dext.GLindex, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2);
	glPopMatrix();*/

	//Piso previo a rampa
	glTranslatef(6.3, -3.0, 0.0);
	//prisma(16, 5, 90, p_marg.GLindex, 0, 0, 0, p_marg.GLindex, 0, 6, 1, 0, 0, 0, 0, 0, 0, 16, 16, 0, 0);

	glPopMatrix();

	//Piso previo a rampa
	glPushMatrix();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(8.0, 0.0, 0.0);
	glPushMatrix();
	//Edificio por torre de Rectoría
	glTranslatef(-15.0, 6.2, 20.0);
	prisma(13, 6, 20, m1.GLindex, m_atras.GLindex, pared_r.GLindex, pared_r.GLindex, techo.GLindex, 0, 1, 1, 1, 1, 5, 1, 5, 1, 1, 1, 0, 0);

	//Parte baja edificio por Rectoría
	glTranslatef(0.0, -5.0, 0.0);
	prisma(10, 4, 20, mbaja.GLindex, mbaja.GLindex, mbaja.GLindex, mbaja.GLindex, 0, 0, 3, 1, 3, 1, 6, 1, 6, 1, 0, 0, 0, 0);

	//Camino techado por Rectoría
	glPushMatrix();
	glTranslatef(-2.5, 2.0, -34.0);
	prisma(2, 0.8, 51, 0, 0, 0, 0, techo.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0);

	glTranslatef(-0.8, -2.4, -30);
	for (int i = 2; i<20; i++)
	{
		glPushMatrix();
		glTranslatef(0.0, 0.0, i * 58 / 20.0);
		cilindro(4, 0.1, 10);
		glTranslatef(1.0, 0.0, 0.0);
		cilindro(4, 0.1, 10);
		glPopMatrix();
	}
	glPopMatrix();


	//Suelo por edificio Rectoría
	glPushMatrix();
	glTranslatef(3.0, -1.8, 0.0);
	prisma(22, 1.3, 24, 0, 0, 0, 0, piedra_Dext.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0);
	glPopMatrix();


	//Parte alta edificio por Rectoría
	glPushMatrix();
	glTranslatef(0.0, 8.0, 0.0);
	prisma(7, 2, 15, v1.GLindex, v1.GLindex, v1.GLindex, v1.GLindex, techo.GLindex, 0, 4, 1, 4, 1, 6, 1, 6, 1, 1, 1, 0, 0);
	glPopMatrix();

	//Columnas edificio por Rectoría
	glTranslatef(-6.0, 0.0, -9.4);
	for (int i = 0; i<8; i++)
	{
		glPushMatrix();
		glTranslatef(0.0, 0.0, i*19.6 / 8);
		prisma(0.3, 4, 0.3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		glTranslatef(11.8, 0.0, 0.0);
		prisma(0.3, 4, 0.3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		glPopMatrix();
	}
	glPopMatrix();

	//Primer cuadro edificio Rectoría
	glTranslatef(-7.0, 7.0, 8.1);
	prisma(10, 14, 10, v_rect.GLindex, v_rect.GLindex, v_rect.GLindex, v_rect.GLindex, 0, 0, 8, 4, 8, 4, 8, 4, 8, 4, 0, 0, 0, 0);

	//Intermedio Rectoria
	glTranslatef(0.0, 8.0, 0.0);
	prisma(10, 2, 10, i_rect.GLindex, i_rect.GLindex, i_rect.GLindex, i_rect.GLindex, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0);

	//Saliente intermedio Rectoría
	glPushMatrix();
	glTranslatef(6.0, -1.0, 0.0);
	prisma(2, 4, 7, m_rect.GLindex, m_rect.GLindex, 0, m_rect.GLindex, techo.GLindex, 0, 0.2, 0.2, 0.2, 0.2, 0, 0, 1, 1, 1, 1, 0, 0);
	glPopMatrix();

	//Último tramo Rectoría
	glTranslatef(0.0, 10.0, 0.0);
	prisma(10, 18, 10, v_rect.GLindex, v_rect.GLindex, v_rect.GLindex, v_rect.GLindex, techo.GLindex, 0, 6, 9, 6, 9, 6, 9, 6, 9, 1, 1, 0, 0);

	//Franja en Rectoría
	glTranslatef(-4.0, -6.5, -3.0);
	prisma(5, 37, 5, p_arq.GLindex, p_arq.GLindex, l_rect.GLindex, v_rect.GLindex, techo.GLindex, 0, 2, 2, 3, 14, 1, 1, 4, 14, 1, 1, 0, 0);
	glPopMatrix();

	glPopMatrix();
}

void arq()
{
	glPushMatrix();
	//Tramo pegado a talleres
	glTranslatef(-12, 3.5, 8.2);
	prisma(9, 18, 35, f_arq.GLindex, p_arq.GLindex, izq_arq.GLindex, lados_arq.GLindex, techo.GLindex, 0, 1, 1, 1, 1, 10, 4, 7, 4, 1, 1, 0, 0);

	//Tramo horizontal
	glTranslatef(-21, -2, -14);
	prisma(35, 9.0, 7, izq_arq.GLindex, v_MUCA.GLindex, p_arq.GLindex, 0, techo.GLindex, 0, 10, 3, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0);

	//Marquesina por MUCA horizontal y vertical
	glPushMatrix();
	glTranslatef(-8.75, -2.0, -4.5);
	prisma(17.5, 0.8, 2, 0, 0, 0, 0, techo.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0);

	glTranslatef(-7.25, 0.0, -5.5);
	prisma(2, 0.8, 9.5, 0, 0, 0, 0, techo.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0);

	glTranslatef(-3.5, 0.0, -3.7);
	prisma(6, 0.8, 2, 0, 0, 0, 0, techo.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0);
	glPopMatrix();

	//Parte baja tramo horizontal
	glPushMatrix();
	glTranslatef(-6.0, -7.0, 0.0);
	prisma(25, 5, 7, p_gen.GLindex, p_gen.GLindex, p_gen.GLindex, p_gen.GLindex, piso_p.GLindex, 0, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 0, 0);

	//Piso acceso a MUCA
	glTranslatef(0.0, -1.5, -8.0);
	prisma(25, 3, 12, 0, piedra_Dext.GLindex, 0, piedra_Dext.GLindex, piso_p.GLindex, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0);

	//Escaleras acceso a MUCA
	glPushMatrix();
	glTranslatef(2.0, 0.75, -7.6);
	glRotatef(180, 0.0, 1.0, 0.0);

	//escaleras(8, 1, 101.2, 2.5, 1, techo.GLindex);
	escaleras(8, 1, 10.5, 2, 0, techo.GLindex);

	glPopMatrix();

	glPopMatrix();

	//Tramo pegado a MUCA
	glTranslatef(-13, -2.5, 13);
	prisma(9.5, 9, 20, 0, 0, 0, p_arq.GLindex, techo.GLindex, 0, 0, 0, 0, 0, 0, 0, 10, 10, 1, 1, 0, 0);

	//Saliente pegado a MUCA
	glPushMatrix();
	glTranslatef(0.0, 7.0, 7.5);
	prisma(9.5, 5, 4, ladrillos.GLindex, ladrillos.GLindex, ladrillos.GLindex, ladrillos.GLindex, techo.GLindex, 0, 10, 10, 10, 10, 10, 10, 10, 10, 1, 1, 1, 1);
	glPopMatrix();

	//Borde derecho MUCA
	glTranslatef(-7, -0.1, 1);
	prisma(40, 8.8, 22, ent_arq.GLindex, p_arq.GLindex, 0, p_arq.GLindex, t_MUCA.GLindex, 0, 1, 1, 1, 1, 0, 0, 6, 6, 5, 5, 0, 0);

	//Faltante MUCA
	glTranslatef(-8.5, 0, -16);
	prisma(23, 8.8, 10, 0, 0, 0, 0, t_MUCA.GLindex, 0, 0, 0, 1, 1, 0, 0, 0, 0, 5, 5, 0, 0);

	//Marquesinas MUCA
	glPushMatrix();
	glTranslatef(-13.5, 4.09, 24.7142);
	for (int i = 0; i<7; i++)
	{
		glPushMatrix();
		glTranslatef(0.0, -0.62*i, -4.5714*i);
		prisma(4.0, 0.32, 4.5714, 0, 0, 0, 0, techo.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0);
		glPopMatrix();
	}
	glPopMatrix();

	//Techo zona comercial
	glPushMatrix();
	glTranslatef(-28.0, 0.6, -8.7142);
	prisma(70, 0.8, 8, 0, 0, 0, 0, techo.GLindex, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0);

	glPushMatrix();
	glTranslatef(40.7, -2.94, -2.8);
	for (int i = 0; i<44; i++)
	{
		glPushMatrix();
		glTranslatef(-i*77.0 / 44, 0.0, 0.0);
		cilindro(4.98, 0.2, 10);
		glPopMatrix();
	}
	glPopMatrix();

	//Techo aparte en zona comercial
	glPushMatrix();
	glTranslatef(-25.17, -1.9, 7.0);
	prisma(20.33, 4.8, 8, 0, cajas.GLindex, 0, 0, t_MUCA.GLindex, 0, 0, 0, 1, 1, 0, 0, 0, 0, 2, 2, 0, 0);
	glPopMatrix();
	glPopMatrix();

	//Tiendas primera parte
	glPushMatrix();
	glTranslatef(-18.0, -1.85, -6.6);
	prisma(15.0, 4.98, 3.5, 0, t_zc.GLindex, p_arq.GLindex, 0, 0, 0, 0, 0, 7, 1, 1, 1, 0, 0, 0, 0, 0, 0);

	//Vidrios segunda parte
	glTranslatef(-15.0, 0.0, 0.0);
	prisma(10.0, 4.98, 3.5, 0, v_zc.GLindex, 0, v_zc.GLindex, 0, 0, 0, 0, 7, 1, 0, 0, 4, 1, 0, 0, 0, 0);
	glPopMatrix();

	//Piso zona de cajas
	glPushMatrix();
	glTranslatef(-24.5, -4.4, -6.7142);
	glPushMatrix();
	glScalef(78, 1, 11);
	prisma(1, 0.4, 1, 0, 0, 0, 0, piedra_Dext.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 1, 0, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void muroArquiIslas(GLfloat ax, GLfloat ay, GLfloat az, GLuint text){
	float alt = ay;
	float ancho = 66;
	glBindTexture(GL_TEXTURE_2D, text);

	glBegin(GL_QUADS);//para que se vea la textura bien xD
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0, 0); glVertex3f(ax, ay, az);
	glTexCoord2f(1.0, 0); glVertex3f(ax, ay - alt, az);
	glTexCoord2f(1.0, 1.0); glVertex3f(ax + ancho, ay - alt, az);
	glTexCoord2f(1, 0.0); glVertex3f(ax + ancho, ay, az);

	glEnd();
}

void rampaArquiIslas(GLfloat ax, GLfloat ay, GLfloat az, GLuint text){
	float alt = ay;
	float ancho = 12.5;
	float largo = 45;
	
	glBindTexture(GL_TEXTURE_2D, text);
	glBegin(GL_QUADS);//para que se vea la textura bien xD
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0, 0); glVertex3f(ax, ay, az);
	glTexCoord2f(1.0, 0); glVertex3f(ax, ay - alt, az + largo);
	glTexCoord2f(1.0, 1.0); glVertex3f(ax + ancho, ay - alt, az + largo);
	glTexCoord2f(1, 0.0); glVertex3f(ax + ancho, ay , az);
	glEnd();
}

void rampaArquiMUCA(GLfloat ax, GLfloat ay, GLfloat az, GLuint text){
	float alt = 3;
	float ancho = 32;
	float largo = 12.5;
	glBindTexture(GL_TEXTURE_2D, text);

	glBegin(GL_QUADS);//para que se vea la textura bien xD
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0, 0); glVertex3f(ax, ay, az);
	glTexCoord2f(1.0, 0); glVertex3f(ax, ay - alt, az + largo);
	glTexCoord2f(1.0, 1.0); glVertex3f(ax + ancho, ay - alt, az + largo);
	glTexCoord2f(1, 0.0); glVertex3f(ax + ancho, ay, az);
	/*
	glTexCoord2f(0, 0); glVertex3f(ax, ay, az);
	glTexCoord2f(1.0, 0); glVertex3f(ax + ancho, ay, az);
	glTexCoord2f(1.0, 1.0); glVertex3f(ax + ancho, ay, az + 31.65);
	glTexCoord2f(1, 0.0); glVertex3f(ax, ay, az + 31.65);
	*/
	glEnd();
}

void pisoArqui(GLfloat ax, GLfloat ay, GLfloat az, GLuint text){
	float alt = ay;
	float ancho = 96;

	float largo = 80;
	glBindTexture(GL_TEXTURE_2D, text);

	glBegin(GL_QUADS);//para que se vea la textura bien xD
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0, 0); glVertex3f(ax, ay, az);
	glTexCoord2f(1.0, 0); glVertex3f(ax + ancho, ay, az);
	glTexCoord2f(1.0, 1.0); glVertex3f(ax + ancho, ay, az + largo);
	glTexCoord2f(1, 0.0); glVertex3f(ax, ay, az + largo);
	glEnd();
}

void pisoArqui1(GLfloat ax, GLfloat ay, GLfloat az, GLuint text){
	float alt = ay;
	float ancho = 40;

	float largo = 60;
	glBindTexture(GL_TEXTURE_2D, text);

	glBegin(GL_QUADS);//para que se vea la textura bien xD
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0, 0); glVertex3f(ax, ay, az);
	glTexCoord2f(1.0, 0); glVertex3f(ax + ancho, ay, az);
	glTexCoord2f(1.0, 1.0); glVertex3f(ax + ancho, ay, az + largo);
	glTexCoord2f(1, 0.0); glVertex3f(ax, ay, az + largo);
	glEnd();
}

void pintaTexto(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
	//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}

void generaCuadro(GLfloat ax, GLfloat ay, GLfloat az, GLuint text){
	glBindTexture(GL_TEXTURE_2D, text);
	glBegin(GL_QUADS);//para que se vea la textura bien xD
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0, 0); glVertex3f(ax, ay, az);
	glTexCoord2f(1.0, 0); glVertex3f(ax + 3.7, ay, az);
	glTexCoord2f(1.0, 1.0); glVertex3f(ax + 3.7, ay, az + 3.7);
	glTexCoord2f(1, 0.0); glVertex3f(ax, ay, az + 3.7);
	glEnd();
}

void escalerasIslasRectoria(GLfloat ax, GLfloat ay, GLfloat az, GLuint text, GLint cont){
	GLfloat ancho;
	if (cont == 10 || cont == 20)
		ancho = 2.5;
	else
		ancho = 0.3;

	glBindTexture(GL_TEXTURE_2D, text);
	glBegin(GL_QUADS);//para que se vea la textura bien xD
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0, 0); glVertex3f(ax, ay, az);
	glTexCoord2f(1.0, 0); glVertex3f(ax + ancho, ay, az);
	glTexCoord2f(1.0, 1.0); glVertex3f(ax + ancho, ay, az + 31.65);
	glTexCoord2f(1, 0.0); glVertex3f(ax, ay, az + 31.65);


	glEnd();
}

void escalerasIslasRectoria1(GLfloat ax, GLfloat ay, GLfloat az, GLuint text, GLint cont){

	GLfloat ancho;
	if (cont == 10 || cont == 20)
		ancho = 2.5;
	else
		ancho = 0.3;
	glBindTexture(GL_TEXTURE_2D, text);

	glBegin(GL_QUADS);//para que se vea la textura bien xD
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0, 0); glVertex3f(ax + ancho, ay, az);
	glTexCoord2f(1.0, 0); glVertex3f(ax + ancho, ay - 0.24, az);
	glTexCoord2f(1.0, 1.0); glVertex3f(ax + ancho, ay - 0.24, az + 31.65);
	glTexCoord2f(1, 0.0); glVertex3f(ax + ancho, ay, az + 31.65);

	glEnd();
}

void prisma_disInt1()
{
	//Parte frontal rectángulos extremos
	glBindTexture(GL_TEXTURE_2D, a_di.GLindex);
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.5, 0.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.5, 3.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 3.0, 0.0);

	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.5, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(6.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(6.0, 4.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.5, 4.0, 0.0);
	glEnd();

	//Parte frontal rectángulo inclinado
	glBegin(GL_TRIANGLES);
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(1.5, 0.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.5, 1.0, 0.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(1.5, 3.0, 0.0);

	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.5, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.5, 4.0, 0.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(1.5, 3.0, 0.0);
	glEnd();

	//Parte posterior rectángulos extremos
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(0.0, 0.0, -14.0);
	glVertex3f(1.5, 0.0, -14.0);
	glVertex3f(1.5, 3.0, -14.0);
	glVertex3f(0.0, 3.0, -14.0);

	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(4.5, 1.0, -14.0);
	glVertex3f(6.0, 1.0, -14.0);
	glVertex3f(6.0, 4.0, -14.0);
	glVertex3f(4.5, 4.0, -14.0);
	glEnd();

	//Parte frontal rectángulo inclinado
	glBegin(GL_TRIANGLES);
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(1.5, 0.0, -14.0);
	glVertex3f(4.5, 1.0, -14.0);
	glVertex3f(1.5, 3.0, -14.0);

	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(4.5, 1.0, -14.0);
	glVertex3f(4.5, 4.0, -14.0);
	glVertex3f(1.5, 3.0, -14.0);
	glEnd();

	//Uniones
	glBindTexture(GL_TEXTURE_2D, techo.GLindex);
	glBegin(GL_QUADS);
	//Arriba
	glNormal3f(0.0, 1.0, 0.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 3.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.5, 3.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.5, 3.0, -14.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 3.0, -14.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(1.5, 3.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.5, 4.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.5, 4.0, -14.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(1.5, 3.0, -14.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(4.5, 4.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(6.0, 4.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(6.0, 4.0, -14.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(4.5, 4.0, -14.0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, t_di.GLindex);
	glBegin(GL_QUADS);
	//Abajo
	glNormal3f(0.0, -1.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.5, 0.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.5, 0.0, -14.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, -14.0);

	glTexCoord2f(0.0, 1.0); glVertex3f(1.5, 0.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(4.5, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.5, 1.0, -14.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(1.5, 0.0, -14.0);

	glTexCoord2f(0.0, 1.0); glVertex3f(4.5, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(6.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(6.0, 1.0, -14.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.5, 1.0, -14.0);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, techo.GLindex);
	glBegin(GL_QUADS);
	//Izquierda
	glNormal3f(-1.0, 0.0, 0.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 1.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 1.0, -14.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.0, 0.0, -14.0);

	//Derecha
	glNormal3f(1.0, 0.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(6.0, 3.0, 0.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(6.0, 3.0, -14.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(6.0, 4.0, -14.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(6.0, 4.0, 0.0);

	glEnd();

	//Planta baja
	glBindTexture(GL_TEXTURE_2D, piso_p.GLindex);
	glBegin(GL_QUADS);
	//Triángulo Frente
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(1.5, 0.0, -1.5);
	glTexCoord2f(0.0, 1.0); glVertex3f(6.0, 0.0, -1.5);
	glTexCoord2f(1.0, 1.0); glVertex3f(6.0, 1.0, -1.5);
	glTexCoord2f(1.0, 0.0); glVertex3f(4.5, 1.0, -1.5);

	//Triángulo Atrás
	glTexCoord2f(1.0, 0.0); glVertex3f(1.5, 0.0, -14.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(6.0, 0.0, -14.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(6.0, 1.0, -14.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(4.5, 1.0, -14.0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, ladrillos.GLindex);
	glBegin(GL_QUADS);
	//Fachada
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, -1.5);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, -1.5, -1.5);
	glTexCoord2f(5.0, 1.0); glVertex3f(6.0, -1.5, -1.5);
	glTexCoord2f(5.0, 0.0); glVertex3f(6.0, 0.0, -1.5);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, v_DGOSE.GLindex);
	glBegin(GL_QUADS);
	//Atrás
	glNormal3f(0.0, 0.0, -1.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 0.0, -14.0);
	glTexCoord2f(3.0, 1.0); glVertex3f(6.0, 0.0, -14.0);
	glTexCoord2f(3.0, 0.0); glVertex3f(6.0, -1.5, -14.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, -1.5, -14.0);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, p_gral.GLindex);
	glBegin(GL_QUADS);
	//Piso
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 10.0); glVertex3f(0.0, -1.5, 0.0);
	glTexCoord2f(10.0, 10.0); glVertex3f(6.0, -1.5, 0.0);
	glTexCoord2f(10.0, 0.0); glVertex3f(6.0, -1.5, -1.5);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, -1.5, -1.5);

	glEnd();

	//Columna corta
	glPushMatrix();
	glTranslatef(0.3, -0.75, -0.3);
	cilindro(1.5, 0.2, 10);
	glPopMatrix();


	//Columna larga
	glPushMatrix();
	glTranslatef(3.1, -0.32, -0.3);
	cilindro(2.36, 0.2, 10);
	glPopMatrix();

}

void prisma_disInt2()
{
	glBindTexture(GL_TEXTURE_2D, a_di.GLindex);
	glBegin(GL_QUADS);
	//Persianas parte alta
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(8.0, 0.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(8.0, 3.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 3.0, 0.0);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, v_DGOSE.GLindex);
	glBegin(GL_QUADS);
	//Atrás parte alta
	glNormal3f(0.0, 0.0, -1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, -14.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 3.0, -14.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(8.0, 3.0, -14.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(8.0, 0.0, -14.0);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, v_di.GLindex);
	glBegin(GL_QUADS);
	//Ventanas frente
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 0.0, -1.6 / 4);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, -1.5, -1.6 / 4);
	glTexCoord2f(1.0, 0.0); glVertex3f(8.0, -1.5, -1.6 / 4);
	glTexCoord2f(1.0, 1.0); glVertex3f(8.0, 0.0, -1.6 / 4);

	//Ventanas atrás
	glNormal3f(0.0, 0.0, -1.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 0.0, -14.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(8.0, 0.0, -14.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(8.0, -1.5, -14.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, -1.5, -14.0);
	glEnd();

	glBegin(GL_QUADS);

	//Unión columnas
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, -1.6);
	glVertex3f(8.0, 0.0, -1.6);
	glVertex3f(8.0, 0.0, 0.0);

	//Pared abajo
	glVertex3f(8.0, -1.5, -0.4);
	glVertex3f(8.0, -1.5, -14.0);
	glVertex3f(8.0, 0.0, -14.0);
	glVertex3f(8.0, 0.0, -0.4);

	//Pared arriba
	glVertex3f(8.0, 0.0, 0.0);
	glVertex3f(8.0, 0.0, -14.0);
	glVertex3f(8.0, 3.0, -14.0);
	glVertex3f(8.0, 3.0, 0.0);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, techo.GLindex);
	glBegin(GL_QUADS);
	//Techo
	glNormal3f(0.0, 1.0, 0.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 3.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(8.0, 3.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(8.0, 3.0, -14.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.0, 3.0, -14.0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, p_gral.GLindex);
	glBegin(GL_QUADS);
	//Piso
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 10.0); glVertex3f(0.0, -1.5, 4.0);
	glTexCoord2f(10.0, 10.0); glVertex3f(8.0, -1.5, 4.0);
	glTexCoord2f(10.0, 0.0); glVertex3f(8.0, -1.5, -0.4);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, -1.5, -0.4);

	glEnd();

	//Columna derecha
	glPushMatrix();
	glTranslatef(0.3, -0.75, -0.3);
	cilindro(1.5, 0.2, 10);

	//Columna izquierda
	glTranslatef(3.5, 0.0, 0.0);
	cilindro(1.5, 0.2, 10);
	glPopMatrix();

}

void prisma_disInt3()
{
	glBindTexture(GL_TEXTURE_2D, a_di.GLindex);
	glBegin(GL_QUADS);
	//Persianas parte alta
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(6.0, 0.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(6.0, 3.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 3.0, 0.0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, v_DGOSE.GLindex);
	glBegin(GL_QUADS);
	//Atrás parte alta
	glNormal3f(0.0, 0.0, -1.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, -14.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 3.0, -14.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(6.0, 3.0, -14.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(6.0, 0.0, -14.0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, ladrillos.GLindex);
	glBegin(GL_QUADS);
	//Ventanas frente
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 0.0, -1.6);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, -1.5, -1.6);
	glTexCoord2f(1.0, 0.0); glVertex3f(6.0, -1.5, -1.6);
	glTexCoord2f(1.0, 1.0); glVertex3f(6.0, 0.0, -1.6);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, v_DGOSE.GLindex);
	glBegin(GL_QUADS);
	//Ventanas atrás
	glNormal3f(0.0, 0.0, -1.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 0.0, -14.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(6.0, 0.0, -14.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(6.0, -1.5, -14.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, -1.5, -14.0);

	//Unión columnas
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, -1.6);
	glVertex3f(6.0, 0.0, -1.6);
	glVertex3f(6.0, 0.0, 0.0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, techo.GLindex);
	glBegin(GL_QUADS);
	//Techo
	glNormal3f(0.0, 1.0, 0.0);
	glTexCoord2f(0.0, 0.1); glVertex3f(0.0, 3.0, 0.0);
	glTexCoord2f(1.0, 0.1); glVertex3f(6.0, 3.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(6.0, 3.0, -14.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 3.0, -14.0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, p_gral.GLindex);
	glBegin(GL_QUADS);
	//Piso
	glNormal3f(0.0, 1.0, 0.0);
	glTexCoord2f(0.0, 10.0); glVertex3f(0.0, -1.5, 0.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, -1.5, -1.6);
	glTexCoord2f(10.0, 0.0); glVertex3f(6.0, -1.5, -1.6);
	glTexCoord2f(10.0, 10.0); glVertex3f(6.0, -1.5, 0.0);

	glEnd();

	//Columna derecha
	glPushMatrix();
	glTranslatef(3.0, -0.75, -0.3);
	cilindro(1.5, 0.2, 10);

	//Columna izquierda
	glTranslatef(2.7, 0.0, 0.0);
	cilindro(1.5, 0.2, 10);
	glPopMatrix();

}

void prisma_disInt4()
{
	glPushMatrix();
	glTranslatef(32, 0.75, -7);
	prisma(64, 4.5, 14, v_DGOSE.GLindex, v_DGOSE.GLindex, p_arq.GLindex, p_arq.GLindex, techo.GLindex, 0, 15, 3, 15, 3, 1, 1, 1, 1, 1, 1, 0, 0);
	glPopMatrix();
}

void prisma_disInt5()
{
	glPushMatrix();
	glTranslatef(7.0, 1.5, -7.0);
	prisma(14, 3, 14, a_di.GLindex, 0, 0, 0, techo.GLindex, t_di.GLindex, 3, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, ladrillos.GLindex);
	glBegin(GL_QUADS);
	//Pared frontal
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(6.0, 0.0); glVertex3f(14.0, -1.5, -1.5);
	glTexCoord2f(6.0, 1.0); glVertex3f(14.0, 0.0, -1.5);
	glTexCoord2f(0.0, 1.0); glVertex3f(1.5, 0.0, -1.5);
	glTexCoord2f(0.0, 0.0); glVertex3f(1.5, -1.5, -1.5);

	//Pared izquierda
	glNormal3f(-1.0, 0.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(1.5, -1.5, -1.5);
	glTexCoord2f(6.0, 1.0); glVertex3f(1.5, 0.0, -1.5);
	glTexCoord2f(6.0, 0.0); glVertex3f(1.5, 0.0, -14.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(1.5, -1.5, -14.0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, p_gral.GLindex);
	glBegin(GL_QUADS);

	//Piso
	glNormal3f(0.0, 0.0, 10.0);
	glTexCoord2f(0.0, 10.0); glVertex3f(0.0, -1.5, 0.0);
	glTexCoord2f(10.0, 10.0); glVertex3f(14.0, -1.5, 0.0);
	glTexCoord2f(10.0, 0.0); glVertex3f(14.0, -1.5, -14.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, -1.5, -14.0);

	glEnd();
}

void auditorioAlfonso()
{
	glBegin(GL_QUADS);
	//Pared frontal
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 3.0, 0.0);
	glVertex3f(-17.0, 3.0, 4.0);
	glVertex3f(-17.0, 0.0, 4.0);

	//Pared trasera
	glVertex3f(0.0, 0.0, -14.0);
	glVertex3f(-17.0, 0.0, -18.0);
	glVertex3f(-17.0, 3.0, -18.0);
	glVertex3f(0.0, 3.0, -14.0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, techo.GLindex);
	glBegin(GL_QUADS);
	//Techo
	glNormal3f(0.0, 1.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.0, 3.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 3.0, -14.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-17.0, 3.0, -18.0);
	glTexCoord2f(.0, 0.0); glVertex3f(-17.0, 3.0, 4.0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, t_di.GLindex);
	glBegin(GL_QUADS);
	//Abajo
	glNormal3f(0.0, -1.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(-17.0, 0.0, 4.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-17.0, 0.0, -18.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, -14.0);

	glEnd();

	glBegin(GL_QUADS);
	//Columna en pasillo (frente)
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, -1.5, 0.0);
	glVertex3f(0.0, -1.5, -5.0);
	glVertex3f(0.0, 0.0, -5.0);

	//Columna en pasillo (atrás)
	glVertex3f(-0.5, 0.0, 0.0);
	glVertex3f(-0.5, 0.0, -5.0);
	glVertex3f(-0.5, -1.5, -5.0);
	glVertex3f(-0.5, -1.5, 0.0);

	//Unión visible columna
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(-0.5, 0.0, 0.0);
	glVertex3f(-0.5, -1.5, 0.0);
	glVertex3f(0.0, -1.5, 0.0);

	//Unión no visible columna
	glVertex3f(0.0, 0.0, -5.0);
	glVertex3f(0.0, -1.5, -5.0);
	glVertex3f(-0.5, -1.5, -5.0);
	glVertex3f(-0.5, 0.0, -5.0);

	//Columna derecha
	//Columna en pasillo (frente)
	glVertex3f(0.0, 0.0, -9.0);
	glVertex3f(0.0, -1.5, -9.0);
	glVertex3f(0.0, -1.5, -14.0);
	glVertex3f(0.0, 0.0, -14.0);

	//Columna en pasillo (atrás)
	glVertex3f(-0.5, 0.0, -9.0);
	glVertex3f(-0.5, 0.0, -14.0);
	glVertex3f(-0.5, -1.5, -14.0);
	glVertex3f(-0.5, -1.5, -9.0);

	//Unión visible columna
	glVertex3f(0.0, 0.0, -9.0);
	glVertex3f(-0.5, 0.0, -9.0);
	glVertex3f(-0.5, -1.5, -9.0);
	glVertex3f(0.0, -1.5, -9.0);

	//Unión no visible columna
	glVertex3f(0.0, 0.0, -14.0);
	glVertex3f(0.0, -1.5, -14.0);
	glVertex3f(-0.5, -1.5, -14.0);
	glVertex3f(-0.5, 0.0, -14.0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, p_gral.GLindex);
	glBegin(GL_QUADS);
	//Piso con ladrillo
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(10.0, 10.0); glVertex3f(0.0, -1.5, 0.0);
	glTexCoord2f(10.0, 0.0); glVertex3f(0.0, -1.5, -14.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(-25.0, -1.5, -14.0);
	glTexCoord2f(0.0, 10.0); glVertex3f(-25.0, -1.5, 0.0);

	glEnd();

	glPushMatrix();
	//Semicírculo
	glTranslatef(-17.0, 1.5, -7.0);
	glRotatef(270, 0.0, 1.0, 0.0);
	medioCilindro(3, 11, 10, t_di.GLindex, techo.GLindex, v_DGOSE.GLindex);
	glPopMatrix();

	glPushMatrix();
	//Columna central
	glTranslatef(-3.2, -0.75, -7.0);
	cilindro(1.5, 0.2, 10);
	glPopMatrix();

	glPushMatrix();
	//Acceso
	glTranslatef(-14.0, -0.75, -7.0);
	prisma(17, 1.5, 8, ladrillos.GLindex, ladrillos.GLindex, ladrillos.GLindex, ladrillos.GLindex, 0, 0, 4, 1, 4, 1, 4, 1, 4, 1, 0, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();
	//Columna acceso izquierda
	glTranslatef(-3.2, -0.75, -3.5);
	prisma(0.3, 1.5, 5.0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	glTranslatef(0.0, 0.0, -7.5);
	prisma(0.3, 1.5, 5.0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	glPopMatrix();

}

void disenoIndustrial()
{
	for (int i = 0; i < 7; i++)
	{
		glPushMatrix();
		glTranslatef(i*6.0, 0.0, 0.0);
		prisma_disInt1();
		glTranslatef((i * 2) - 6, 0.0, -64.0);
		glPushMatrix();
		glRotatef(180, 0.0, 1.0, 0.0);
		prisma_disInt2();
		glPopMatrix();
		glPopMatrix();
		if (i<6)
		{
			glPushMatrix();
			glRotatef(270, 0.0, 1.0, 0.0);
			glTranslatef(-(i + 2) * 6 - 8.0, 0.0, 14.0);
			prisma_disInt3();
			glPopMatrix();
		}
	}
	glPushMatrix();
	glTranslatef(56.0, 0.0, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	prisma_disInt4();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-14.0, 0.0, 0.0);
	prisma_disInt5();
	glPopMatrix();

	//Conexión entre centro y bordes
	glPushMatrix();
	glTranslatef(2.5, 0.75, -29.5);
	prisma(5.0, 4.5, 25, v_DGOSE.GLindex, v_DGOSE.GLindex, v_DGOSE.GLindex, v_DGOSE.GLindex, techo.GLindex, 0, 4, 2, 4, 2, 4, 2, 4, 2, 1, 1, 0, 0);
	glPopMatrix();

	//Centro
	glPushMatrix();
	glTranslatef(15.0, 0.75, -32.0);
	prisma(20.0, 4.5, 30.0, v_DGOSE.GLindex, v_DGOSE.GLindex, v_DGOSE.GLindex, v_DGOSE.GLindex, techo.GLindex, 0, 4, 2, 4, 2, 4, 2, 4, 2, 1, 1, 0, 0);
	glPopMatrix();

	glPushMatrix();
	//Auditorio
	glTranslatef(-14.0, 0.0, 0.0);
	auditorioAlfonso();
	glPopMatrix();
}

void escalera_Principal()
{
	for (int i = 0; i<10; i++)
	{
		glBindTexture(GL_TEXTURE_2D, piedra_Dext.GLindex);
		glBegin(GL_QUADS);
		//Plano horizontal escalón
		glNormal3f(0.0, 1.0, 0.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(0.0, i*0.15, -0.3*i);
		glTexCoord2f(1.0, 0.0); glVertex3f(1.9, i*0.15, -0.3*i);
		glTexCoord2f(01.0, 1.0); glVertex3f(1.9, i*0.15, -0.3*(i + 1));
		glTexCoord2f(0.0, 1.0); glVertex3f(0.0, i*0.15, -0.3*(i + 1));

		//Plano vertical escalón
		glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(0.0, i*0.15, -0.3*(i + 1));
		glTexCoord2f(1.0, 0.0); glVertex3f(1.9, i*0.15, -0.3*(i + 1));
		glTexCoord2f(1.0, 1.0); glVertex3f(1.9, 0.15*(i + 1), -0.3*(i + 1));
		glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 0.15*(i + 1), -0.3*(i + 1));
		glEnd();
	}

	//Descanso entre escaleras
	glBindTexture(GL_TEXTURE_2D, piedra_Dext.GLindex);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 3.0); glVertex3f(0.0, 1.5, -3.0);
	glTexCoord2f(3.0, 3.0); glVertex3f(5.2, 1.5, -3.0);
	glTexCoord2f(3.0, 0.0); glVertex3f(5.2, 1.5, -5.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 1.5, -5.0);
	glEnd();

	for (int i = 0; i<10; i++)
	{
		glBindTexture(GL_TEXTURE_2D, piedra_Dext.GLindex);
		glBegin(GL_QUADS);
		//Segundo tramo escaleras
		glNormal3f(0.0, 1.0, 0.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(5.2, 1.5 + (0.15*i), -3.0 + (0.3*i));
		glTexCoord2f(0.0, 0.0); glVertex3f(3.3, 1.5 + (0.15*i), -3.0 + (0.3*i));
		glTexCoord2f(0.0, 1.0); glVertex3f(3.3, 1.5 + (0.15*i), -3.0 + (0.3*(i + 1)));
		glTexCoord2f(1.0, 1.0); glVertex3f(5.2, 1.5 + (0.15*i), -3.0 + (0.3*(i + 1)));

		//Plano vertical
		glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(3.3, 1.5 + (0.15*i), -3.0 + (0.3*(i + 1)));
		glTexCoord2f(0.0, 1.0); glVertex3f(3.3, 1.5 + (0.15*(i + 1)), -3.0 + (0.3*(i + 1)));
		glTexCoord2f(1.0, 1.0); glVertex3f(5.2, 1.5 + (0.15*(i + 1)), -3.0 + (0.3*(i + 1)));
		glTexCoord2f(1.0, 0.0); glVertex3f(5.2, 1.5 + (0.15*i), -3.0 + (0.3*(i + 1)));

		glEnd();
	}
}

void barandal_Principal(int inicio)
{
	glBegin(GL_QUADS);
	if (inicio == 0)
	{
		//Plano pegado a la escalera
		glNormal3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, -3.0);
		glVertex3f(0.0, 2.25, -3.0);
		glVertex3f(0.0, 0.75, 0.0);
	}
	else
	{
		glVertex3f(0.0, -0.2, 0.0);
		glVertex3f(0.0, 1.45, -3.0);
		glVertex3f(0.0, 2.25, -3.0);
		glVertex3f(0.0, 0.75, 0.0);
	}


	//Plano del descanso pegado a la escalera
	glVertex3f(0.0, 2.25, -3.0);
	glVertex3f(0.0, 1.45, -3.0);
	glVertex3f(0.0, 1.45, -5.2);
	glVertex3f(0.0, 2.25, -5.2);

	//Plano del descanso externo
	if (inicio == 0)
	{
		glVertex3f(-0.2, 2.25, -3.0);
		glVertex3f(-0.2, 0.0, -3.0);
		glVertex3f(-0.2, 0.0, -5.0);
		glVertex3f(-0.2, 2.25, -5.0);
	}
	else
	{
		glVertex3f(-0.2, 2.25, -3.0);
		glVertex3f(-0.2, 1.45, -3.0);
		glVertex3f(-0.2, 1.45, -5.0);
		glVertex3f(-0.2, 2.25, -5.0);
	}


	if (inicio == 1){
		//Plano externo
		glVertex3f(-0.2, -0.2, 0.0);
		glVertex3f(-0.2, 0.75, 0.0);
		glVertex3f(-0.2, 2.25, -3.0);
		glVertex3f(-0.2, 1.4, -3.0);
	}
	else
	{
		glVertex3f(-0.2, 0.0, 0.0);
		glVertex3f(-0.2, 0.75, 0.0);
		glVertex3f(-0.2, 2.25, -3.0);
		glVertex3f(-0.2, 0.0, -3.0);
	}


	if (inicio == 0){
		//Uniones
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.75, 0.0);
		glVertex3f(-0.2, 0.75, 0.0);
		glVertex3f(-0.2, 0.0, 0.0);
	}
	else
	{
		glVertex3f(0.0, -0.2, 0.0);
		glVertex3f(0.0, 0.75, 0.0);
		glVertex3f(-0.2, 0.75, 0.0);
		glVertex3f(-0.2, -0.2, 0.0);
	}

	//Inclinada
	glVertex3f(0.0, 0.75, 0.0);
	glVertex3f(0.0, 2.25, -3.0);
	glVertex3f(-0.2, 2.25, -3.0);
	glVertex3f(-0.2, 0.75, 0.0);


	//Superior descanso izquierdo
	glVertex3f(0.0, 2.25, -3.0);
	glVertex3f(0.0, 2.25, -5.0);
	glVertex3f(-0.2, 2.25, -5.0);
	glVertex3f(-0.2, 2.25, -3.0);


	//Interno descanso
	glVertex3f(0.0, 1.45, -5.0);
	glVertex3f(5.2, 1.45, -5.0);
	glVertex3f(5.2, 2.25, -5.0);
	glVertex3f(0.0, 2.25, -5.0);

	if (inicio == 0)
	{
		//Externo descanso
		glVertex3f(-0.2, 0.0, -5.2);
		glVertex3f(-0.2, 2.25, -5.2);
		glVertex3f(5.4, 2.25, -5.2);
		glVertex3f(5.4, 0.0, -5.2);
	}
	else
	{
		glVertex3f(-0.2, 1.45, -5.2);
		glVertex3f(-0.2, 2.25, -5.2);
		glVertex3f(5.4, 2.25, -5.2);
		glVertex3f(5.4, 1.45, -5.2);
	}

	//Superior entre descanso
	glVertex3f(-0.2, 2.25, -5.0);
	glVertex3f(5.4, 2.25, -5.0);
	glVertex3f(5.4, 2.25, -5.2);
	glVertex3f(-0.2, 2.25, -5.2);

	if (inicio == 0){
		//Plano faltante cara externa
		glVertex3f(-0.2, 2.25, -5.0);
		glVertex3f(-0.2, 2.25, -5.2);
		glVertex3f(-0.2, 0.0, -5.2),
			glVertex3f(-0.2, 0.0, -5.0);
	}
	else
	{
		glVertex3f(-0.2, 2.25, -5.0);
		glVertex3f(-0.2, 2.25, -5.2);
		glVertex3f(-0.2, 1.45, -5.2),
			glVertex3f(-0.2, 1.45, -5.0);
	}


	if (inicio == 0){
		//Parte baja a descanso, parte interna
		glVertex3f(1.9, 0.0, 0.0);
		glVertex3f(1.9, 0.75, 0.0);
		glVertex3f(1.9, 2.0, -2.9);
		glVertex3f(1.9, 0.0, -2.9);
	}
	else
	{
		glVertex3f(1.9, -0.2, 0.0);
		glVertex3f(1.9, 0.75, 0.0);
		glVertex3f(1.9, 2.0, -2.9);
		glVertex3f(1.9, 1.2, -2.9);
	}


	if (inicio == 0)
	{
		//Parte baja a descanso, parte externa
		glVertex3f(2.1, 0.0, 0.0);
		glVertex3f(2.1, 0.0, -2.9);
		glVertex3f(2.1, 2.0, -2.9);
		glVertex3f(2.1, 0.75, 0.0);
	}
	else
	{
		glVertex3f(2.1, -0.2, 0.0);
		glVertex3f(2.1, 1.45, -2.9);
		glVertex3f(2.1, 2.0, -2.9);
		glVertex3f(2.1, 0.75, 0.0);
	}



	if (inicio == 0)
	{
		//Uniones
		glVertex3f(1.9, 0.0, 0.0);
		glVertex3f(2.1, 0.0, 0.0);
		glVertex3f(2.1, 0.75, 0.0);
		glVertex3f(1.9, 0.75, 0.0);
	}
	else
	{
		glVertex3f(1.9, -0.2, 0.0);
		glVertex3f(2.1, -0.2, 0.0);
		glVertex3f(2.1, 0.75, 0.0);
		glVertex3f(1.9, 0.75, 0.0);
	}


	//Unión inclinada
	glVertex3f(1.9, 0.75, 0.0);
	glVertex3f(2.1, 0.75, 0.0);
	glVertex3f(2.1, 2.0, -2.9);
	glVertex3f(1.9, 2.0, -2.9);

	glColor3f(0.0, 0.0, 1.0);
	//Unión interna descanso
	glVertex3f(1.9, 1.45, -3.0);
	glVertex3f(1.9, 2.25, -3.0);
	glVertex3f(3.1, 2.25, -3.0);
	glVertex3f(3.1, 1.45, -3.0);
	glColor3f(1.0, 1.0, 1.0);


	if (inicio == 0)
	{
		//Union externa descanso
		glVertex3f(2.1, 2.25, -2.8);
		glVertex3f(2.1, 0.0, -2.8);
		glVertex3f(3.1, 0.0, -2.8);
		glVertex3f(3.1, 2.25, -2.8);
	}
	else
	{
		glVertex3f(2.1, 2.25, -2.8);
		glVertex3f(2.1, 1.45, -2.8);
		glVertex3f(3.1, 1.45, -2.8);
		glVertex3f(3.1, 2.25, -2.8);
	}

	//Unión superior descanso
	glVertex3f(1.9, 2.25, -2.8);
	glVertex3f(3.1, 2.25, -2.8);
	glVertex3f(3.1, 2.25, -3.0);
	glVertex3f(1.9, 2.25, -3.0);




	//Plano faltante interior descanso
	if (inicio == 0)
	{
		glVertex3f(1.9, 1.0, -2.8);
		glVertex3f(1.9, 2.25, -2.8);
		glVertex3f(1.9, 2.25, -3.0);
		glVertex3f(1.9, 1.0, -3.0);
	}
	else
	{
		glVertex3f(1.9, 1.2, -2.8);
		glVertex3f(1.9, 2.25, -2.8);
		glVertex3f(1.9, 2.25, -3.0);
		glVertex3f(1.9, 1.5, -3.0);
	}

	//Plano pequeño en descanso auxiliar
	glVertex3f(1.9, 1.75, -2.8);
	glVertex3f(2.1, 1.75, -2.8);
	glVertex3f(2.1, 2.25, -2.8);
	glVertex3f(1.9, 2.25, -2.8);

	//Descanso a primer nivel, cara interna
	glVertex3f(3.3, 1.2, -3.0);
	glVertex3f(3.3, 2.5, 0.0);
	glVertex3f(3.3, 3.75, 0.0);
	glVertex3f(3.3, 2.25, -3.0);

	//Descanso a primer nivel, cara externa
	glVertex3f(3.1, 1.2, -3.0);
	glVertex3f(3.1, 2.5, 0.0);
	glVertex3f(3.1, 3.75, 0.0);
	glVertex3f(3.1, 2.25, -3.0);

	//Unión sobre descanso inferior
	glVertex3f(3.1, 1.2, -3.0);
	glVertex3f(3.3, 1.2, -3.0);
	glVertex3f(3.3, 2.5, 0.0);
	glVertex3f(3.1, 2.5, 0.0);

	//Unión sobre descanso
	glVertex3f(3.1, 2.25, -3.0);
	glVertex3f(3.3, 2.25, -3.0);
	glVertex3f(3.3, 1.45, -3.0);
	glVertex3f(3.1, 1.45, -3.0);

	//Unión barandal
	glVertex3f(3.1, 2.25, -3.0);
	glVertex3f(3.1, 3.75, 0.0);
	glVertex3f(3.3, 3.75, 0.0);
	glVertex3f(3.3, 2.25, -3.0);

	//Parte externa descanso a primer nivel, cara interna
	glVertex3f(5.2, 1.45, -5.0);
	glVertex3f(5.2, 1.45, -3.0);
	glVertex3f(5.2, 2.25, -3.0);
	glVertex3f(5.2, 2.25, -5.0);

	//Parte externa descanso a primer nivel, cara externa
	if (inicio == 0)
	{
		glVertex3f(5.4, 0.0, -5.2);
		glVertex3f(5.4, 2.25, -5.2);
		glVertex3f(5.4, 2.25, -3.0);
		glVertex3f(5.4, 0.0, -3.0);
	}
	else
	{
		glVertex3f(5.4, 1.45, -5.2);
		glVertex3f(5.4, 2.25, -5.2);
		glVertex3f(5.4, 2.25, -3.0);
		glVertex3f(5.4, 1.45, -3.0);
	}

	//Unión de barandal
	glVertex3f(5.2, 2.25, -5.0);
	glVertex3f(5.2, 2.25, -3.0);
	glVertex3f(5.4, 2.25, -3.0);
	glVertex3f(5.4, 2.25, -5.0);

	//Barandal a primer nivel, cara interna
	glVertex3f(5.2, 1.0, -3.0);
	glVertex3f(5.2, 2.5, 0.0);
	glVertex3f(5.2, 3.75, 0.0);
	glVertex3f(5.2, 2.25, -3.0);

	//Barandal a primer nivel, cara externa
	if (inicio == 0)
	{
		glVertex3f(5.4, 1.0, -3.0);
		glVertex3f(5.4, 2.5, 0.0);
		glVertex3f(5.4, 3.75, 0.0);
		glVertex3f(5.4, 2.25, -3.0);
	}
	else
	{
		glVertex3f(5.4, 1.45, -3.0);
		glVertex3f(5.4, 2.5, 0.0);
		glVertex3f(5.4, 3.75, 0.0);
		glVertex3f(5.4, 2.25, -3.0);
	}

	//Unión barandal
	glVertex3f(5.2, 2.25, -3.0);
	glVertex3f(5.2, 3.75, 0.0);
	glVertex3f(5.4, 3.75, 0.0);
	glVertex3f(5.4, 2.25, -3.0);

	//Unión sobre descanso inferior
	if (inicio == 0)
	{
		glVertex3f(5.2, 1.0, -3.0);
		glVertex3f(5.4, 1.0, -3.0);
		glVertex3f(5.4, 2.5, 0.0);
		glVertex3f(5.2, 2.5, 0.0);
	}
	else
	{
		glVertex3f(5.2, 1.45, -3.0);
		glVertex3f(5.4, 1.45, -3.0);
		glVertex3f(5.4, 2.5, 0.0);
		glVertex3f(5.2, 2.5, 0.0);
	}

	//Unión barandal en primer nivel, derecho
	glVertex3f(5.2, 2.5, 0.0);
	glVertex3f(5.4, 2.5, 0.0);
	glVertex3f(5.4, 3.75, 0.0);
	glVertex3f(5.2, 3.75, 0.0);

	//Unión barandal en primer nivel, izquierdo
	glVertex3f(3.1, 2.5, 0.0);
	glVertex3f(3.3, 2.5, 0.0);
	glVertex3f(3.3, 3.75, 0.0);
	glVertex3f(3.1, 3.75, 0.0);



	//Plano a piso desde descanso
	if (inicio == 0)
	{
		glVertex3f(3.1, 1.45, -2.8);
		glVertex3f(3.1, 0.0, -2.8);
		glVertex3f(5.4, 0.0, -2.8);
		glVertex3f(5.4, 1.45, -2.8);

		//Plano aunxiliar
		glVertex3f(5.4, 0.0, -3.0);
		glVertex3f(5.4, 1.0, -3.0);
		glVertex3f(5.4, 1.0, -2.8);
		glVertex3f(5.4, 0.0, -2.8);
	}

	//Barandal descanso primer nivel,externo
	glVertex3f(2.1, 3.0, -0.2);
	glVertex3f(2.1, 3.75, -0.2);
	glVertex3f(3.3, 3.75, -0.2);
	glVertex3f(3.3, 3.0, -0.2);

	//Barandal descanso primer nivel, interno
	glVertex3f(2.1, 3.0, 0.0);
	glVertex3f(2.1, 3.75, 0.0);
	glVertex3f(3.3, 3.75, 0.0);
	glVertex3f(3.3, 3.0, 0.0);

	//Unión barandel primer nivel, superior
	glVertex3f(2.1, 3.75, 0.0);
	glVertex3f(2.1, 3.75, -0.2);
	glVertex3f(3.3, 3.75, -0.2);
	glVertex3f(3.3, 3.75, 0.0);


	glEnd();
}

void pisosPrincipal()
{
	for (int i = 0; i<4; i++)
	{
		glPushMatrix();
		glTranslatef(0.0, 3 * i, 0.0);
		if (i == 0)	barandal_Principal(0);
		else		barandal_Principal(1);
		escalera_Principal();
		glPopMatrix();
	}
}

void puentePrincipal()
{
	glPushMatrix();
	glTranslatef(0.0, -5.0, 0.0);
	//Arco de soporte
	glPushMatrix();
	glRotatef(90, 0.0, 0.0, 1.0);
	glRotatef(45, 0.0, 1.0, 0.0);
	medioCilindroPuente(3, 6, 5.5, 10);
	glPopMatrix();

	//Pasillo parte baja
	glPushMatrix();
	glTranslatef(0.0, 6.125, 0.0);
	prisma(3, 0.25, 8.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	glPopMatrix();

	//Columnas
	glPushMatrix();
	glTranslatef(-1.0, 7.3, 3.7);
	glScalef(1.0, 1.2, 1.0);
	for (int i = 0; i<9; i++)
	{
		glPushMatrix();
		glTranslatef(0.0, 0.0, -i*0.9);
		cilindro(2.0, 0.1, 10);
		glTranslatef(2.0, 0.0, 0.0);
		cilindro(2.0, 0.1, 10);
		glPopMatrix();
	}
	glPopMatrix();

	//Pasillo parte alta
	glPushMatrix();
	glTranslatef(0.0, 8.5, 0.0);
	prisma(3, 0.25, 8.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	glPopMatrix();

	//Barandales
	glPushMatrix();
	glTranslatef(1.4, 6.3, 0.0);
	prisma(0.2, 0.2, 8.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	glTranslatef(-2.8, 0.0, 0.0);
	prisma(0.2, 0.2, 8.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	glTranslatef(0.0, 2.4, 0.0);
	prisma(0.2, 0.2, 8.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	glTranslatef(2.8, 0.0, 0.0);
	prisma(0.2, 0.2, 8.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	glPopMatrix();

	glPopMatrix();
}

void plantaPrincipal(int a)
{
	if (a == 0)
	{
		glPushMatrix();
		glTranslatef(0.0, 0.0, 2.5);
		prisma(24.5, 0.5, 5, 0, p_arq.GLindex, p_arq.GLindex, p_arq.GLindex, p_gral.GLindex, t_di.GLindex, 1, 1, 1, 1, 1, 1, 1, 1, 50, 3, 0, 0);
		glPopMatrix();
	}
	else
	{
		glPushMatrix();
		glTranslatef(0.0, 0.0, 3.0);
		prisma(24.5, 0.5, 4, p_arq.GLindex, p_arq.GLindex, p_arq.GLindex, p_arq.GLindex, p_gral.GLindex, 0, 1, 1, 1, 1, 1, 1, 1, 1, 10, 2, 0, 0);
		glPopMatrix();
	}
	glPushMatrix();
	glTranslatef(0.0, 1.5, 3.5);
	prisma(24.5, 2.5, 3.0, front.GLindex, salones.GLindex, p_arq.GLindex, p_arq.GLindex, techo.GLindex, 0, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 0, 0);
	glPopMatrix();
}

void Principal()
{
	//Plantas
	prisma(35, 25, 10, front.GLindex, salones.GLindex, p_arq.GLindex, p_arq.GLindex, techo.GLindex, 0, 4, 3, 8, 3, 1, 1, 1, 1, 1, 1, 0, 0);
	glTranslatef(5, -15, 2.5);
	prisma(45, 5, 15, bib.GLindex, salones.GLindex, p_arq.GLindex, bib.GLindex, techo.GLindex, 0, 9, 1, 9, 1, 1, 1, 6, 3, 1, 1, 0, 0);
	glTranslatef(0.0, -6.75, 0.0);
	prisma(45, 8.5, 15, bar_princ.GLindex, salones.GLindex, p_arq.GLindex, p_arq.GLindex, 0, 0, 9, 1, 9, 2, 1, 1, 1, 1, 0, 0, 0, 0);
}


void arbol_alpha()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glBindTexture(GL_TEXTURE_2D, tree.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);

	glPopMatrix();
}

void plano(GLuint textura, int sent)
{
	glPushMatrix();
	glRotatef(45, 0.0, 0.0, 1.0);
	if (sent != 0) ond *= -1;
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	glBindTexture(GL_TEXTURE_2D, textura);
	glBegin(GL_TRIANGLES);
	glNormal3f(0.0, 0.0, 1.0);

	glTexCoord2f(0.0, 0.5 + des); glVertex3f(-1.0, 0.0, 0.0);
	glTexCoord2f(0.5, 1.0 + des); glVertex3f(0.0, 1.0, 0.0);
	glTexCoord2f(0.5, 0.5 + des); glVertex3f(0.0, 0.0, ond);

	glTexCoord2f(0.5, 1.0 + des); glVertex3f(0.0, 1.0, 0.0);
	glTexCoord2f(0.5, 0.5 + des); glVertex3f(0.0, 0.0, ond);
	glTexCoord2f(1.0, 0.5 + des); glVertex3f(1.0, 0.0, 0.0);

	glTexCoord2f(1.0, 0.5 + des); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord2f(0.5, 0.0 + des); glVertex3f(0.0, -1.0, 0.0);
	glTexCoord2f(0.5, 0.5 + des); glVertex3f(0.0, 0.0, ond);

	glTexCoord2f(0.5, 0.0 + des); glVertex3f(0.0, -1.0, 0.0);
	glTexCoord2f(0.5, 0.5 + des); glVertex3f(0.0, 0.0, ond);
	glTexCoord2f(0.0, 0.5 + des); glVertex3f(-1.0, 0.0, 0.0);
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();
	des += 0.08;
}

void plano(GLuint textura)
{
	glPushMatrix();
	glRotatef(45, 0.0, 0.0, 1.0);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);

	glBindTexture(GL_TEXTURE_2D, textura);
	glBegin(GL_TRIANGLES);
	glNormal3f(0.0, 0.0, 1.0);

	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 0.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 1.0, 0.0);
	glTexCoord2f(0.5, 0.5); glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 1.0, 0.0);
	glTexCoord2f(0.5, 0.5); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(1.0, 0.0, 0.0);

	glTexCoord2f(1.0, 0.0); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, -1.0, 0.0);
	glTexCoord2f(0.5, 0.5); glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, -1.0, 0.0);
	glTexCoord2f(0.5, 0.5); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 0.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
	des += 0.08;
}

void cilindro(GLfloat y, GLfloat r, GLint  div, GLuint t1, GLuint t2, GLuint t3){
	int i;
	glPushMatrix();

	for (i = 1; i <= div; i++){
		glBindTexture(GL_TEXTURE_2D, t1);
		glBegin(GL_TRIANGLES);

		//Plano de circunferencia base inferior
		glNormal3f(0.0, -1.0, 0.0);
		glTexCoord2f(0.5, 0.0); glVertex3f(0, -y / 2, 0);
		glTexCoord2f(0.0, 1.0); glVertex3f(r*cos((i - 1)*razon / div), -y / 2, r*sin((i - 1)*razon / div));
		glTexCoord2f(1.0, 1.0); glVertex3f(r*cos(i*razon / div), -y / 2, r*sin(i*razon / div));

		glEnd();

		glBindTexture(GL_TEXTURE_2D, t2);
		glBegin(GL_TRIANGLES);
		//Plano de circunferencia base superior
		glNormal3f(0.0, 1.0, 0.0);
		glTexCoord2f(0.5, 0.0); glVertex3f(0, y / 2, 0);
		glTexCoord2f(1.0, 1.0); glVertex3f(r*cos(i*razon / div), y / 2, r*sin(i*razon / div));
		glTexCoord2f(0.0, 1.0); glVertex3f(r*cos((i - 1)*razon / div), y / 2, r*sin((i - 1)*razon / div));
		glEnd();

		//Plano lateral asociado a cada división

		glBegin(GL_QUADS);
		glNormal3f(cos((i - 0.5)*razon / div), 0, sin((i - 0.5)*razon / div));
		glTexCoord2f(1.0, 1.0); glVertex3f(r*cos(i*razon / div), y / 2, r*sin(i*razon / div));
		glTexCoord2f(1.0, 0.0); glVertex3f(r*cos(i*razon / div), -y / 2, r*sin(i*razon / div));
		glTexCoord2f(0.0, 0.0); glVertex3f(r*cos((i - 1)*razon / div), -y / 2, r*sin((i - 1)*razon / div));
		glTexCoord2f(0.0, 1.0); glVertex3f(r*cos((i - 1)*razon / div), y / 2, r*sin((i - 1)*razon / div));
		glEnd();
	}
	glPopMatrix();
}

void medioCilindroPuente(GLfloat y, GLfloat r1, GLfloat r2, GLint div, GLuint t){
	int i;

	for (i = 1; i <= div; i++){
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		glBindTexture(GL_TEXTURE_2D, t);
		glBegin(GL_QUADS);

		//Plano de circunferencia base inferior
		glNormal3f(0.0, -1.0, 0.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(r2*cos(i*3.141592*0.5 / div), -y / 2, r2*sin(i*3.141592*0.5 / div));
		glTexCoord2f(0.0, 0.0); glVertex3f(r2*cos((i - 1)*3.141592*0.5 / div), -y / 2, r2*sin((i - 1)*3.141592*0.5 / div));
		glTexCoord2f(1.0, 0.0); glVertex3f(r1*cos((i - 1)*3.141592*0.5 / div), -y / 2, r1*sin((i - 1)*3.141592*0.5 / div));
		glTexCoord2f(1.0, 1.0); glVertex3f(r1*cos(i*3.141592*0.5 / div), -y / 2, r1*sin(i*3.141592*0.5 / div));

		//Plano de circunferencia base superior
		glNormal3f(0.0, 1.0, 0.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(r2*cos((i - 1)*3.141592*0.5 / div), y / 2, r2*sin((i - 1)*3.141592*0.5 / div));
		glTexCoord2f(0.0, 1.0); glVertex3f(r2*cos(i*3.141592*0.5 / div), y / 2, r2*sin(i*3.141592*0.5 / div));
		glTexCoord2f(1.0, 1.0); glVertex3f(r1*cos(i*3.141592*0.5 / div), y / 2, r1*sin(i*3.141592*0.5 / div));
		glTexCoord2f(1.0, 0.0); glVertex3f(r1*cos((i - 1)*3.141592*0.5 / div), y / 2, r1*sin((i - 1)*3.141592*0.5 / div));

		//Plano lateral asociado a cada división
		glNormal3f(cos(i*3.141592*0.5 / div), 0, sin(i*3.141592*0.5 / div));
		glTexCoord2f(1.0, 1.0); glVertex3f(r1*cos(i*3.141592*0.5 / div), y / 2, r1*sin(i*3.141592*0.5 / div));
		glTexCoord2f(1.0, 0.0); glVertex3f(r1*cos(i*3.141592*0.5 / div), -y / 2, r1*sin(i*3.141592*0.5 / div));
		glTexCoord2f(0.0, 0.0); glVertex3f(r1*cos((i - 1)*3.141592*0.5 / div), -y / 2, r1*sin((i - 1)*3.141592*0.5 / div));
		glTexCoord2f(0.0, 1.0); glVertex3f(r1*cos((i - 1)*3.141592*0.5 / div), y / 2, r1*sin((i - 1)*3.141592*0.5 / div));

		//Plano lateral asociado a cada división
		glNormal3f(-cos(i*3.141592*0.5 / div), 0, -sin(i*3.141592*0.5 / div));
		glTexCoord2f(0.0, 1.0); glVertex3f(r2*cos(i*3.141592*0.5 / div), y / 2, r2*sin(i*3.141592*0.5 / div));
		glTexCoord2f(1.0, 1.0); glVertex3f(r2*cos((i - 1)*3.141592*0.5 / div), y / 2, r2*sin((i - 1)*3.141592*0.5 / div));
		glTexCoord2f(1.0, 1.0); glVertex3f(r2*cos((i - 1)*3.141592*0.5 / div), -y / 2, r2*sin((i - 1)*3.141592*0.5 / div));
		glTexCoord2f(0.0, 0.0); glVertex3f(r2*cos(i*3.141592*0.5 / div), -y / 2, r2*sin(i*3.141592*0.5 / div));

		glEnd();
		glDisable(GL_BLEND);
	}
}

void cometa()
{
	glPushMatrix();
	glRotatef(rot, 0.0, 1.0, 0.0);
	glTranslatef(0.0, elev, desp);
	glBindTexture(GL_TEXTURE_2D, frac.GLindex);
	glBegin(GL_TRIANGLES);
	glNormal3f(0.0, 0.0, 1.0);

	glTexCoord2f(0.0, 0.5); glVertex3f(-1.0, 0.0, 0.0);
	glTexCoord2f(0.5, 1.0); glVertex3f(0.0, 1.5, 0.0);
	glTexCoord2f(0.5, 0.5); glVertex3f(0.0, 0.0, def);

	glTexCoord2f(0.5, 1.0); glVertex3f(0.0, 1.5, 0.0);
	glTexCoord2f(0.5, 0.5); glVertex3f(0.0, 0.0, def);
	glTexCoord2f(1.0, 0.5); glVertex3f(1.0, 0.0, 0.0);

	glTexCoord2f(1.0, 0.5); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord2f(0.5, 0.0); glVertex3f(0.0, -1.5, 0.0);
	glTexCoord2f(0.5, 0.5); glVertex3f(0.0, 0.0, def);

	glTexCoord2f(0.5, 0.0); glVertex3f(0.0, -1.5, 0.0);
	glTexCoord2f(0.5, 0.5); glVertex3f(0.0, 0.0, def);
	glTexCoord2f(0.0, 0.5); glVertex3f(-1.0, 0.0, 0.0);
	glEnd();

	cilindro(3.1, 0.05, 10);
	glPushMatrix();
	glRotatef(90, 0.0, 0.0, 1.0);
	cilindro(2.1, 0.05, 10);
	glPopMatrix();

	glPopMatrix();

}

void aspersor()
{
	glPushMatrix();
	glRotatef(asp, 0.0, 1.0, 0.0);
	cilindro(2, 3, 10, metal.GLindex, metal.GLindex, metal.GLindex);
	glTranslatef(0, 2.5, 0.0);
	cilindro(3, 1, 10, metal.GLindex, metal.GLindex, metal.GLindex);
	glTranslatef(0.0, 2.0, 0.0);
	cilindro(1, 2, 10, metal.GLindex, metal.GLindex, metal.GLindex);
	glPushMatrix();
	glRotatef(45, 0.0, 0.0, 1.0);
	glTranslatef(-0.5, 1.0, 0.0);
	cilindro(1, 0.4, 10, metal.GLindex, metal.GLindex, metal.GLindex);
	glTranslatef(-2.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(90, 0.0, 0.0, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glTranslatef(-1.5, 0.0, -8.0);
	medioCilindroPuente(0.4, 8, 7.5, 10, agua.GLindex);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void charco()
{
	glPushMatrix();
	plano(agua.GLindex, 0);
	glTranslatef(1.35, 0.0, 0.0);
	plano(agua.GLindex, 1);
	glTranslatef(0.0, 1.35, 0.0);
	plano(agua.GLindex, 0);
	glTranslatef(-1.35, 0.0, 0.0);
	plano(agua.GLindex, 1);

	glPopMatrix();
}

void pelota()
{
	glPushMatrix();
	glTranslatef(despX, despY, despZ);
	fig1.esfera2(3, 10, 10, piso_p.GLindex);
	glPopMatrix();
}


void DGOSE()
{
	glPushMatrix();
	//Planta baja, acceso
	prisma(30, 8, 15, v_DGOSE.GLindex, 0, 0, v_DGOSE.GLindex, 0, 0, 12, 1, 0, 0, 0, 0, 5, 1, 0, 0, 0, 0);

	//Piso planta baja
	glPushMatrix();
	glTranslatef(-10.0, -6.0, -10.0);
	prisma(80, 3, 70, 0, 0, 0, 0, p_gral.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0);
	glPopMatrix();

	//Muro de piedra 
	glTranslatef(-20, 0, 0);
	prisma(10, 8, 15, m_DGOSE.GLindex, 0, 0, 0, 0, 0, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

	//Papelería
	glTranslatef(-7.5, 0.0, 0.0);
	prisma(5, 8, 15, m_Amarillo.GLindex, 0, m_Amarillo.GLindex, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();
	//Techo
	glTranslatef(-10, 4.4, 1.5);
	prisma(50, 0.8, 18, 0, 0, 0, 0, techo.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0);
	glPopMatrix();

	glPushMatrix();
	//Techo por escaleras exterior
	glTranslatef(20.0, 4.4, 6.5);
	prisma(10, 0.8, 8, 0, 0, 0, 0, techo.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0);

	glPopMatrix();

	glPushMatrix();
	//Techo por escaleras costados
	glTranslatef(16.25, 4.4, -2.5);
	//Izquierda
	prisma(2.5, 0.8, 10, 0, 0, 0, 0, techo.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0);
	glTranslatef(3.75 * 2, 0.0, 0.0);
	//Derecha
	prisma(2.5, 0.8, 10, 0, 0, 0, 0, techo.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0);
	glTranslatef(-3.75, 0.0, -4.0);
	//A planta alta
	prisma(5, 0.8, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();
	//Pasillo planta alta
	glTranslatef(-2.5, 0.0, -9.5);

	//Horizontal
	prisma(55, 8, 4, m_Amarillo.GLindex, 0, m_Amarillo.GLindex, piedra_Dext.GLindex, piso_l.GLindex, 0, 1, 1, 0, 0, 1, 1, 2, 2, 10, 2, 0, 0);

	//Vertical
	glTranslatef(-25.5, 0.0, -12.0);
	prisma(4, 8, 20, 0, 0, m_Amarillo.GLindex, 0, piso_l.GLindex, 0, 0, 0, 0, 0, 1, 1, 0, 0, 3, 10, 0, 0);

	glPopMatrix();

	glPushMatrix();
	//Oficinas planta alta junto a escaleras
	glTranslatef(15, 4.4, -21.5);
	prisma(20, 16.8, 20, v_gen.GLindex, 0, v_gen.GLindex, 0, techo.GLindex, 0, 5, 3, 0, 0, 2, 2, 0, 0, 1, 1, 0, 0);

	glTranslatef(-20.5, 0.0, -0.625);
	//Oficinas por estacionamiento
	prisma(21, 16.8, 6.25, v_gen.GLindex, 0, 0, 0, techo.GLindex, 0, 4, 2, 5, 2, 0, 0, 0, 0, 1, 1, 0, 0);

	glPushMatrix();
	glTranslatef(0.0, -1.4, -6.25);
	//Oficinas pequeñas
	prisma(21, 14, 6.25, 0, 0, 0, 0, techo.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0);
	glPopMatrix();

	glTranslatef(-15.5, 0.0, -3.125);
	//Oficinas por rampa
	prisma(10, 16.8, 12.5, m_Amarillo.GLindex, 0, m_Amarillo.GLindex, v_gen.GLindex, techo.GLindex, 0, 1, 1, 0, 0, 1, 1, 3, 2, 1, 1, 0, 0);
	glPopMatrix();

	glPushMatrix();
	//Techo planta alta
	glTranslatef(-2.5, 12.6, -9.5);
	prisma(55, 0.8, 4, 0, 0, 0, 0, techo.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0);

	//Techo por rampa planta alta
	glTranslatef(-25.5, 0.0, -12.0);
	prisma(4, 0.8, 20, 0, 0, 0, 0, techo.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0);

	//Techo faltante interno
	glTranslatef(7.0, 0.0, 6.25);
	prisma(10, 0.8, 7.5, 0, 0, 0, 0, techo.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0);

	//Techo faltante externo
	glTranslatef(-12.8, 0.0, -4.25);
	prisma(7.5, 0.8, 24, 0, 0, 0, 0, techo.GLindex, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0);
	glPopMatrix();

	//Rampa
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, piso_l.GLindex);
	glBegin(GL_QUADS);
	glNormal3f(0.0, cos(23.089*3.141592 / 180), sin(23.089*3.141592 / 180));
	glTexCoord2f(1.0, 0.0); glVertex3f(-30.0, -4.0, -9.5);
	glTexCoord2f(1.0, 8.0); glVertex3f(-30.0, 4.1, -28.5);
	glTexCoord2f(0.0, 8.0); glVertex3f(-35.0, 4.1, -28.5);
	glTexCoord2f(0.0, 0.0); glVertex3f(-35.0, -4.0, -9.5);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, m_Amarillo.GLindex);
	glBegin(GL_TRIANGLES);
	glNormal3f(-1.0, 0.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(-35.0, -4.0, -9.5);
	glTexCoord2f(1.0, 1.0); glVertex3f(-35.0, 4.1, -28);
	glTexCoord2f(1.0, 0.0); glVertex3f(-35.0, -4.0, -28);
	glEnd();

	glTranslatef(-32.5, 0.0, -29.75);
	//Descanso
	prisma(5, 8, 3.5, 0, 0, m_Amarillo.GLindex, 0, piso_l.GLindex, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 2, 0, 0);
	glPopMatrix();

	glPushMatrix();
	//Columnas planta baja
	glTranslatef(-32.5, 0.0, 10.0);
	glColor3f(1.0, 0.0, 0.2);
	for (int i = 0; i<9; i++)
	{
		glPushMatrix();
		glTranslatef(i*60.5 / 9, 0.0, 0.0);
		cilindro(8, 0.2, 10);
		glTranslatef(0.0, 8.2, -18.2);
		if (i == 0)
		{
			glPushMatrix();
			glTranslatef(2.5, 0.0, 0.0);
			cilindro(8, 0.2, 10);
			glPopMatrix();

			glTranslatef(-3.3, -4.1, -4.0);
			for (int j = 0; j<4; j++)
			{
				glPushMatrix();
				glTranslatef(0.0, 0.0, -j*20.0 / 4);
				cilindro(17, 0.2, 10);
				glPopMatrix();
			}

		}
		else cilindro(8, 0.2, 10);
		glPopMatrix();
	}
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();

	glPushMatrix();
	//Escalera
	glTranslatef(20.0, -4.0, 5.0);
	escaleras(10, 16, 5, 11, 1, techo.GLindex);
	glPopMatrix();

	//glPushMatrix();
	//	glTranslatef(-100.0,0.0,40.0);
	//	glRotatef(-90,0.0,1.0,0.0);
	//	glScalef(5.0,3.0,5.0);
	//	puerta_PrincipalA();
	//glPopMatrix();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();


	glPushMatrix();
	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);

	glPushMatrix();

	glTranslatef(objCamera.mPos.x, objCamera.mView.y, objCamera.mPos.z);
	//glRotatef(lluviaY,0.0,1.0,0.0);
	glScalef(1.0, 15.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, lluvia.GLindex);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 0.0 + caida); glVertex3f(-1.0, -1.0, -1.0);
	glTexCoord2f(10.0, 0.0 + caida); glVertex3f(1.0, -1.0, -1.0);
	glTexCoord2f(10.0, 10.0 + caida); glVertex3f(1.0, 1.0, -1.0);
	glTexCoord2f(0.0, 10.0 + caida); glVertex3f(-1.0, 1.0, -1.0);

	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2f(0.0, 0.0 + caida); glVertex3f(-1.0, -1.0, 1.0);
	glTexCoord2f(10.0, 0.0 + caida); glVertex3f(1.0, -1.0, 1.0);
	glTexCoord2f(10.0, 10.0 + caida); glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 10.0 + caida); glVertex3f(-1.0, 1.0, 1.0);

	glNormal3f(1.0, 0.0, 0.0);
	glTexCoord2f(0.0 + caida, 0.0); glVertex3f(1.0, -1.0, -1.0);
	glTexCoord2f(10.0 + caida, 0.0); glVertex3f(1.0, 1.0, -1.0);
	glTexCoord2f(10.0 + caida, 10.0); glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0 + caida, 10.0); glVertex3f(1.0, -1.0, 1.0);

	glNormal3f(1.0, 0.0, 0.0);
	glTexCoord2f(0.0 + caida, 0.0); glVertex3f(-1.0, -1.0, -1.0);
	glTexCoord2f(10.0 + caida, 0.0); glVertex3f(-1.0, 1.0, -1.0);
	glTexCoord2f(10.0 + caida, 10.0); glVertex3f(-1.0, 1.0, 1.0);
	glTexCoord2f(0.0 + caida, 10.0); glVertex3f(-1.0, -1.0, 1.0);
	glEnd();

	glDisable(GL_ALPHA_TEST);
	caida += 0.01;
	glPopMatrix();

	glPushMatrix(); //Creamos cielo
	glDisable(GL_LIGHTING);
	glTranslatef(0, -60, 0);
	glRotatef(rotate, 0.0, 1.0, 0.0);
	fig1.esfera2(300.0, 36.0, 36.0, cielo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	rotate += 0.02;


	glPushMatrix();

	glPushMatrix(); //Rectoría
	glTranslatef(-230.0, 8.0, 44.68);
	glScalef(1.1, 1.1, 1.5);
	glDisable(GL_LIGHTING);
	Rectoria();
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //DGOSE
	glRotatef(4, 0, 1, 0);
	glRotatef(180, 0.0, 1.0, 0.0);
	glTranslatef(70.0, 3.01, -110);
	glScalef(0.7, 0.5, 0.6);
	DGOSE();
	glPopMatrix();

	//glColor3f(1.0, 1.0, 1.0);
	//muroArquiIslas
	//glPopMatrix();
	glPushMatrix();
		glTranslatef(-80, 0, 110);
		glDisable(GL_LIGHTING);
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
		muroArquiIslas(-65, 4.8, 10.66, m_arquiIslas.GLindex);
		pisoArqui(-95, 4.8, 10.66, piso_arq1.GLindex);
		pisoArqui1(-0, 4.8, 50, piso_arq1.GLindex);
		glRotatef(90,0,1,0);
		muroArquiIslas(-90, 4.8, 0, piso_arq1.GLindex);
		//glRotatef(-90, 0, 1, 0);
		//muroArquiIslas(0, 4.8, -90, piso_arq1.GLindex);
		glDisable(GL_TEXTURE_GEN_T);
		glDisable(GL_TEXTURE_GEN_S);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	//rampaArquiIslas
	glPushMatrix();
		glTranslatef(-80, 0, 110);
		glRotatef(180, 0, 1, 0);
		glDisable(GL_LIGHTING);
		glEnable(GL_BLEND);
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
		rampaArquiIslas(65, 4.8, -10.88, r_arquiIslas.GLindex);
		glDisable(GL_TEXTURE_GEN_T);
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_BLEND);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	//rampaArquiMUCA
	/*glPushMatrix();
	glTranslatef(-80, 0, 110);
	glRotatef(90, 0, 1, 0);
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	rampaArquiMUCA(-30, 5.8, -90, r_arquiIslas.GLindex);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glPopMatrix();*/

	//piso arqui


	//pisoArqui



	//Arqui y demás
	glPushMatrix();
		glTranslatef(-60.0, 9.0, 167.0);
		glPushMatrix();
			glScalef(1.2, 1.2, 1.2);
			talleresArqui();
		glPopMatrix();

		glTranslatef(-25.0, 0.0, 0.0);
		glPushMatrix();
			glScalef(1.6, 1.2, 1.2);
			tallerArquiDist1();
		glPopMatrix();

		glTranslatef(-25.0, 0.0, 8.0);
		glPushMatrix();
			glScalef(1.2, 1.2, 1.2);
			talleresArqui();
		glPopMatrix();

		glTranslatef(7, 0.0, -25);
		glPushMatrix();
			glScalef(1.2, 1.2, 1.2);
			talleresArqui();
		glPopMatrix();

		glTranslatef(-35, 0.0, -15);
		glPushMatrix();
			glScalef(1.4, 1.2, 1.3);
			tallerArqui();
		glPopMatrix();

		glTranslatef(10.0, 5.5, 30.0);
			glScalef(1.3, 1.2, 1.1);
		arq();
	glPopMatrix();

	glPushMatrix(); //Diseño Industrial
	glRotatef(-88, 0.0, 1.0, 0.0);
	glTranslatef(65, 3, -90);

	disenoIndustrial();
	glPopMatrix();



	glPushMatrix(); //Humanidades 1
	glDisable(GL_LIGHTING);
	glTranslatef(-66.7, 8.0, -51.0);
	glScalef(0.45, 0.45, 0.45);
	torreHumanidades.GLrender(NULL, _SHADED, 1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Humanidades 2
	glDisable(GL_LIGHTING);
	glTranslatef(130.0, 0.0, 35.0);
	glScalef(0.6, 0.6, 0.6);
	torreHumanidades2.GLrender(NULL, _SHADED, 1);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix(); //Biblioteca
	glDisable(GL_LIGHTING);
	glTranslatef(-209.0, 5.0, 6.5);
	glScalef(0.6, 0.6, 0.4);
	biblioteca.GLrender(NULL, _SHADED, 1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Inge
	glDisable(GL_LIGHTING);
	glTranslatef(-30.0, 0.0, 160);
	glScalef(0.04, 0.04, 0.04);
	inge.GLrender(NULL, _SHADED, 1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //pasto islas
	glDisable(GL_LIGHTING);
	glTranslatef(-20.0, 0.5, 40.0);
	glRotatef(185, 0, 1, 0);
	glScalef(2100.0, 0.0, 1000.0);
	pasto.prisma2(texturaPasto.GLindex, texturaPasto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //camino islas abajo
	glDisable(GL_LIGHTING);
	glTranslatef(-15.0, 0.5, 92.0);
	glRotatef(185, 0, 1, 0);
	glScalef(210.0, 0.5, 5.0);
	camino.prisma2(t_caminoIslas.GLindex, t_piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //camino islas arriba
	glDisable(GL_LIGHTING);
	glTranslatef(-24.0, 0.5, -10.0);
	glRotatef(185, 0, 1, 0);
	glScalef(210.0, 0.5, 5.0);
	camino.prisma2(t_caminoIslas.GLindex, t_piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //camino islas derecha
	glDisable(GL_LIGHTING);
	glTranslatef(81.0, 0.5, 32.0);
	glRotatef(185, 0, 1, 0);
	glScalef(8.0, 0.5, 100.0);
	camino.prisma2(t_caminoIslas.GLindex, t_piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //camino islas izquierda
	glDisable(GL_LIGHTING);
	glTranslatef(-120.0, 0.5, 50.0);
	glRotatef(185, 0, 1, 0);
	glScalef(8.0, 0.5, 100.0);
	camino.prisma2(t_caminoIslas.GLindex, t_piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //barra de derecho
	glDisable(GL_LIGHTING);
	glTranslatef(-30.0, 0.5, -20.0);
	glRotatef(185, 0, 1, 0);
	glScalef(210.0, 5.0, 5.0);
	camino.prisma2(t_piedra.GLindex, t_piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Isla Inge
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTranslatef(25.0, -3.0, 60.0);
	glScalef(5.0, 2.0, 3.0);
	isla.esfera(5.0, 15.0, 15.0, texturaPasto.GLindex);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Isla Derecho
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTranslatef(25.0, -3.0, 9.0);
	glScalef(5.0, 2.0, 3.0);
	isla.esfera(5.0, 15.0, 15.0, texturaPasto.GLindex);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Isla Filos
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTranslatef(-60.0, -3.0, 20.0);
	glScalef(5.0, 2.0, 3.0);
	isla.esfera(5.0, 15.0, 15.0, texturaPasto.GLindex);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //facultad de derecho
	glDisable(GL_LIGHTING);
	glRotatef(-4, 0, 1, 0);
	glTranslatef(-32.0, 0.0, -9.0);
	glScalef(0.7, 0.7, 0.7);
	facultadD.GLrender(NULL, _SHADED, 1);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//glPushMatrix();//pastoRectoria
	//glDisable(GL_LIGHTING);
	//glEnable(GL_BLEND);
	//glEnable(GL_TEXTURE_GEN_S);
	//glEnable(GL_TEXTURE_GEN_T);
	//glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	//glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	////glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//GL_ONE_MINUS_SRC_ALPHA,GL_ONE_MINUS_DST_COLOR GL_ONE_MINUS_SRC_COLOR
	//for (int i = 17616; i > 6943; i = i - 422){
	//	GLfloat aux = GLfloat(GLfloat(i) / 100) - 52;
	//	//printf("\n%.02f", aux);
	//	for (int j = 23129; j > 12000; j = j - 422){
	//		GLfloat aux1 = GLfloat(-GLfloat(j) / 100) - 52;
	//		//printf("\n%.02f", aux1);
	//		generaCuadro(aux1, 7.1, aux, t_placasRectoria.GLindex);
	//	}
	//}
	//glEnable(GL_LIGHTING);
	//glDisable(GL_BLEND);
	//glDisable(GL_ALPHA_TEST);
	//glDisable(GL_TEXTURE_GEN_S);
	//glDisable(GL_TEXTURE_GEN_T);
	//glPopMatrix();



	glPushMatrix();//escaleras
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	int j = 710;
	int cont = 0;
	for (int i = 16914; i > 14014; i = i - 30){
		/*for (int i = 710; i > 0; i = i - 23){
		printf("ebtri2");
		GLfloat aux1 = GLfloat(GLfloat(i) / 100);
		escalerasIslasRectoria(aux, aux1, 141.1, t_escalerasIslas.GLindex);
		}*/
		GLfloat aux1 = GLfloat(GLfloat(j) / 100);
		GLfloat aux = GLfloat(-GLfloat(i) / 100);
		escalerasIslasRectoria(aux, aux1, 19.18, t_escalerasIslas.GLindex, cont);
		escalerasIslasRectoria1(aux, aux1, 19.18, t_escalerasIslas.GLindex, cont);
		if (cont == 10 || cont == 20){
			i = i - 190;
		}
		j = j - 23;
		cont++;

	}
	glDisable(GL_ALPHA_TEST);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_S);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glTranslatef(0.0,4.0,0.0);
	cometa();
	glTranslatef(0.0, -4.0, 0.0);
	glPushMatrix();
			glTranslatef(25.0, 8, 60.0);
			glScalef(.2, 1, .2);
			aspersor();
			glScalef(10, 1, 10);
			glRotatef(90,1,0,0);
			charco();
			glRotatef(-90, 1, 0, 0);
			arbol_alpha();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(25.0, 8.0, 9.0);
	glScalef(.2, 1, .2);
	aspersor();
	glScalef(10, 1, 10);
	glRotatef(90, 1, 0, 0);
	charco();
	glRotatef(-90, 1, 0, 0);
	arbol_alpha();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60.0, 8.0, 20.0);
	glScalef(.2, 1, .2);
	aspersor();
	glScalef(10, 1, 10);
	glRotatef(90, 1, 0, 0);
	charco();
	glRotatef(-90, 1, 0, 0);
	arbol_alpha();
	glPopMatrix();


	glTranslatef(0.0, 40.0, 4.0);
	pelota();

	glColor3f(1.0, 1.0, 1.0);		//Para que los demas elementos regresen a su color de su textura y no permanescan rojos
	glPopMatrix();

	
	glPopMatrix();

	


	glPopMatrix();

	

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 0.0, 0.0);
	pintaTexto(-0.25, 0.23, -0.25, (void *)font, "Proyecto final");
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();

}

void animacion()
{
	if (anim){
		if (edo == 0)
		{
			if (def>-0.4)
			{
				def -= 0.02;
				elev += exp(-5.0 / (3 + def));
				desp += def;
			}
			else edo = 1;
		}
		else if (edo == 1)
		{
			if (def<0.1)
			{
				def += 0.02;
				elev -= 0.08*exp(-1.0 / (7 + def))*sin(-5.0 / (3 + def)*3.141592);
				desp -= 0.3*(2 + def) / 2.5;
				rot += 0.35;
			}
			else edo = 2;
		}
		else if (edo == 2)
		{
			if (def>-0.4)
			{
				def -= 0.02;
				elev += 0.2*cos(5.0 / (3 + def)*3.141592);
				desp += 0.02*cos(5.0 / (3 + def)*3.141592);
				rot -= 0.2;
			}
			else edo = 1;
		}
		if (edo_asp == 0)
		{
			asp += 6;
			if (asp >135) edo_asp = 1;
		}
		else if (edo_asp == 1)
		{
			asp -= 6;
			if (asp<0) edo_asp = 0;
		}

		if (edo_agua == 0)
		{
			ang += 0.13;
			ond = 0.2*cos(ang);
		}
		if (edo_pel == 0)
		{
			t += 0.03;
			despX += 0.03;
			despY = 6-(exp(t) + exp(-t)) / 2.0;
			if (t>3.0)
			{
				edo_pel = 1;
				dY = despY;
				t = 0.0;
			}
		}
		else if (edo_pel == 1)
		{
			t += 0.03;
			despY = dY - (exp(t - 1) + exp(-t + 1)) / 2.0;
			despZ -= 0.03;

			if (t>2.0)
			{
				edo_pel = 2;
				dY = despY;
				t = 0.0;
			}
		}
		else if (edo_pel == 2)
		{
			t += 0.03;
			despY = dY - (exp(t - 0.5) + exp(-t + 0.5)) / 2.0;
			despX -= 0.03;
			if (t>1.0)
			{
				edo_pel = 3;
				dY = despY;
				t = 0.0;
			}
		}
		else if (edo_pel == 3)
		{
			t += 0.03;
			despY = dY - (exp(t - 0.25) + exp(-t + 0.25)) / 2.0;
			despZ += 0.03;
			if (t>0.5)
			{
				edo_pel = 0;
				dY = despY;
				t = -3.0;
			}

		}

	}

	glutPostRedisplay();
}


void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 600.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);
		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.4);
		break;

	case 'r':		//Cambia posicion de la camara desee arriba
	case 'R':
		objCamera.Position_Camera(-31.099323, 160.699631, 9.364282, -33.938477, 160.699631, -24.574570, 0.000000, 1.000000, 0.000000);
		g_lookupdown = 89.0;
		break;

	case 'u': //Cambia la posicion hacia la biblioteca de frente
	case 'U':
		objCamera.Position_Camera(-195.990341, 18.600000, 34.589989, -195.990341, 18.600000, 31.589987, 0.0, 1.0, 0.0);
		g_lookupdown = 0.0;
		break;

	case 'i': //Cambia la posicion hacia la biblioteca de frente
	case 'I':
		objCamera.Position_Camera(90.605507, 10.899999, 24.190191, 93.604088, 10.899999, 24.097816, 0.00000, 1.0, 0.0);
		g_lookupdown = 0.0;
		break;

	case 'f':		// Posicion inicial
	case 'F':
		objCamera.Position_Camera(0, 2.5f, 3, 0, 2.5f, 0, 0, 1, 0);
		g_lookupdown = 0.0;
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	case 'p':
	case 'P':
		//pos_camY -= 0.5f;
		//pos_cam.y += 0.5f;
		//eye_cam.y += 0.5f;
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case 'm':
	case 'M':
		anim ^= true;
		desp = 0.0f;
		elev = 0.0f;
		def = 0.0f;
		rot = 0.0f;
		edo = 0;
		edo_asp = 0;
		edo_pel = 0.0;
		t = -3.0;
		asp = 0;

		break;

	case 'l':
	case 'L':
		//pos_camY += 0.5f;
		//pos_cam.y -= 0.5f;
		//eye_cam.y -= 0.5f;
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;
	default:        // Cualquier otra
		break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		//pos_camY -= 0.5f;
		//pos_cam.y += 0.5f;
		//eye_cam.y += 0.5f;
		objCamera.UpDown_Camera(CAMERASPEED + 0.5);
		break;

	case GLUT_KEY_PAGE_DOWN:
		//pos_camY += 0.5f;
		//pos_cam.y -= 0.5f;
		//eye_cam.y -= 0.5f;
		objCamera.UpDown_Camera(-CAMERASPEED - 0.5);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		lluviaY += 4.011;
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
		lluviaY -= 4.011;
		break;

	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Proyecto final"); // Nombre de la Ventana
	//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}

