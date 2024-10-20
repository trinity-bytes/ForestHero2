#pragma once
#include "iostream"

class Entidad
{
protected:
	int x, y;
public:
	Entidad(int, int);
	~Entidad();

	// Getters
	int getX();
	int getY();

	virtual void Borrar();
	virtual void Dibujar();
};

Entidad::Entidad(int x, int y)
{
	this->x = x;
	this->y = y;
}

Entidad::~Entidad() {}

int Entidad::getX() { return this->x; }
int Entidad::getY() { return this->y; }

void Entidad::Borrar() 
{
	// por implementar
}

void Entidad::Dibujar()
{
	// por implementar
}