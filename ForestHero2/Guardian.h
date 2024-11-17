#pragma once
#include "Agente.h"
#include <string>
using std::string;
class Guardian : public Agente
{
private:
	std::string nombre;
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
		velocidad = 12;
		this->nombre = " ";
	}
	~Guardian() {}
	int getCantVidas() { return this->cantVidas; }
	int getCantAgua() { return this->cantSemillas; }
	int getCantSemillas() { return this->cantAgua; }
	int getPuntos() { return this->puntos; }
	string getNombre(){ return this->nombre; }
	void setNombre(string _nombre) {nombre = _nombre; }
	void setCantAgua(int i) { this->cantSemillas = i; }
	void setCantSemillas(int i) { this->cantAgua = i; }
	void setPuntos(int i) { this->puntos += i; }
	void setCantVidas(int i) { this->cantVidas += i; }

	void ReiniciarEstado()
	{
		this->x = 200;
		this->y = 200;
		this->cantVidas = 5;
		this->cantAgua = 15;
		this->cantSemillas = 20;
		this->puntos = 0;
		velocidad = 12;
		this->nombre = " ";
	}
};
