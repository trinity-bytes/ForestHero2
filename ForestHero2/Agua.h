#pragma once
#include "Entidad.h"

class Agua : public Entidad
{
public:
	Agua(int x, int y, int ancho, int alto) : Entidad(x, y, ancho, alto) {}
	~Agua() {}
};