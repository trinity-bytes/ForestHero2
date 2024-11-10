#pragma once
#include "Entidad.h"

class Arbol : public Entidad
{
public:
	Arbol() : Entidad(x, y, ancho, alto) {}
	~Arbol() {}
};
