#pragma once
#include "Entidad.h"

class PersonajeSecundario : public Entidad
{
protected:
	int dx;
	int dy;
public:
	PersonajeSecundario(int, int);
	~PersonajeSecundario();

	virtual void Mover() {}
};

PersonajeSecundario::PersonajeSecundario(int x, int y) : Entidad(x, y)
{
	this->dx = 1;
	this->dy = 1;
}

PersonajeSecundario::~PersonajeSecundario() {}