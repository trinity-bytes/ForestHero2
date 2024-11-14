#pragma once
#include "FuncionesCustom.h"
#include "MyForm1.h"
#include "MyForm2.h"
//#include "MyForm3.h"
#include "Guardian.h"
#include "Enemigo.h"
#include "Agua.h"
#include "Semilla.h"
#include "Arbol.h"
#include "Basura.h"
#include "vector"
#include "cmath" //todo para usar sqrt y pow en la funcion de calcular distancia

using namespace std;
using namespace System;
using namespace System::Drawing;

class GestionJuego
{
private:
	vector<Agua*> arregloAgua;
	vector<Semilla*> arregloSemillas;
	vector<Arbol*> arregloArboles;
	vector<Basura*> arregloBasuras;
	vector<Enemigo*> arregloEnemigos;

	//! Definimos la cantidad inical de cada elemento del mapa
	/// iniciando los recursos
	const int cantidadInicialEnemigos = 6;
	const int cantidadInicialAgua = 8;
	const int cantidadInicialSemillas = 12;

	/// Limites del escenario
	const int limXizquierda = 40;
	const int limXderecha = 1000;
	const int limYsuperior = 90;
	const int limYinferior = 730;

	// para las coordenadas de los objetos que se van a generar
	int cx, cy;

	//! Para definir las dimenciones de las celdas del escenario
	const int anchoCelda = 80;
	const int altoCelda = 80;
	//! Definimo las filas y columnas
	static const int filasMatriz = 8;
	static const int columnasMatriz = 12;
	//! Creamos la matriz que llevara el registro de los arboles plantados
	bool matrizArboles[filasMatriz][columnasMatriz] = {false};

public:
	GestionJuego()
	{
		// iniciamos los arreglos
		arregloAgua = vector<Agua*>();
		arregloSemillas = vector<Semilla*>();
		arregloArboles = vector<Arbol*>();
		arregloBasuras = vector<Basura*>();
		arregloEnemigos = vector<Enemigo*>();
	}

	~GestionJuego() {}

	void IniciarElementos(
		int anchoEnemigo, int altoEnemigo,
		int anchoAgua, int altoAgua,
		int anchoSemilla, int altoSemilla
	) 
	{
		// inicializar enemigos
		for (int i = 0; i < cantidadInicialEnemigos; i++)
		{
			AgregarEnemigo(anchoEnemigo, altoEnemigo);
		}

		// inicializar agua
		for (int i = 0; i < cantidadInicialAgua; i++)
		{
			AgregarAgua(anchoAgua, altoAgua);
		}

		// inicializar semillas
		for (int i = 0; i < cantidadInicialSemillas; i++)
		{
			AgregarSemilla(anchoSemilla, altoSemilla);
		}
	}

	void DibujarTodo(
		Graphics^ g,
		Bitmap^ bmpEnemigo,
		Bitmap^ bmpAgua,
		Bitmap^ bmpSemilla,
		Bitmap^ bmpBasura,
		Bitmap^ bmpArbol
	)
	{
		// dibujamos los arboles
		if (arregloArboles.size() > 0)
		{
			for (int i = 0; i < arregloArboles.size(); i++)
			{
				arregloArboles[i]->Dibujar(g, bmpArbol);
			}
		}
		
		// dibujamos el agua
		if (arregloAgua.size() > 0)
		{
			for (int i = 0; i < arregloAgua.size(); i++)
			{
				arregloAgua[i]->Dibujar(g, bmpAgua);
			}
		}
				
		// dibujamos las semillas
		if (arregloSemillas.size() > 0)
		{
			for (int i = 0; i < arregloSemillas.size(); i++)
			{
				arregloSemillas[i]->Dibujar(g, bmpSemilla);
			}
		}
		
		// dibujamos la basura
		if (arregloBasuras.size() > 0)
		{
			for (int i = 0; i < arregloBasuras.size(); i++)
			{
				arregloBasuras[i]->Dibujar(g, bmpBasura);
			}
		}
		
		// dibujamos a los enemigos
		if (arregloEnemigos.size() > 0)
		{
			for (int i = 0; i < arregloEnemigos.size(); i++)
			{
				arregloEnemigos[i]->Dibujar(g, bmpEnemigo);
			}
		}
	}

	void MoverTodo(Graphics^ g) 
	{
		int r;

		//! Mover enemigos
		for (int i = 0; i < arregloEnemigos.size(); i++)
		{
			r = GenerarNumeroAleatorio(0, 40);

			switch (r)
			{
			case 1:
				arregloEnemigos[i]->setDireccionActual(Arriba); break;
			case 10:
				arregloEnemigos[i]->setDireccionActual(Abajo); break;
			case 15:
				arregloEnemigos[i]->setDireccionActual(Izquierda); break;
			case 20:
				arregloEnemigos[i]->setDireccionActual(Derecha); break;
			case 25:
				arregloEnemigos[i]->setDireccionActual(Ninguna); break;
			default:
				break;
			}

			arregloEnemigos[i]->Mover(g);
		}

		//! Mover semillas
		for (int i = 0; i < arregloSemillas.size(); i++)
		{
			if (!arregloSemillas[i]->getSeMueve()) continue; /// ignoraos las semillas que no se mueven uwu

			arregloSemillas[i]->Mover(g);
		}
	}

	void ColisionPersonaje(Guardian* objGuardian)
	{
		/// colision con semillas
		for (int i = 0; i < arregloSemillas.size(); i++)
		{
			if (arregloSemillas[i]->getSeMueve()) continue;
			if (arregloSemillas[i]->getRectangle().IntersectsWith(objGuardian->getRectangle()))
			{
				arregloSemillas.erase(arregloSemillas.begin() + i);

				objGuardian->setCantSemillas(objGuardian->getCantSemillas() + 1);
				i--;
				objGuardian->setPuntos(1000);
			}
		}

		/// Colision con agua
		for (int i = 0; i < arregloAgua.size(); i++)
		{
			if (i >= arregloAgua.size()) break;

			if (arregloAgua[i]->getRectangle().IntersectsWith(objGuardian->getRectangle()))
			{
				// incrementar el contador de agua del guardian
				objGuardian->setCantAgua(objGuardian->getCantAgua() + 1);

				arregloAgua.erase(arregloAgua.begin() + i);
				i--;
				objGuardian->setPuntos(1000);
			}
		}

		/// Colision con basura
		for (int i = 0; i < arregloBasuras.size(); i++)
		{
			if (arregloBasuras[i]->getRectangle().IntersectsWith(objGuardian->getRectangle()))
			{
				//Perder Vidas
				objGuardian->setCantVidas(-1);
			}
		}

		/// Colision con los enemigos
		for (int i = 0; i < arregloEnemigos.size(); i++)
		{
			if (i >= arregloEnemigos.size()) break;

			if (arregloEnemigos[i]->getRectangle().IntersectsWith(objGuardian->getRectangle()))
			{
				///Perder Vidas

				arregloEnemigos.erase(arregloEnemigos.begin() + i);
				i--;
				objGuardian->setCantVidas(-1);
			}
		}
	}

	void AgregarEnemigo(int anchoEnemigo, int altoEnemigo)
	{
		cx = GenerarNumeroAleatorio(limXizquierda, limXderecha - anchoEnemigo);
		cy = GenerarNumeroAleatorio(limYsuperior, limYinferior - altoEnemigo);

		Enemigo* e = new Enemigo(cx, cy, anchoEnemigo, altoEnemigo);
		arregloEnemigos.push_back(e);
	}

	void AgregarAgua(int anchoAgua, int altoAgua)
	{
		cx = GenerarNumeroAleatorio(limXizquierda, limXderecha - anchoAgua);
		cy = GenerarNumeroAleatorio(limYsuperior, limYinferior - altoAgua);

		Agua* a = new Agua(cx, cy, anchoAgua, altoAgua);
		arregloAgua.push_back(a);
	}

	void AgregarSemilla(int anchoSemilla, int altoSemilla)
	{
		cx = GenerarNumeroAleatorio(limXizquierda, limXderecha - anchoSemilla);
		cy = GenerarNumeroAleatorio(limYsuperior, limYinferior - altoSemilla);

		Semilla* s = new Semilla(cx, cy, anchoSemilla, altoSemilla);
		arregloSemillas.push_back(s);
	}

	void AgregarBasura(int anchoBasura, int altoBasura)
	{
		int r = GenerarNumeroAleatorio(0, arregloEnemigos.size() - 1);

		cx = arregloEnemigos[r]->getX();
		cy = arregloEnemigos[r]->getY();

		Basura* b = new Basura(cx, cy, anchoBasura, altoBasura);
		arregloBasuras.push_back(b);
	}

	void AgregarArbol(int x, int y, int anchoArbol, int altoArbol)
	{
		Arbol* a = new Arbol(x, y, anchoArbol, altoArbol);
		arregloArboles.push_back(a);
	}

	void PlantarArbol(Guardian* objGuardian, int anchoArbol, int altoArbol)
	{
		int columnaActual = objGuardian->getX() / anchoCelda;
		int filaActual = objGuardian->getY() / altoCelda;

		/// Calcualmos el centro de la celda actual y las cercanas
		int posiciones[4][2] = {
		{ columnaActual * anchoCelda + anchoCelda / 2, filaActual * altoCelda + altoCelda / 2 },
		{ (columnaActual + 1) * anchoCelda + anchoCelda / 2, filaActual * altoCelda + altoCelda / 2 },
		{ columnaActual * anchoCelda + anchoCelda / 2, (filaActual + 1) * altoCelda + altoCelda / 2 },
		{ (columnaActual + 1) * anchoCelda + anchoCelda / 2, (filaActual + 1) * altoCelda + altoCelda / 2 }
		};

		/// Determinamos cual es la celda mas cercana comparando sus distancias
		int mejorColumna = columnaActual, mejorFila = filaActual;
		double distanciaMinima = CalcularDistancia(
									objGuardian->getX(), 
									objGuardian->getY(), 
									posiciones[0][0], 
									posiciones[0][1]
								);

		for (int i = 1; i < 4; i++) {
			int nuevaColumna = (i % 2 == 0) ? columnaActual : columnaActual + 1;
			int nuevaFila = (i < 2) ? filaActual : filaActual + 1;

			if (nuevaColumna < columnasMatriz && nuevaFila < filasMatriz) {
				double distancia = CalcularDistancia(
										objGuardian->getX(), 
										objGuardian->getY(), 
										posiciones[i][0], 
										posiciones[i][1]
									);
				if (distancia < distanciaMinima) {
					distanciaMinima = distancia;
					mejorColumna = nuevaColumna;
					mejorFila = nuevaFila;
				}
			}
		}

		/// Plantamos el arbol en la celda mas cercana, si es que esta libre
		if (!matrizArboles[mejorFila][mejorColumna]) {
			int xArbol = limXizquierda + mejorColumna * anchoCelda + anchoCelda / 2 - anchoArbol / 2;
			int yArbol = mejorFila * altoCelda + altoCelda / 2 - altoArbol / 2;

			AgregarArbol(xArbol, yArbol, anchoArbol, altoArbol);
			matrizArboles[mejorFila][mejorColumna] = true;

			objGuardian->setCantAgua(objGuardian->getCantAgua() - 1);
			objGuardian->setCantSemillas(objGuardian->getCantSemillas() - 1);
		}
	}

	void DispararSemilla(int anchoSemilla, int altoSemilla, Guardian* objGuardian)
	{
		switch (objGuardian->getDireccionActual()) {
		case Arriba:
			cy = objGuardian->getY() - objGuardian->getAlto();
			cx = objGuardian->getX();
			break;
		case Abajo:
			cy = objGuardian->getY() + objGuardian->getAlto();
			cx = objGuardian->getX();
			break;
		case Izquierda:
			cy = objGuardian->getY();
			cx = objGuardian->getX() - objGuardian->getAncho();
			break;
		case Derecha:
			cy = objGuardian->getY();
			cx = objGuardian->getX() + objGuardian->getAncho();
			break;
		case Ninguna:
			cy = objGuardian->getY() - objGuardian->getAlto();
			cx = objGuardian->getX();
			break;
		}

		Semilla* s = new Semilla(
			cx,
			cy,
			anchoSemilla, 
			altoSemilla, 
			objGuardian->getDireccionActual()
		);

		arregloSemillas.push_back(s);
	}

	void DeterminarGanador() 
	{
		//Poner la funcion de determinar ganador
		/*MyForm3^ win = gcnew MyForm3();
			win->Show();*/
	}

	bool AnalizarGAMEOVER(Guardian* objGuardian, bool objetivoComletado)
	{
		if (objGuardian->getCantVidas()==0)
		{
			//Poner GAMEOVER
			/*MyForm2^ gameOver = gcnew MyForm2();
			gameOver->Show();*/
		}
	}

	double CalcularDistancia(int x1, int y1, int x2, int y2) {
		/// calculamos la distancia entre 2 coordenadas
		return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	}
};