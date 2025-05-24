#pragma once
#include "Agente.h"

/// Clase Semilla que hereda de Agente, demostrando el concepto de herencia
class Semilla : public Agente
{
private:
    /// Variable privada para encapsular el estado de movimiento de la semilla
    bool seMueve;

public:
    /// Constructor que inicializa los atributos de la semilla y llama al constructor de la clase base
    Semilla(int x, int y, int ancho, int alto) : Agente(x, y, velocidad, ancho, alto)
    {
        seMueve = false;
        velocidad = 0;
    }

    /// Constructor sobrecargado que inicializa la semilla con una dirección específica
    Semilla(int x, int y, int ancho, int alto, Direccion direccionActual) : Agente(x, y, velocidad, ancho, alto)
    {
        seMueve = true;
        velocidad = 40;
        this->direccionActual = direccionActual;
    }

    /// Destructor de la clase
    ~Semilla() {}

    /// Método getter para acceder al estado de movimiento de la semilla (encapsulamiento)
    bool getSeMueve() { return seMueve; }

    /// Método sobrescrito para dibujar la semilla (polimorfismo)
    void Dibujar(Graphics^ g, Bitmap^ bmp) override
    {
        g->DrawImage(bmp, x, y, ancho, alto);
    }

    /// Método sobrescrito para mover la semilla (polimorfismo)
    void Mover(Graphics^ g) override
    {
        switch (direccionActual)
        {
        case Arriba:
            if (y > 70) {
                dx = 0;
                dy = -velocidad;
                y += dy;
            }
            break;
        case Abajo:
        case Ninguna:
            if (y + alto < 830) {
                dx = 0;
                dy = velocidad;
                y += dy;
            }
            break;
        case Izquierda:
            if (x > 30) {
                dx = -velocidad;
                dy = 0;
                x += dx;
            }
            break;
        case Derecha:
            if (x + ancho < 1100) {
                dx = velocidad;
                dy = 0;
                x += dx;
            }
            break;
        }
    }
};