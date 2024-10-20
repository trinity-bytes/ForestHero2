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

	void addAgua(Agua*);
	void addSemilla(Semilla*);
	void addArbol(Arbol*);
	void addBasura(Basura*);
	void addEnemigo(Enemigo*);

	Agua* returnAgua(int);
	Semilla* returnSemilla(int);
	Arbol* returnArbol(int);
	Basura* returnBasura(int);
	Enemigo* returnEnemigo(int);

	int sizeAgua();
	int sizeSemilla();
	int sizeArbol();
	int sizeBasura();
	int sizeEnemigo();

	vector<Agua*> returnArregloAguas();
	vector<Semilla*> returnArregloSemillas();
	vector<Arbol*> returnArregloArboles();
	vector<Basura*> returnArregloBasuras();
	vector<Enemigo*> returnArregloEnemigos();

	void deleteAgua(int);
	void deleteSemilla(int);
	void deleteArbol(int);
	void deleteBasura(int);
	void deleteEnemigo(int);
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

// Agregar elementos
void ArregloElementos::addAgua(Agua* agua) {
    arregloAguas.push_back(agua);
}

void ArregloElementos::addSemilla(Semilla* semilla) {
    arregloSemillas.push_back(semilla);
}

void ArregloElementos::addArbol(Arbol* arbol) {
    arregloArboles.push_back(arbol);
}

void ArregloElementos::addBasura(Basura* basura) {
    arregloBasuras.push_back(basura);
}

void ArregloElementos::addEnemigo(Enemigo* enemigo) {
    arregloEnemigos.push_back(enemigo);
}

// Retornar elementos
Agua* ArregloElementos::returnAgua(int index) {
    if (index >= 0 && index < arregloAguas.size())
        return arregloAguas.at(index);
    return nullptr; 
}

Semilla* ArregloElementos::returnSemilla(int index) {
    if (index >= 0 && index < arregloSemillas.size())
        return arregloSemillas.at(index);
    return nullptr;
}

Arbol* ArregloElementos::returnArbol(int index) {
    if (index >= 0 && index < arregloArboles.size())
        return arregloArboles.at(index);
    return nullptr;
}

Basura* ArregloElementos::returnBasura(int index) {
    if (index >= 0 && index < arregloBasuras.size())
        return arregloBasuras.at(index);
    return nullptr;
}

Enemigo* ArregloElementos::returnEnemigo(int index) {
    if (index >= 0 && index < arregloEnemigos.size())
        return arregloEnemigos.at(index);
    return nullptr;
}

// Tamaño de los vectores
int ArregloElementos::sizeAgua() {
    return arregloAguas.size();
}

int ArregloElementos::sizeSemilla() {
    return arregloSemillas.size();
}

int ArregloElementos::sizeArbol() {
    return arregloArboles.size();
}

int ArregloElementos::sizeBasura() {
    return arregloBasuras.size();
}

int ArregloElementos::sizeEnemigo() {
    return arregloEnemigos.size();
}

// Retornar todos los vectores
vector<Agua*> ArregloElementos::returnArregloAguas() {
    return arregloAguas;
}

vector<Semilla*> ArregloElementos::returnArregloSemillas() {
    return arregloSemillas;
}

vector<Arbol*> ArregloElementos::returnArregloArboles() {
    return arregloArboles;
}

vector<Basura*> ArregloElementos::returnArregloBasuras() {
    return arregloBasuras;
}

vector<Enemigo*> ArregloElementos::returnArregloEnemigos() {
    return arregloEnemigos;
}

// Eliminar elementos por índice
void ArregloElementos::deleteAgua(int index) {
    if (index >= 0 && index < arregloAguas.size())
        arregloAguas.erase(arregloAguas.begin() + index);
}

void ArregloElementos::deleteSemilla(int index) {
    if (index >= 0 && index < arregloSemillas.size())
        arregloSemillas.erase(arregloSemillas.begin() + index);
}

void ArregloElementos::deleteArbol(int index) {
    if (index >= 0 && index < arregloArboles.size())
        arregloArboles.erase(arregloArboles.begin() + index);
}

void ArregloElementos::deleteBasura(int index) {
    if (index >= 0 && index < arregloBasuras.size())
        arregloBasuras.erase(arregloBasuras.begin() + index);
}

void ArregloElementos::deleteEnemigo(int index) {
    if (index >= 0 && index < arregloEnemigos.size())
        arregloEnemigos.erase(arregloEnemigos.begin() + index);
}