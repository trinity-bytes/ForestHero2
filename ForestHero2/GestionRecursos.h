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
    ArregloElementos() {
        arregloAguas = vector<Agua*>();
        arregloSemillas = vector<Semilla*>();
        arregloArboles = vector<Arbol*>();
        arregloBasuras = vector<Basura*>();
        arregloEnemigos = vector<Enemigo*>();
    }

    ~ArregloElementos() {}

    // Agregar elementos
    void addAgua(Agua* agua) {
        arregloAguas.push_back(agua);
    }

    void addSemilla(Semilla* semilla) {
        arregloSemillas.push_back(semilla);
    }

    void addArbol(Arbol* arbol) {
        arregloArboles.push_back(arbol);
    }

    void addBasura(Basura* basura) {
        arregloBasuras.push_back(basura);
    }

    void addEnemigo(Enemigo* enemigo) {
        arregloEnemigos.push_back(enemigo);
    }

    // Retornar elementos
    Agua* returnAgua(int index) {
        if (index >= 0 && index < arregloAguas.size())
            return arregloAguas.at(index);
        return nullptr;
    }

    Semilla* returnSemilla(int index) {
        if (index >= 0 && index < arregloSemillas.size())
            return arregloSemillas.at(index);
        return nullptr;
    }

    Arbol* returnArbol(int index) {
        if (index >= 0 && index < arregloArboles.size())
            return arregloArboles.at(index);
        return nullptr;
    }

    Basura* returnBasura(int index) {
        if (index >= 0 && index < arregloBasuras.size())
            return arregloBasuras.at(index);
        return nullptr;
    }

    Enemigo* returnEnemigo(int index) {
        if (index >= 0 && index < arregloEnemigos.size())
            return arregloEnemigos.at(index);
        return nullptr;
    }

    // Tamaño de los vectores
    int sizeAgua() {
        return arregloAguas.size();
    }

    int sizeSemilla() {
        return arregloSemillas.size();
    }

    int sizeArbol() {
        return arregloArboles.size();
    }

    int sizeBasura() {
        return arregloBasuras.size();
    }

    int sizeEnemigo() {
        return arregloEnemigos.size();
    }

    // Retornar todos los vectores
    vector<Agua*> returnArregloAguas() {
        return arregloAguas;
    }

    vector<Semilla*> returnArregloSemillas() {
        return arregloSemillas;
    }

    vector<Arbol*> returnArregloArboles() {
        return arregloArboles;
    }

    vector<Basura*> returnArregloBasuras() {
        return arregloBasuras;
    }

    vector<Enemigo*> returnArregloEnemigos() {
        return arregloEnemigos;
    }

    // Eliminar elementos por índice
    void deleteAgua(int index) {
        if (index >= 0 && index < arregloAguas.size())
            arregloAguas.erase(arregloAguas.begin() + index);
    }

    void deleteSemilla(int index) {
        if (index >= 0 && index < arregloSemillas.size())
            arregloSemillas.erase(arregloSemillas.begin() + index);
    }

    void deleteArbol(int index) {
        if (index >= 0 && index < arregloArboles.size())
            arregloArboles.erase(arregloArboles.begin() + index);
    }

    void deleteBasura(int index) {
        if (index >= 0 && index < arregloBasuras.size())
            arregloBasuras.erase(arregloBasuras.begin() + index);
    }

    void deleteEnemigo(int index) {
        if (index >= 0 && index < arregloEnemigos.size())
            arregloEnemigos.erase(arregloEnemigos.begin() + index);
    }
};
