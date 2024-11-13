#pragma once
#include "Agente.h"

class Semilla : public Agente
{
private:

public:
	Semilla(int x, int y, int ancho, int alto) : Agente(x, y, velocidad, ancho, alto)
	{
		velocidad = 30;
	}

	Semilla(int x, int y, int ancho, int alto, Direccion direccionActual) : Agente(x, y, velocidad, ancho, alto)
	{
		velocidad = 40;
		this->direccionActual = direccionActual;
	}

	~Semilla() {}

};

