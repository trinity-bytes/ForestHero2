#pragma once
#include "Entidad.h"

enum Direccion { Arriba, Abajo, Izquierda, Derecha, Ninguna };

class Agente : public Entidad
{
protected:
    int dx, dy, velocidad;
    Direccion direccionActual;
public:
    Agente(int x, int y, int velocidad, int ancho, int alto) : Entidad(x, y, ancho, alto)
    {
        dx = dy = 0;
        this->velocidad = velocidad;
        direccionActual = Ninguna;
    }

    ~Agente() {}

    // getters
    int getDY() { return this->dy; }
    int getDX() { return this->dx; }
    Direccion getDireccionActual() { return this->direccionActual; }
        
    // setter
    void setDireccionActual(Direccion d) { this->direccionActual = d; }
    void setVelocidad(int velocidad) { this->velocidad = velocidad; }

    virtual void Mover(Graphics^ g)
    {
        dx = dy = 0;

        switch (direccionActual)
        {
        case Arriba:
            if (y > 90) dy = -velocidad;
            else direccionActual = Ninguna;
            idY = 3;
            break;
        case Abajo:
            if (y + alto < 730) dy = velocidad;
            else direccionActual = Ninguna;
            idY = 0;
            break;
        case Izquierda:
            if (x > 40) dx = -velocidad;
            else direccionActual = Ninguna;
            idY = 1;
            break;
        case Derecha:
            if (x + ancho < 1000) dx = velocidad;
            else direccionActual = Ninguna;
            idY = 2;
            break;
        case Ninguna:
            idY = 0;
            break;
        }

        if (direccionActual != Direccion::Ninguna)
        {
            idX = (idX + 1) % 4;
            x += dx;
            y += dy;
        }
        else
        {
            idX = 0;
        } 
    }
};