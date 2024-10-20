#pragma once
#include "FuncionesCustom.h"
#include "PersonajeSecundario.h"

class Enemigo : public PersonajeSecundario
{
public:
	Enemigo(int, int);
	~Enemigo();

	void Mover() override;
	void Dibujar();
};

Enemigo::Enemigo(int x, int y) : PersonajeSecundario(x, y) {}

Enemigo::~Enemigo() {}

void Enemigo::Mover()
{
	int direccion = GenerarNumeroAleatorio(1, 60);

	switch (direccion)
	{
	case 1: // Arriba
		if (y - 1 > 2) y -= dy;
		break;
	case 20: // Abajo
		if (y + 1 < 17) y = y + dx;
		break;
	case 40: // Izquierda
		if (x - 1 > 1) x = x - dx;
		break;
	case 60: // Derecha
		if (x + 1 < 21) x = x + dx;
		break;
	}
}

void Enemigo::Dibujar() {
	// implementar
}