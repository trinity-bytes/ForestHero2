#pragma once
#include "FuncionesCustom.h"
#include "Agente.h"

class Enemigo : public Agente
{
public:
	Enemigo() : Agente(x, y, velocidad, ancho, alto) { velocidad = 5; }
	~Enemigo() {}
};