#pragma once
#include "Agente.h"

class Aliado : Agente
{
private:

public:
	Aliado() : Agente(velocidad) { velocidad = 10; }
	~Aliado() {}
};
