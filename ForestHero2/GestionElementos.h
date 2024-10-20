#pragma once
#include "Enemigo.h"
#include "Agua.h"
#include "Semilla.h"
#include "Arbol.h"
#include "Basura.h"
#include "vector"

using namespace std;

class ArregloElementos
{
private:
	vector<Agua*> arregloAguas;
	vector<Semilla*> arregloSemillas;
	vector<Arbol*> arregloArboles;
	vector<Basura*> arregloBasuras;
	vector<Enemigo*> arregloEnemigos;
public:
	ArregloElementos();
	~ArregloElementos();

	void AgregarAgua(Agua*);
	Agua* ObtenerAgua(int);
	int CantidadAgua();
	vector<Agua*> Retornar();
	void EliminarAgua(int);
};

ArregloElementos::ArregloElementos()
{
	arregloAguas = vector<Agua*>();
	arregloSemillas = vector<Semilla*>();
	arregloArboles = vector<Arbol*>();
	arregloBasuras = vector<Basura*>();
	arregloEnemigos = vector<Enemigo*>();
}

ArregloElementos::~ArregloElementos() {}