#pragma once
#include "Entidad.h"

class Basura : public Entidad
{
public:
	Basura() : Entidad(x, y, ancho, alto) {}
	~Basura() {}
};