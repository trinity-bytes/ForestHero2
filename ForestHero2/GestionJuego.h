#pragma once
#include "GestionRecursos.h"

class GestionJuego
{
private:
	ArregloElementos* objElementos;
public:
	GestionJuego();
	~GestionJuego();

	void IniciarElementos();
	void MoverElementos();
	void RevisarColisiones();
	void DeterminarGanador();
};

GestionJuego::GestionJuego()
{
	IniciarElementos();
}

GestionJuego::~GestionJuego() {}

void GestionJuego::IniciarElementos() 
{

}

void GestionJuego::MoverElementos() 
{

}

void GestionJuego::RevisarColisiones() 
{

}

void GestionJuego::DeterminarGanador() {

}