

#ifndef CHRIS_SOLARSYSTEM_H
#define CHRIS_SOLARSYSTEM_H

#ifdef _WIN32
#include <Windows.h>
#endif

#include <GL/glut.h>

#include <vector>

#include "planeta.h"

class SistemaSolar
{
private:
	std::vector<Planeta> planetas;

public:
	SistemaSolar();

	// Calcula las posiciones y la lógica de todos los planetas
	void calcularPosiciones(float tiempo);

	// Agrega un planeta con los datos proporcionados
	void addPlaneta(float distanciaAlSol, float tiempoOrbita, float tiempoRotacion, float radio, GLuint identificadorTextura);

	// Agrega una luna al planeta especificado
	void addLuna(int indexPlaneta, float c, float tiempoOrbita, float tiempoRotacion, float radio, GLuint identificadorTextura);

	// Renderiza los planetas con OpenGL
	void renderizar();

	// Renderiza el dibujo de las órbitas
	void renderizarOrbitas();

	// Obtiene la posición en unidades de espacio 3D del planeta dado (especificado por su índice en la lista) y la coloca en el vector 3D "vec"
	void getPosicionPlaneta(int index, float* vec);

	// Obtiene el radio del planeta en el índice especificado en la lista de planetas
	float getRadioDelPlaneta(int index);

	Planeta getPlaneta(int index);
};

#endif
