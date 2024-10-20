#pragma once
#include "Entidad.h"

class Basura : public Entidad
{
public:
	Basura();
	~Basura();
};

Basura::Basura() : Entidad() {}

Basura::~Basura() {}