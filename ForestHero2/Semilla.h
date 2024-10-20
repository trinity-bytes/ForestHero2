#pragma once
#include "Entidad.h"

class Semilla : public Entidad
{
public:
	Semilla(int, int);
	~Semilla();

	void Dibujar();
};

Semilla::Semilla(int x, int y) :Entidad(x, y) {}

Semilla::~Semilla() {}

void Semilla::Dibujar() {
	// implementar
}