#pragma once
using namespace System::Drawing;

/// Clase base que utiliza el concepto de abstracción para definir una entidad genérica
class Entidad
{
protected:
    /// Variables protegidas para encapsular los datos de la clase
    int x, y, ancho, alto, idX, idY;

public:
    /// Constructor que inicializa los atributos de la entidad
    Entidad(int px, int py, int pancho, int palto)
    {
        this->x = px;
        this->y = py;
        this->ancho = pancho;
        this->alto = palto;
        this->idX = 0;
        this->idY = 0;
    }

    /// Destructor de la clase
    ~Entidad() {}

    /// Métodos getter para acceder a los atributos privados (encapsulamiento)
    int getX() { return this->x; }
    int getY() { return this->y; }
    int getAncho() { return this->ancho; }
    int getAlto() { return this->alto; }

    /// Métodos setter para modificar los atributos privados (encapsulamiento)
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    /// Método virtual que puede ser sobrescrito en clases derivadas (polimorfismo)
    virtual void Dibujar(Graphics^ g, Bitmap^ bmp)
    {
        System::Drawing::Rectangle sectionShow = System::Drawing::Rectangle(idX * ancho, idY * alto, ancho, alto);
        System::Drawing::Rectangle zoom = System::Drawing::Rectangle(x, y, ancho, alto);
        g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
    }

    /// Método para obtener un rectángulo que representa la entidad
    System::Drawing::Rectangle getRectangle()
    {
        return System::Drawing::Rectangle(x, y, ancho * 0.9, alto * 0.9);
    }
};