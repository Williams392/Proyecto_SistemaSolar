

#ifndef CHRIS_MOON_H
#define CHRIS_MOON_H

#ifdef _WIN32
#include <Windows.h>
#include <GL/glut.h>
#endif

class Luna
{
private:
	// distance from its planet
	float distanciaDesdePlaneta;

	// time it takes to complete 1 orbit
	float tiempoOrbita;

	// time it takes to spin 360 degrees
	float tiempoRotacion;

	// radius of the moon itself
	float radio;

	// the texture used for rendering
	GLuint identificadorTextura;

	// its position in 3d space relative to the planet
	float posicion[3];
	// its rotation around its axis
	float rotacion;

public:
	// Distance is in units of km (kilometers) and time is in units of earth days
	Luna(float distanceFromPlanet, float orbitTime, float rotationTime, float radius, GLuint textureHandle);

	// Calculate its position in 3d space relative to the planet in the orbit using the given time value
	void calculatePosition(float time);

	// Render it to the screen
	void render(void);

	// render this moons orbit circle
	void renderOrbit(void);

	float* getPosition();
};

#endif
