#pragma once
#include "Entidad.h"

class PowerUp : public Entidad
{
private:
	bool visible = false;
public:
	PowerUp(int x, int y, int ancho, int alto) : Entidad(x, y, ancho, alto) {}
	~PowerUp() {}

	bool getVisible() { return visible; }

	void setVisible(bool v) { this->visible = v; }
};
