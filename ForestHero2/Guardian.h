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
	Guardian(int x, int y, int ancho, int alto) : Agente(x, y, velocidad, ancho, alto)
	{
		this->vidas = 5;
		this->cantAgua = 15;
		this->cantSemillas = 20;
		this->puntos = 0;
		velocidad = 5;
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
	void dispararSemillas(Semilla* semillas){
		//implementar aqui
	}
};
