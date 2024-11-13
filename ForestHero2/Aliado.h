#pragma once
#include "Agente.h"

class Aliado : public Agente
{
private:

public:
	Aliado(int px, int py, int pvelocidad, int pancho, int palto) : Agente(px, py, pvelocidad, pancho, palto) 
	{ 
		velocidad = 20; 
	}

	~Aliado() {}
};
