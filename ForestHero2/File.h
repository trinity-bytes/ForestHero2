#pragma once
#include <iostream>
#include <fstream>
#include "Guardian.h"
#include <string>

using namespace std;

class File {
private:
	ofstream fileWrite;
	ifstream fileRead;
	string texto;
	Guardian* guardian;

public:
	File() {
		guardian = new Guardian(200, 200, 64, 64);
	}
	~File() {
		delete guardian;
	}

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
		guardian->getNombre() = atoi(texto.c_str());
		getline(fileRead, texto);
		guardian->setPuntos(atoi(texto.c_str()));
		fileRead.close();
	}
};