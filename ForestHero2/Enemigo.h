#pragma once
#include "Agente.h"

class Enemigo : public Agente
{
private:
	int vidas;
	Direccion direccionActual;
public:
	Enemigo(int x, int y, int ancho, int alto) : Agente(x, y, velocidad, ancho, alto)
	{ 
		vidas = 2;
		velocidad = 5; 
		direccionActual = Ninguna;
	}
	~Enemigo() {}

	Direccion getDireccionAleatoria()
	{
		int r = GenerarNumeroAleatorio(0, 100);

		switch (r)
		{
		case 1:
			return Arriba; break;
		case 15:
			return Abajo; break;
		case 30:
			return Izquierda; break;
		case 45:
			return Derecha; break;
		case 95:
			return Ninguna; break;
		default:
			break;
		}
	}

	Direccion getDireccionActual()
	{
		return this->direccionActual;
	}

	void setDireccionActual(Direccion d)
	{
		this->direccionActual = d;
	}
};