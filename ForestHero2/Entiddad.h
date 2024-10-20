#pragma once
#include "FuncionesExtra.h"
#include "iostream"

using namespace std;

class Entidad
{
protected:
	int x, y;
public:
	Entidad(int, int);
	~Entidad();

	// Getters
	int getX() const;
	int getY() const;

	void Borrar() const;
};

Entidad::Entidad(int x, int y)
{
	this->x = x;
	this->y = y;
}

Entidad::~Entidad() {}

int Entidad::getX() const { return this->x; }
int Entidad::getY() const { return this->y; }

void Entidad::Borrar() const {
	gotoxy(x, y); cout << " ";
}