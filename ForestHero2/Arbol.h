#pragma once
#include "Entidad.h"

class Arbol : public Entidad
{
public:
	Arbol(int, int);
	~Arbol();

	void Dibujar();
};

Arbol::Arbol(int x, int y) : Entidad(x, y) {}

Arbol::~Arbol() {}

void Arbol::Dibujar() 
{
	// implementar
}