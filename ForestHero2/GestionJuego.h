#pragma once
#include "GestionRecursos.h"

class GestionJuego
{
private:
	ArregloElementos* objElementos;
public:
	GestionJuego()
	{
		IniciarElementos();
	}
	~GestionJuego() {}

	void IniciarElementos() {}
	void MoverElementos() {}
	void RevisarColisiones() {}
	void DeterminarGanador() {}
};



