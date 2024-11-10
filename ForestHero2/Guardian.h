#pragma once
#include "Agente.h"

class Guardian : public Agente 
{
private:
	int vidas;
	int cantAgua;
	int cantSemillas;
	int puntos;
public:
	Guardian() : Agente(velocidad)
	{
		vidas = 5;
		cantAgua = 15;
		cantSemillas = 20;
		puntos = 0;
		velocidad = 20;
	}
	~Guardian() {}
	
	int getCantAgua() { return this->cantSemillas; }
	int getCantSemillas() { return this->cantAgua; }
	int getPuntos() { return this->puntos; }
	int getVidas() { return this->vidas; }
	
	void setCantAgua(int i) { this->cantSemillas = i; }
	void setCantSemillas(int i) { this->cantAgua = i; }
	void setPuntos(int i) { this->puntos = i; }
	void setVidas(int i) { this->vidas += i; }
};
