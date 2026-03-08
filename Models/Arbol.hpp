#pragma once
#include "Entidad.hpp"

class Arbol : public Entidad
{
public:
	Arbol(int x, int y, int ancho, int alto) : Entidad(x, y, ancho, alto) {}
	~Arbol() {}
};
