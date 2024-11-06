#pragma once
#include "Agente.h"

class Semilla : public Agente
{
public:
	Semilla();
	~Semilla();
};

Semilla::Semilla() : Agente(velocidad) 
{
	velocidad = 5;
}

Semilla::~Semilla() {}