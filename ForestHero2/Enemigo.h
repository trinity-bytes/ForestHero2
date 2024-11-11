#pragma once
#include "Agente.h"

class Enemigo : public Agente
{
private:
	int vidas;
	Direccion direccionActual;
public:
	Enemigo(int x, int y, int ancho, int alto) : Agente(x, y, velocidad, ancho, alto)
	{ 
		vidas = 2;
		velocidad = 5; 
		direccionActual = Ninguna;
	}
	~Enemigo() {}

	Direccion getDireccionActual() { return this->direccionActual; }

	void setDireccionActual(Direccion d) { this->direccionActual = d; }
};