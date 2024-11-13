#pragma once
#include "Entidad.h"

class Basura : public Entidad
{
public:
	Basura(int x, int y, int ancho, int alto) : Entidad(x, y, ancho, alto) {}
	~Basura() {}
};