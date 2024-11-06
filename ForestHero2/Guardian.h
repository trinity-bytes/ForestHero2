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
	Guardian();
	~Guardian();
	
	int getCantAgua();
	int getCantSemillas();
	int getPuntos();
	int getVidas();
	
	void setCantAgua(int);
	void setCantSemillas(int);
	void setPuntos(int);
	void setVidas(int);
};

Guardian::Guardian() :Agente(velocidad)
{
	vidas = 5;
	cantAgua = 15;
	cantSemillas = 20;
	puntos = 0;
	velocidad = 8;
}

Guardian::~Guardian() {}

int Guardian::getCantAgua() { return this->cantSemillas; }
int Guardian::getCantSemillas() { return this->cantAgua; }
int Guardian::getPuntos() { return this->puntos; }
int Guardian::getVidas() { return this->vidas; }

void Guardian::setCantAgua(int i) { this->cantSemillas = i; }
void Guardian::setCantSemillas(int i) { this->cantAgua = i; }
void Guardian::setPuntos(int i) { this->puntos = i; }
void Guardian::setVidas(int i) { this->vidas = i; }