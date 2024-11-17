#pragma once
#include <iostream>
#include <fstream>
//#include <stdlib.h>
#include "Guardian.h"
#include <string>

using namespace std;

class File {
private:
	ofstream fileWrite;
	ifstream fileRead;
	string texto;
	Guardian* guardian;
	int x1, y1, x2, y2;

public:
	File() {
		guardian = new Guardian(200, 200, 64,64);
	}
	~File() {}

	void CargarDatos() {
		fileRead.open("JugadorPuntaje.txt", ios::in);

		if (fileRead.fail()) {
			fileRead.close();

			fileWrite.open("JugadorPuntaje.txt", ios::out);
			fileWrite << guardian->getNombre() << " " << guardian->getPuntos() << endl;
			fileWrite.close();

			fileRead.open("JugadorPuntaje.txt", ios::in);
		}

		getline(fileRead, texto);
		x1 = atoi(texto.c_str());
		getline(fileRead, texto);
		y1 = atoi(texto.c_str());
		getline(fileRead, texto);
		x2 = atoi(texto.c_str());
		getline(fileRead, texto);
		y2 = atoi(texto.c_str());
		getline(fileRead, texto);
	}

	int getX1() { return x1; }
	int getY1() { return y1; }

	int getX2() { return x2; }
	int getY2() { return y2; }

};