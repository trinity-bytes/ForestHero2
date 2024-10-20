#pragma once
#include "Entidad.h"

class Agua : public Entidad
{
public:
	Agua(int, int);
	~Agua();

	void Dibujar();
};

Agua::Agua(int x, int y) : Entidad(x, y) {}

Agua::~Agua() {}

void Agua::Dibujar() 
{
	//! por implementar
}