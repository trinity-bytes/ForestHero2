#pragma once
#include "GestionRecursos.h"
#include "Guardian.h"

class GestionJuego
{
private:
	ArregloElementos* objElementos;
	Guardian* objGuardian;
public:
	GestionJuego();
	~GestionJuego();

	void IniciarJuego();
	void RevisarColisiones();
	void DeterminarGanador();
};

GestionJuego::GestionJuego()
{
}

GestionJuego::~GestionJuego()
{
}