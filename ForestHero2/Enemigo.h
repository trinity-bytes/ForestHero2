#pragma once
#include "FuncionesCustom.h"
#include "Agente.h"

class Enemigo : public Agente
{
public:
	Enemigo() : Agente(velocidad) { velocidad = 5; }
	~Enemigo() {}
};