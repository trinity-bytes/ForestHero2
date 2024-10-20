#pragma once
#include "String.h"

using namespace System::Drawing;

class Entidad
{
protected:
	int x, y, ancho, alto, indiceAncho, indiceAlto;
	char* imagen;
public:
	Entidad();
	~Entidad();

	// getters
	int getX();
	int getY();
	int getAncho();
	int getAlto();

	// setters
	void setX(int);
	void setX(int);
	void setImagen(char*);

	void Borrar();
	void Dibujar(Graphics^);
};

Entidad::Entidad()
{
	x = y = indiceAncho = indiceAlto = 0;
	imagen = new char[16];
}

Entidad::~Entidad() {}

int Entidad::getX() { return this->x; }
int Entidad::getY() { return this->y; }
int Entidad::getAncho() { return this->ancho; }
int Entidad::getAlto() { return this->alto; }

void Entidad::setX(int x) { this->x = x; }
void Entidad::setX(int y) { this->y = y; }

void Entidad::setImagen(char* dirImagen) 
{
	//lo que viene en el param valor lo copiamos a imagen
	//copia valor a imagen
	strcpy(imagen, dirImagen);

	//cargar imagen
	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(imagen));
	//bitmap tiene la imagen cargada

	ancho = bitmap->Width / 4;
	alto = bitmap->Height / 4;

	delete bitmap;
}

void Entidad::Borrar() 
{
	//todo por implementar
}

void Entidad::Dibujar(Graphics^ canvas)
{
	//vuelve a cargar el sprite completo
	Bitmap^ bitmap = gcnew Bitmap(gcnew System::String(imagen));

	//se obtiene un recuadro o porcion del sprite
	Rectangle cuadro = Rectangle(indiceAncho * ancho, indiceAlto * alto, ancho, alto);
	
	//para hacer zoom
	Rectangle zoom = Rectangle(x, y, ancho * 1, alto * 1);

	//dibujar cuadro en el canvas del formulario
	canvas->DrawImage(bitmap, zoom, cuadro, GraphicsUnit::Pixel);
}