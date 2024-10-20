#pragma once
#include "Entidad.h"

class Basura : public Entidad
{
public:
	Basura(int, int);
	~Basura();

	// getters
	int getX();
	int getY();

	void Dibujar();
};

Basura::Basura(int x, int y) : Entidad(x, y) {}

Basura::~Basura() {}

int Basura::getX() { return x; }
int Basura::getY() { return y; }

void Basura::Dibujar() 
{
	// implementar
}