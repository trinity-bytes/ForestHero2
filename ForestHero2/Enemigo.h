#pragma once
#include "FuncionesCustom.h"
#include "Personaje.h"

class Enemigo : public Personaje
{
public:
	Enemigo();
	~Enemigo();
};

Enemigo::Enemigo() : Personaje(velocidad) 
{
	velocidad = 5;
}

Enemigo::~Enemigo() {}