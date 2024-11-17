#pragma once
#include "Agente.h"

class Aliado : public Agente
{
private:
	bool visible = false;
public:
	Aliado(int px, int py, int pvelocidad, int pancho, int palto) : Agente(px, py, pvelocidad, pancho, palto) 
	{ 
		velocidad = 16; 
	}

	~Aliado() {}

	bool getVisible() { return visible; }

	void setVisible(bool v) { this->visible = v; }
};
