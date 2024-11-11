#pragma once
#include "Agente.h"

class Semilla : public Agente
{
public:
	Semilla() : Agente(x, y, velocidad, ancho, alto)
	{
		velocidad = 5;
	}
	~Semilla() {}
};

