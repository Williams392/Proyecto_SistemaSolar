
#include "sistemasolar.h"

SistemaSolar::SistemaSolar()
{
	
}

// Calcula las posiciones y la lógica de todos los planetas
void SistemaSolar::calcularPosiciones(float tiempo)
{
	for (int i = 0; i < planetas.size(); i++)
	{
		planetas[i].calculatePosition(tiempo);
	}
}

// Agrega un planeta con los datos proporcionados
void SistemaSolar::addPlaneta(float distanciaAlSol, float tiempoOrbita, float tiempoRotacion, float radio, GLuint identificadorTextura)
{
	planetas.push_back(Planeta(distanciaAlSol, tiempoOrbita, tiempoRotacion, radio, identificadorTextura));
}

// Agrega una luna al planeta especificado
void SistemaSolar::addLuna(int indexPlaneta, float distanciaAlPlaneta, float tiempoOrbita, float tiempoRotacion, float radio, GLuint identificadorTextura)
{
	planetas[indexPlaneta].addMoon(distanciaAlPlaneta, tiempoOrbita, tiempoRotacion, radio, identificadorTextura);
}

// render the planets with opengl
void SistemaSolar::renderizar()
{
	for (int i = 0; i < planetas.size(); i++)
	{
		planetas[i].render();
	}
}


// Renderiza el dibujo de las órbitas
void SistemaSolar::renderizarOrbitas()
{
	for (int i = 0; i < planetas.size(); i++)
	{
		planetas[i].renderOrbit();
	}
}

// Obtiene la posición en unidades de espacio 3D del planeta dado (especificado por su índice en la lista) y la coloca en el vector 3D "vec"
void SistemaSolar::getPosicionPlaneta(int index, float* vec)
{
	planetas[index].getPosition(vec);
}


// Obtiene el radio del planeta en el índice especificado en la lista de planetas
float SistemaSolar::getRadioDelPlaneta(int index)
{
	return planetas[index].getRadius();
}

Planeta SistemaSolar::getPlaneta(int index) {
	return planetas[index];
}
