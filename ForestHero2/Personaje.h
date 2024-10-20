#pragma once
#include "Entidad.h"

enum Direccion { Arriba, Abajo, Izquierda, Derecha, Ninguno };

class Personaje : public Entidad
{
protected:
	int dx, dy, velocidad;
public:
	Personaje(int);
	~Personaje();

	// getters
	int getDX();
	int getDY();

	// setter
	void setDireccion(Direccion);

	void Mover(Graphics^, Direccion);
};

Personaje::Personaje(int velocidad) : Entidad()
{
	dx = dy = 0;
	this->velocidad = velocidad;
}

Personaje::~Personaje() {}

int Personaje::getDX() { return this->dx; }
int Personaje::getDY() { return this->dy; }

void Personaje::setDireccion(Direccion teclaPulsada)
{
	switch (teclaPulsada)
	{
	case Arriba:
		this->dx = 0;
		this->dy = -velocidad;
		break;
	case Abajo:
		this->dx = 0;
		this->dy = velocidad;
		break;
	case Izquierda:
		this->dx = -velocidad;
		this->dy = 0;
		break;
	case Derecha:
		this->dx = velocidad;
		this->dy = 0;
		break;
	case Ninguno:
		this->dx = 0;
		this->dy = 0;
		break;
	}
}

void Personaje::Mover(Graphics^ canvas, Direccion teclapulsada)
{
	if (teclapulsada == Direccion::Abajo)     indiceAlto = 0;
	if (teclapulsada == Direccion::Arriba)    indiceAlto = 3;
	if (teclapulsada == Direccion::Derecha)   indiceAlto = 2;
	if (teclapulsada == Direccion::Izquierda) indiceAlto = 1;
	if (teclapulsada == Direccion::Ninguno)   indiceAlto = 0;

	indiceAncho++;
	if (indiceAncho > 3) indiceAncho = 0;

	x = x + dx;
	y = y + dy;

	Dibujar(canvas);
}