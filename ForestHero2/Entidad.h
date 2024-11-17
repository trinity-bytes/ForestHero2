#pragma once
using namespace System::Drawing;
class Entidad
{
protected:
	int x, y, ancho, alto, idX, idY;
public:
	Entidad(int px, int py, int pancho, int palto)
	{
		this->x = px;
		this->y = py;
		this->ancho = pancho;
		this->alto = palto;
		this->idX = 0;
		this->idY = 0;
	}
	~Entidad() {}

	// getters
	int getX() { return this->x; }
	int getY() { return this->y; }
	int getAncho() { return this->ancho; }
	int getAlto() { return this->alto; }

	// setters
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	virtual void Dibujar(Graphics^ g, Bitmap^ bmp)
	{
		System::Drawing::Rectangle sectionShow = System::Drawing::Rectangle(idX * ancho, idY * alto, ancho, alto);
		System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, ancho, alto);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}

	System::Drawing::Rectangle getRectangle()
	{
		return System::Drawing::Rectangle(x, y, ancho * 0.8, alto * 0.8);
	}
};

