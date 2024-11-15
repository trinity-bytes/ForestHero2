#pragma once
#include "FuncionesCustom.h"
#include "MyForm1.h"
//#include "MyForm2.h"
//#include "MyForm3.h"
#include "Guardian.h"
#include "Enemigo.h"
#include "Aliado.h"
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
	Aliado* aliado;

	// para calcular el porcentaje de reforestacion
	const int cantMaxArboles = 96;

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
	// con este timer podemos dar un tiempo de inmunidad al guardian
	int pseudoTimerInmunidad = 0;
	const int timeOutBasura = 20;
	const int timeOutPowerUp = 50;
	// para controlar el estado de inmunidad del guardian
	bool guardianInmune = false;

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
		aliado = new Aliado(40, 500, 20, 125, 125);
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
		Bitmap^ bmpArbol,
		Bitmap^ bmpAliado
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

		//dibujar Aliado
		if (aliado->getVisible() == true) aliado->Dibujar(g,bmpAliado);
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

			/// eliminamos las semillas que traspasan los limites del escenario
			if (arregloSemillas[i]->getX() < limXizquierda ||
				arregloSemillas[i]->getX() > limXderecha ||
				arregloSemillas[i]->getY() < limYsuperior ||
				arregloSemillas[i]->getY() > limYinferior)
			{
				arregloSemillas.erase(arregloSemillas.begin() + i);
				i--;
			}
		}

		//! MoverAliado
		aliado->Mover(g);
		if (aliado->getX() > 995 + aliado->getAlto()) aliado->setVisible(false);
	}

	void ColisionPersonaje(Guardian* objGuardian)
	{
		vector<int> indicesSemillasEliminar;
		vector<int> indicesEnemigosEliminar;
		vector<int> indicesAguaEliminar;
		vector<int> indicesBasuraEliminar;

		/// colision Guardian - semillas
		for (int i = 0; i < arregloSemillas.size(); i++)
		{
			if (arregloSemillas[i]->getSeMueve()) continue; /// ignoramos a las semillas que se mueven (asi como ella me ignora pipipi)
			if (arregloSemillas[i]->getRectangle().IntersectsWith(objGuardian->getRectangle()))
			{
				indicesSemillasEliminar.push_back(i);

				objGuardian->setCantSemillas(objGuardian->getCantSemillas() + 1);
				objGuardian->setPuntos(1000);
			}
		}

		/// Colision Guardian - agua
		for (int i = 0; i < arregloAgua.size(); i++)
		{
			if (i >= arregloAgua.size()) break;

			if (arregloAgua[i]->getRectangle().IntersectsWith(objGuardian->getRectangle()))
			{
				// incrementar el contador de agua del guardian
				objGuardian->setCantAgua(objGuardian->getCantAgua() + 1);
				objGuardian->setPuntos(1000);

				indicesAguaEliminar.push_back(i);				
			}
		}

		/// Colision guardian - basura
		
		for (int i = 0; i < arregloBasuras.size(); i++)
		{
			if (arregloBasuras[i]->getRectangle().IntersectsWith(objGuardian->getRectangle()))
			{
				if (guardianInmune == false)
				{
					//Perder Vidas
					if (objGuardian->getCantVidas() > 0) objGuardian->setCantVidas(-1);
					
					guardianInmune = true;
					// todo timeout de inmunidad para que el guardian no pierda vidas infinitamente
					pseudoTimerInmunidad = timeOutBasura;
				}
				
			}
		}
				
		/// Colision guardian - enemigos
		for (int i = 0; i < arregloEnemigos.size(); i++)
		{
			if (i >= arregloEnemigos.size()) break;

			if (arregloEnemigos[i]->getRectangle().IntersectsWith(objGuardian->getRectangle()))
			{
				///Perder Vidas
				indicesEnemigosEliminar.push_back(i);
				objGuardian->setCantVidas(-1);
			}
		}

		/// Colision semilla - basura
		for (int i = 0; i < arregloSemillas.size(); i++)
		{
			if (!arregloSemillas[i]->getSeMueve()) continue; /// ignormos a las semillas que no semueven

			for (int j = 0; j < arregloBasuras.size(); j++)
			{
				if (arregloSemillas[i]->getRectangle().IntersectsWith(arregloBasuras[j]->getRectangle()))
				{
					//todo Aqui lo que se hace es que se realiza una comprobacion 
					//todo con el metodo find para corroborar que el indice que se 
					//todo va a agregar al arreglo no haya sigo agregado previamente
					/// Asi se evita que haya indices duplicados y ocurra un error de vector fuera de rango, de nada.
					// este tipo de comprobaciones se implementa mas adelante en la colision Semilla-Enemigo
					if (std::find(indicesSemillasEliminar.begin(), indicesSemillasEliminar.end(), i) == indicesSemillasEliminar.end())	
						indicesSemillasEliminar.push_back(i);

					if (std::find(indicesBasuraEliminar.begin(), indicesBasuraEliminar.end(), j) == indicesBasuraEliminar.end())
					indicesBasuraEliminar.push_back(j);
					break; /// terminamos el ciclo ya que se elimino la semilla
				}
			}
		}

		/// Colison Semilla - Enemigo
		for (int i = 0; i < arregloSemillas.size(); i++)
		{
			if (!arregloSemillas[i]->getSeMueve()) continue; /// ignormos a las semillas que no semueven

			for (int j = 0; j < arregloEnemigos.size(); j++)
			{
				if (arregloSemillas[i]->getRectangle().IntersectsWith(arregloEnemigos[j]->getRectangle()))
				{
					//todo Comprobacion de la existencia del indice (previamente explicado)
					if (std::find(indicesSemillasEliminar.begin(), indicesSemillasEliminar.end(), i) == indicesSemillasEliminar.end())
						indicesSemillasEliminar.push_back(i);

					/// le restamos vidas al enemigo
					arregloEnemigos[j]->setVidas(arregloEnemigos[j]->getVidas() - 1);

					if (arregloEnemigos[j]->getVidas() <= 0) /// verificamos las vidas del enemigo
					{
						if (std::find(indicesEnemigosEliminar.begin(), indicesEnemigosEliminar.end(), j) == indicesEnemigosEliminar.end())
							indicesEnemigosEliminar.push_back(j);
					}
					break; /// terminamos el ciclo ya que se elimino la semilla
				}
			}
		}

		//todo Eliminamos los elementos fuera de los bucles
		/// esta forma de for lo que hace es que busca desde el inicio al final de la matriz 
		/// y compara sus valores para descartar valores duplicados
		for (auto i = indicesSemillasEliminar.rbegin(); i != indicesSemillasEliminar.rend(); ++i)
		{
			arregloSemillas.erase(arregloSemillas.begin() + *i);
		}
		for (auto i = indicesEnemigosEliminar.rbegin(); i != indicesEnemigosEliminar.rend(); ++i)
		{
			arregloEnemigos.erase(arregloEnemigos.begin() + *i);
		}
		for (int i = indicesAguaEliminar.size() - 1; i >= 0; i--)
		{
			arregloAgua.erase(arregloAgua.begin() + indicesAguaEliminar[i]);
		}
		for (int i = indicesBasuraEliminar.size() - 1; i >= 0; i--)
		{
			arregloBasuras.erase(arregloBasuras.begin() + indicesBasuraEliminar[i]);
		}

		/// Decrecentamos el pseudotimer si es mayor a 0
		if (pseudoTimerInmunidad > 0) pseudoTimerInmunidad--;
		else guardianInmune = false;
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
		/// Obtenemos el centro del personaje
		int centroX = objGuardian->getX() + objGuardian->getAncho() / 2;
		int centroY = objGuardian->getY() + objGuardian->getAlto() / 2;

		/// Ajustamos la posicion x e y para evitar errores de calculo de las posiciones
		/// en las celdas
		int xAjustado = centroX - limXizquierda;
		int yAjustado = centroY - limYsuperior;

		///caclulamos la fila y columna actuales en base a la posicion ajustada
		int columnaActual = xAjustado / anchoCelda;
		int filaActual = yAjustado / altoCelda;

		/// Calculamos el centro de la celda actual y las cercanas
		int posiciones[4][2] = {
		{ columnaActual * anchoCelda + anchoCelda / 2, filaActual * altoCelda + altoCelda / 2 },
		{ (columnaActual + 1) * anchoCelda + anchoCelda / 2, filaActual * altoCelda + altoCelda / 2 },
		{ columnaActual * anchoCelda + anchoCelda / 2, (filaActual + 1) * altoCelda + altoCelda / 2 },
		{ (columnaActual + 1) * anchoCelda + anchoCelda / 2, (filaActual + 1) * altoCelda + altoCelda / 2 }
		};

		/// Determinamos cual es la celda mas cercana comparando sus distancias
		int mejorColumna = columnaActual, mejorFila = filaActual;
		double distanciaMinima = CalcularDistancia(
									xAjustado,
									yAjustado, 
									posiciones[0][0], 
									posiciones[0][1]
								);

		for (int i = 1; i < 4; i++) 
		{
			int nuevaColumna = (i % 2 == 0) ? columnaActual : columnaActual + 1;
			int nuevaFila = (i < 2) ? filaActual : filaActual + 1; // ternario (recuerdos de vietnam XD)

			/// validamos que la nueva celda este dentro de los limites de la matriz
			if (nuevaColumna < columnasMatriz && nuevaFila < filasMatriz) 
			{
				double distancia = CalcularDistancia(
										xAjustado, 
										yAjustado, 
										posiciones[i][0], 
										posiciones[i][1]
									);
				if (distancia < distanciaMinima) 
				{
					distanciaMinima = distancia;
					mejorColumna = nuevaColumna;
					mejorFila = nuevaFila;
				}
			}
		}

		/// Plantamos el arbol en la celda mas cercana, si es que esta libre
		if (!matrizArboles[mejorFila][mejorColumna]) {
			// aqui le sumamos el espacio dejado a la izquierda para corregir el posicionmiento en x
			int xArbol = limXizquierda + mejorColumna * anchoCelda + anchoCelda / 2 - anchoArbol / 2;
			int yArbol = limYsuperior + mejorFila * altoCelda + altoCelda / 2 - altoArbol / 2;

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
		case Ninguna:
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

	void InvocarAliado()
	{
		cy = GenerarNumeroAleatorio(limYsuperior, limYinferior - aliado->getAlto());

		aliado->setX(limXizquierda);
		aliado->setY(cy);
		aliado->setVisible(true);
	}

	double PorcentajeReforestacion()
	{
		int totalArboles = arregloArboles.size();
		
		return (totalArboles / cantMaxArboles) * 100;
	}

	bool DeterminarVictoria(Guardian* objGuardian)
	{
		if (PorcentajeReforestacion() >= 70 && objGuardian->getCantVidas() > 0) return true;
		else return false;
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