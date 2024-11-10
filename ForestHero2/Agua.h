#pragma once
#include "Entidad.h"

class Agua : public Entidad
{
public:
	Agua() : Entidad(x, y, ancho, alto) {}
	~Agua() {}
};