#pragma once
#include "Agente.h"

class Semilla : public Agente
{
public:
	Semilla(int x, int y, int ancho, int alto) : Agente(x, y, velocidad, ancho, alto)
	{
		velocidad = 20;
	}
	~Semilla() {}
};

