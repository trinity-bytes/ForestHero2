#pragma once
#include "Agente.h"

class Semilla : public Agente
{
public:
	Semilla() : Agente(velocidad)
	{
		velocidad = 5;
	}
	~Semilla() {}
};

