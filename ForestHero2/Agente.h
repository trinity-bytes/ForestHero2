#pragma once
#include "Entidad.h"

enum Direccion { Arriba, Abajo, Izquierda, Derecha, Ninguna };

class Agente : public Entidad
{
protected:
    int dx, dy, velocidad;
public:
    Agente(int velocidad) : Entidad(x, y, ancho, alto)
    {
        dx = dy = velocidad = 0;
    }

    ~Agente() {}

    // getters
    int getDY() { return this->dy; }
    int getDX() { return this->dx; }

    // setter
    void setVelocidad(int velocidad) { this->velocidad = velocidad; }
    void setDireccion(Direccion teclaPulsada)
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
        case Ninguno:
            this->dx = 0;
            this->dy = 0;
            break;
        }
    }

    void mover(Graphics^ g, Direccion teclapulsada)
    {
        if (teclapulsada == Direccion::Abajo)     idY = 0;
        if (teclapulsada == Direccion::Arriba)    idY = 3;
        if (teclapulsada == Direccion::Derecha)   idY = 2;
        if (teclapulsada == Direccion::Izquierda) idY = 1;
        if (teclapulsada == Direccion::Ninguno)   idY = 0;

        idX++;
        if (idX > 3) idX = 0;

        x += dx;
        y += dy;
    }
};


