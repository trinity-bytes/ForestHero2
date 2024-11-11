#pragma once
#include "FuncionesCustom.h"
//#include "GestionRecursos.h"
#include "Enemigo.h"
#include "Agua.h"
#include "Semilla.h"
#include "Arbol.h"
#include "Basura.h"
#include "vector"
//#include "Guardian.h"

using namespace std;

class GestionJuego
{
private:
	//ArregloElementos* objElementos;
	//Guardian* objGuardian;
	vector<Agua*> arregloAgua;
	vector<Semilla*> arregloSemillas;
	vector<Arbol*> arregloArboles;
	vector<Basura*> arregloBasuras;
	vector<Enemigo*> arregloEnemigos;

	int cantidadInicialEnemigos;
	Direccion direccionActual;
public:
	GestionJuego()
	{
		// iniciamos los arreglos siuuu
		arregloAgua = vector<Agua*>();
		arregloSemillas = vector<Semilla*>();
		arregloArboles = vector<Arbol*>();
		arregloBasuras = vector<Basura*>();
		arregloEnemigos = vector<Enemigo*>();

		direccionActual = Ninguna;
		cantidadInicialEnemigos = 5;
	}
	~GestionJuego() {}

	void IniciarElementos(int ancho, int alto) 
	{
		int cx, cy;
		// inicializar enemigos
		for (int i = 0; i < cantidadInicialEnemigos; i++)
		{
			cx = GenerarNumeroAleatorio(20, 820 - ancho);
			cy = GenerarNumeroAleatorio(60, 590 - alto);
			Enemigo* e = new Enemigo(cx, cy, ancho, alto);
			arregloEnemigos.push_back(e);
		}

		// inicializar agua


		// inicializar semillas
	}

	void DibujarTodo(Graphics^ g, Bitmap^ bmpEnemigo)
	{
		// dibujamos a los enemigos
		for (int i = 0; i < arregloEnemigos.size(); i++)
		{
			arregloEnemigos[i]->Dibujar(g, bmpEnemigo);
		}

		// dibujamos el agua


		// dibujamos las semillas


		// dibujamos los arboles


		// dibujamos la basura
	}

	void MoverTodo(Graphics^ g) 
	{
		int r;

		for (int i = 0; i < arregloEnemigos.size(); i++)
		{
			r = GenerarNumeroAleatorio(0, 100);

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
			case 95:
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