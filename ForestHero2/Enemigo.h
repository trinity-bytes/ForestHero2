#pragma once
#include "Agente.h"

class Enemigo : public Agente
{
private:
	int vidas;
public:
	Enemigo(int x, int y, int ancho, int alto) : Agente(x, y, velocidad, ancho, alto)
	{ 
		vidas = 2;
		velocidad = 6; 
	}
	~Enemigo() {}

	int getVidas() { return this->vidas; }

	void setVidas(int vidas) { this->vidas = vidas; }
};