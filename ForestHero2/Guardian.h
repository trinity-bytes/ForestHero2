#pragma once
#include "Agente.h"

class Guardian : public Agente 
{
private:
	int cantVidas;
	int cantAgua;
	int cantSemillas;
	int puntos;
public:
	Guardian(int x, int y, int ancho, int alto) : Agente(x, y, velocidad, ancho, alto)
	{
		this->cantVidas = 5;
		this->cantAgua = 15;
		this->cantSemillas = 20;
		this->puntos = 0;
		velocidad = 8;
	}
	~Guardian() {}
	int getCantVidas() { return this->cantVidas; }
	int getCantAgua() { return this->cantSemillas; }
	int getCantSemillas() { return this->cantAgua; }
	int getPuntos() { return this->puntos; }
	
	void setCantAgua(int i) { this->cantSemillas = i; }
	void setCantSemillas(int i) { this->cantAgua = i; }
	void setPuntos(int i) { this->puntos += i; }
	void setCantVidas(int i) { this->cantVidas += i; }
};
