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

    void Mover(Graphics^ g, Direccion teclaPulsada)
    {
        switch (teclaPulsada)
        {
        case Arriba:
            if (y > 90)
            {
                this->dx = 0;
                this->dy = -velocidad;
            }
            else
            {
                teclaPulsada = Direccion::Ninguna;
            }

            idY = 3;
            break;
        case Abajo:
            if (y + alto < 730)
            {
                this->dx = 0;
                this->dy = velocidad;
            }
            else
            {
                teclaPulsada = Direccion::Ninguna;
            }

            idY = 0;
            break;
        case Izquierda:
            if (x > 40)
            {
                this->dx = -velocidad;
                this->dy = 0;
            }
            else
            {
                teclaPulsada = Direccion::Ninguna;
            }

            idY = 1;
            break;
        case Derecha:
            if (x + ancho < 1000)
            {
                this->dx = velocidad;
                this->dy = 0;
            }
            else
            {
                teclaPulsada = Direccion::Ninguna;
            }

            idY = 2;
            break;
        case Ninguna:
            this->dx = 0;
            this->dy = 0;

            idY = 0;
            break;
        }

        if (teclaPulsada != Direccion::Ninguna)
        {
            idX++;
            if (idX > 3) idX = 0;

            x += dx;
            y += dy;
        }
        else
        {
            idX = 0;
        } 
    }
};