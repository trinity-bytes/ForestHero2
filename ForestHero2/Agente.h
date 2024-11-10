#pragma once
#include "Entidad.h"

enum Direccion { Arriba, Abajo, Izquierda, Derecha, Ninguna };

class Agente : public Entidad
{
protected:
    int dx, dy, velocidad;
public:
    Agente(int);
    ~Agente();

    // getters
    int getDX();
    int getDY();

    // setter
    void setVelocidad(int);
    void setDireccion(Direccion);

    void Mover(Graphics^, Direccion);
};

Agente::Agente(int velocidad) : Entidad()
{
    dx = dy = velocidad = 0;
}

Agente::~Agente() {}

int Agente::getDX() { return this->dx; }
int Agente::getDY() { return this->dy; }

void Agente::setVelocidad(int velocidad) { this->velocidad = velocidad; }

void Agente::setDireccion(Direccion teclaPulsada)
{
    switch (teclaPulsada)
    {
    case Arriba:
        this->dx = 0;
        this->dy = -velocidad;
        break;
    case Abajo:
        this->dx = 0;
        this->dy = velocidad;
        break;
    case Izquierda:
        this->dx = -velocidad;
        this->dy = 0;
        break;
    case Derecha:
        this->dx = velocidad;
        this->dy = 0;
        break;
    case Ninguna:
        this->dx = 0;
        this->dy = 0;

        break;
    }
}

void Agente::Mover(Graphics^ canvas, Direccion teclapulsada)
{
    if (teclapulsada == Direccion::Abajo)     indiceAlto = 0;
    if (teclapulsada == Direccion::Arriba)    indiceAlto = 3;
    if (teclapulsada == Direccion::Derecha)   indiceAlto = 2;
    if (teclapulsada == Direccion::Izquierda) indiceAlto = 1;
    if (teclapulsada == Direccion::Ninguna)   indiceAlto = 0;
    
    if (teclapulsada != Direccion::Ninguna)
    {
        indiceAncho++;
        if (indiceAncho > 3) indiceAncho = 0;

        x += dx;
        y += dy;
    }
    else
    {
        indiceAncho = 0;
    }

    Dibujar(canvas);
}