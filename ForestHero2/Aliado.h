#pragma once
#include "Agente.h"

class Aliado : Agente
{
private:

public:
	Aliado();
	~Aliado();
};

Aliado::Aliado() : Agente(velocidad)
{
	velocidad = 10;
}

Aliado::~Aliado() {}