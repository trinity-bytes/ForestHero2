#pragma once
#include "FuncionesCustom.h"
#include "Enemigo.h"
#include "Agua.h"
#include "Semilla.h"
#include "Arbol.h"
#include "Basura.h"
#include "vector"

using namespace std;

class GestionJuego
{
private:
	vector<Agua*> arregloAgua;
	vector<Semilla*> arregloSemillas;
	vector<Arbol*> arregloArboles;
	vector<Basura*> arregloBasuras;
	vector<Enemigo*> arregloEnemigos;

	// Definimos la cantidad inical de cada elemento del mapa
	int cantidadInicialEnemigos;
	int cantidadInicialAgua;
	int cantidadInicialSemillas;
public:
	GestionJuego()
	{
		// iniciamos los arreglos siuuu
		arregloAgua = vector<Agua*>();
		arregloSemillas = vector<Semilla*>();
		arregloArboles = vector<Arbol*>();
		arregloBasuras = vector<Basura*>();
		arregloEnemigos = vector<Enemigo*>();

		/// iniciando los recursos
		cantidadInicialEnemigos = 5;
		cantidadInicialAgua = 8;
		cantidadInicialSemillas = 12;
	}

	~GestionJuego() {}

	void IniciarElementos(int anchoEnemigos, int altoEnemigos, int anchoAgua, int altoAgua) 
	{
		int cx, cy;

		// inicializar enemigos
		for (int i = 0; i < cantidadInicialEnemigos; i++)
		{
			cx = GenerarNumeroAleatorio(20, 820 - anchoEnemigos);
			cy = GenerarNumeroAleatorio(60, 590 - altoEnemigos);

			Enemigo* e = new Enemigo(cx, cy, anchoEnemigos, altoEnemigos);
			arregloEnemigos.push_back(e);
		}

		// inicializar agua
		for (int i = 0; i < cantidadInicialAgua; i++)
		{
			cx = GenerarNumeroAleatorio(20, 820 - anchoAgua);
			cy = GenerarNumeroAleatorio(60, 590 - altoAgua);

			Agua* a = new Agua(cx, cy, anchoAgua, altoAgua);
			arregloAgua.push_back(a);
		}

		// inicializar semillas
	}

	void DibujarTodo(Graphics^ g, Bitmap^ bmpEnemigo, Bitmap^ bmpAgua)
	{
		// dibujamos el agua
		for (int i = 0; i < arregloAgua.size(); i++)
		{
			arregloAgua[i]->Dibujar(g, bmpAgua);
		}
		
		// dibujamos las semillas


		// dibujamos los arboles


		// dibujamos la basura


		// dibujamos a los enemigos
		for (int i = 0; i < arregloEnemigos.size(); i++)
		{
			arregloEnemigos[i]->Dibujar(g, bmpEnemigo);
		}
	}

	void MoverTodo(Graphics^ g) 
	{
		int r;

		//! Mover enemigos
		for (int i = 0; i < arregloEnemigos.size(); i++)
		{
			r = GenerarNumeroAleatorio(0, 70);

			switch (r)
			{
			case 1:
				arregloEnemigos[i]->setDireccionActual(Arriba); break;
			case 15:
				arregloEnemigos[i]->setDireccionActual(Abajo); break;
			case 30:
				arregloEnemigos[i]->setDireccionActual(Izquierda); break;
			case 45:
				arregloEnemigos[i]->setDireccionActual(Derecha); break;
			case 60:
				arregloEnemigos[i]->setDireccionActual(Ninguna); break;
			default:
				break;
			}

			arregloEnemigos[i]->Mover(g, arregloEnemigos[i]->getDireccionActual());
		}
	}
	void RevisarColisiones() 
	{
		//for (int i = 0; i < objElementos->sizeBasura(); i++)
		//{
		//	for (int j = 0; j < objElementos->sizeSemilla(); j++)
		//	{
		//		if (objElementos->returnBasura(i)->getRectangle().IntersectsWith(objElementos->returnSemilla(j)->getRectangle()))
		//		{
		//			objElementos->deleteBasura(i);
		//			objElementos->deleteSemilla(j);
		//			//Eliminar la basura y la semilla al realizar la colision
		//		}
		//	}
		//}

		//for (int i = 0; i < objElementos->sizeEnemigo(); i++)
		//{
		//	if (objElementos->returnEnemigo(i)->getRectangle().IntersectsWith(objGuardian->getRectangle()))
		//	{
		//		//Perder Vidas 
		//		objGuardian->setVidas(-1);
		//		objElementos->deleteEnemigo(i);
		//	}
		//}

		//for (int i = 0; i < objElementos->sizeBasura(); i++)
		//{
		//	if (objElementos->returnBasura(i)->getRectangle().IntersectsWith(objGuardian->getRectangle()))
		//	{
		//		//Perder Vidas
		//		objGuardian->setVidas(-1);
		//	}
		//}

		//for (int i = 0; i < objElementos->sizeAgua(); i++)
		//{
		//	if (objElementos->returnAgua(i)->getRectangle().IntersectsWith(objGuardian->getRectangle()))
		//	{
		//		//Aumentar agua
		//		objElementos->addAgua(objAgua);
		//	}
		//}
		//for (int i = 0; i < objElementos->sizeArbol(); i++)
		//{
		//	if (objElementos->returnArbol(i)->getRectangle().IntersectsWith(objGuardian->getRectangle()))
		//	{
		//		//No se si este es la semilla que se encuentra por el suelo, en ese caso en vez de ser
		//		//return arbol, es return Semilla
		//		//Aumentar semillas
		//	}
		//}
	}
	void DeterminarGanador() 
	{
		//Poner la funcion de determinar ganador
	}

	//bool AnalizarGAMEOVER()
	//{
	//	if (objGuardian->getVidas()==0)
	//	{
	//		//Poner GAMEOVER
	//	}
	//}
};