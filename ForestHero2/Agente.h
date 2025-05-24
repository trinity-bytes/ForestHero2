#pragma once
#include "Entidad.h"

/// Enumeración para las direcciones posibles del agente
enum Direccion { Arriba, Abajo, Izquierda, Derecha, Ninguna };

/// Clase Agente que hereda de Entidad, demostrando el concepto de herencia
class Agente : public Entidad
{
protected:
    /// Variables protegidas para encapsular los datos de la clase
    int dx, dy, velocidad;
    Direccion direccionActual;

public:
    /// Constructor que inicializa los atributos del agente y llama al constructor de la clase base
    Agente(int x, int y, int velocidad, int ancho, int alto) : Entidad(x, y, ancho, alto)
    {
        dx = dy = 0;
        this->velocidad = velocidad;
        direccionActual = Ninguna;
    }

    /// Destructor de la clase
    ~Agente() {}

    /// Métodos getter para acceder a los atributos privados (encapsulamiento)
    int getDY() { return this->dy; }
    int getDX() { return this->dx; }
    Direccion getDireccionActual() { return this->direccionActual; }

    /// Métodos setter para modificar los atributos privados (encapsulamiento)
    void setDireccionActual(Direccion d) { this->direccionActual = d; }
    void setVelocidad(int velocidad) { this->velocidad = velocidad; }

    /// Método virtual que puede ser sobrescrito en clases derivadas (polimorfismo)
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