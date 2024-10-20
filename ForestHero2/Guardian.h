#pragma once
#include "Personaje.h"

class Guardian : public Personaje 
{
private:
	int vidas;
	int contadorAgua;
	int contadorSemillas;
	int puntos;
public:
	Guardian();
	~Guardian();

	int getContadorSemillas();
	int getContadorAgua();
	int getPuntos();
	int getVidas();

	void setContadorSemillas(int);
	void setContadorAgua(int);
	void setPuntos(int);
	void setVidas(int);
};

Guardian::Guardian() :Personaje(velocidad)
{
	vidas = 5;
	contadorAgua = 15;
	contadorSemillas = 20;
	puntos = 0;
	velocidad = 10;
}

Guardian::~Guardian() {}

int Guardian::getContadorSemillas() { return this->contadorSemillas; }
int Guardian::getContadorAgua() { return this->contadorAgua; }
int Guardian::getPuntos() { return this->puntos; }
int Guardian::getVidas() { return this->vidas; }

void Guardian::setContadorSemillas(int i) { this->contadorSemillas = i; }
void Guardian::setContadorAgua(int i) { this->contadorAgua = i; }
void Guardian::setPuntos(int i) { this->puntos = i; }
void Guardian::setVidas(int i) { this->vidas = i; }