#pragma once
#include "FuncionesCustom.h"
#include "Agente.h"

class Enemigo : public Agente
{
public:
	Enemigo();
	~Enemigo();
};

Enemigo::Enemigo() : Agente(velocidad) 
{
	velocidad = 5;
}

Enemigo::~Enemigo() {}