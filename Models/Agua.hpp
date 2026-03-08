#pragma once
#include "Entidad.hpp"

class Agua : public Entidad
{
public:
	Agua(int x, int y, int ancho, int alto) : Entidad(x, y, ancho, alto) {}
	~Agua() {}
};
