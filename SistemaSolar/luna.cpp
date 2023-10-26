
#include "luna.h"
#include <cmath>

#include <Windows.h>
#include <GL/glut.h>

#include "globals.h"

Luna::Luna(float distanciaDesdePlaneta, float tiempoOrbita, float tiempoRotacion, float radio, GLuint identificadorTextura)
{
	this->distanciaDesdePlaneta = distanciaDesdePlaneta;
	this->tiempoOrbita = tiempoOrbita;
	this->tiempoRotacion = tiempoRotacion;
	this->radio = radio;
	this->identificadorTextura = identificadorTextura;
}

// Calcula su posición en el espacio 3D en relación al planeta en órbita usando el valor de tiempo dado
void Luna::calculatePosition(float tiempo)
{
	// find the angle of orientation of the orbit around the planet
	float angle = tiempo * 3.1419f / tiempoOrbita;
	
	// use trig to find the position in space relative to the planet
	posicion[0] = sin(angle) * distanciaDesdePlaneta;
	posicion[1] = cos(angle) * distanciaDesdePlaneta;
	posicion[2] = 0;

	// find the rotation of the moon around its axis
	rotacion = tiempo * 360 / tiempoRotacion;
}

// Render it to the screen
void Luna::render(void)
{
	glPushMatrix();

	// bind the moons texture
	glBindTexture(GL_TEXTURE_2D, identificadorTextura);

	// translate to the right positon and rotate for the moons spinning
	glTranslatef(posicion[0] * distanceScale, posicion[1] * distanceScale, posicion[2] * distanceScale);
	glRotatef(-rotacion, 0.0f, 0.0f, 1.0f);
	
	// render as a GLU sphere quadric object
	GLUquadricObj* quadric = gluNewQuadric();
	gluQuadricTexture(quadric, true);
	gluQuadricNormals(quadric, GLU_SMOOTH);

	gluSphere(quadric, radio * planetSizeScale, 30, 30);

	glPopMatrix();
}

// render this planets orbit circle
void Luna::renderOrbit(void)
{
	// draw a line strip
	glBegin(GL_LINE_STRIP);

	// loop round from 0 to 2*PI and draw around the radius of the orbit using trigonometry
	for (float angle = 0.0f; angle < 6.283185307f; angle += 0.1f)
	{
		glVertex3f(sin(angle) * distanciaDesdePlaneta * distanceScale, cos(angle) * distanciaDesdePlaneta * distanceScale, 0.0f);
	}
	glVertex3f(0.0f, distanciaDesdePlaneta * distanceScale, 0.0f);

	glEnd();
}

float* Luna::getPosition() {
	return posicion;
}
