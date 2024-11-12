#pragma once
#include "Agente.h"

class Semilla : public Agente
{
private:
	Direccion direccionActual;
public:
	Semilla(int x, int y, int ancho, int alto) : Agente(x, y, velocidad, ancho, alto)
	{
		velocidad = 40;
		direccionActual = Ninguna;
	}

	Semilla(int x, int y, int ancho, int alto, Direccion direccionActual) : Agente(x, y, velocidad, ancho, alto)
	{
		velocidad = 40;
		this->direccionActual = direccionActual;
	}

	~Semilla() {}

	Direccion getDireccionActual() { return this->direccionActual; }

	void setDireccionActual(Direccion d) { this->direccionActual = d; }
};

