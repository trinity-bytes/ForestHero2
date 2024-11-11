#pragma once
#include "Agente.h"

class Aliado : public Agente
{
private:

public:
	Aliado(int px, int py, int pvelocidad, int pancho, int palto) : Agente(px, py, pvelocidad, pancho, palto) { velocidad = 20; }
	~Aliado() {}
	//void mover(Graphics^ g)
	//{
	//	idX++;
	//	if (idX > 3) idX = 0;

	//	x += dx;
	//}
	void dibujar(Graphics^ g, Bitmap^ bmp)
	{
		System::Drawing::Rectangle seccionMostrada = System::Drawing::Rectangle(idX * ancho, idY * alto, ancho, alto);
		System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, ancho * 1.0, alto * 1.0);
		g->DrawImage(bmp, zoom, seccionMostrada, GraphicsUnit::Pixel);
	}
	System::Drawing::Rectangle getRectangle()
	{
		return System::Drawing::Rectangle(x, y, ancho * 0.03, alto * 0.03);
	}
};
