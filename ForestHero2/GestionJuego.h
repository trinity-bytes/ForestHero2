#pragma once
#include "FuncionesCustom.h"
#include "GestionRecursos.h"
#include "Guardian.h"

class GestionJuego
{
private:
	ArregloElementos* objElementos;
	Guardian* objGuardian;
	Agua* objAgua;
public:
	GestionJuego()
	{
		IniciarElementos();
	}
	~GestionJuego() {}

	void IniciarElementos() {}

	void MoverTodo(Graphics^ g) 
	{
		int r = GenerarNumeroAleatorio(0, 100);
		Direccion tecla;

		switch (r)
		{
		case 1:
			tecla = Arriba; break;
		case 15:
			tecla = Abajo; break;
		case 30:
			tecla = Izquierda; break;
		case 45:
			tecla = Derecha; break;
		default:
			break;
		}

		for (int i = 0; i < objElementos->sizeEnemigo(); i++)
		{
			objElementos->returnEnemigo(i)->Mover(g, tecla);
		}
	}
	void RevisarColisiones() 
	{
		for (int i = 0; i < objElementos->sizeBasura(); i++)
		{
			for (int j = 0; j < objElementos->sizeSemilla(); j++)
			{
				if (objElementos->returnBasura(i)->getRectangle().IntersectsWith(objElementos->returnSemilla(j)->getRectangle()))
				{
					objElementos->deleteBasura(i);
					objElementos->deleteSemilla(j);
					//Eliminar la basura y la semilla al realizar la colision
				}
			}
		}

		for (int i = 0; i < objElementos->sizeEnemigo(); i++)
		{
			if (objElementos->returnEnemigo(i)->getRectangle().IntersectsWith(objGuardian->getRectangle()))
			{
				//Perder Vidas 
				objGuardian->setVidas(-1);
				objElementos->deleteEnemigo(i);
			}
		}

		for (int i = 0; i < objElementos->sizeBasura(); i++)
		{
			if (objElementos->returnBasura(i)->getRectangle().IntersectsWith(objGuardian->getRectangle()))
			{
				//Perder Vidas
				objGuardian->setVidas(-1);
			}
		}

		for (int i = 0; i < objElementos->sizeAgua(); i++)
		{
			if (objElementos->returnAgua(i)->getRectangle().IntersectsWith(objGuardian->getRectangle()))
			{
				//Aumentar agua
				objElementos->addAgua(objAgua);
			}
		}
		for (int i = 0; i < objElementos->sizeSemilla(); i++)
		{
			if (objElementos->returnSemilla(i)->getRectangle().IntersectsWith(objGuardian->getRectangle()))
			{
				//No se si este es la semilla que se encuentra por el suelo, en ese caso en vez de ser
				//return arbol, es return Semilla
				//Aumentar semillas
			}
		}
	}
	void DeterminarGanador() 
	{
		//Poner la funcion de determinar ganador
	}

	bool AnalizarGAMEOVER()
	{
		if (objGuardian->getVidas()==0)
		{
			//Poner GAMEOVER
		}
	}
};



