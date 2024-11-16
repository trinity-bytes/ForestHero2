#pragma once
#include <iostream>
#include <fstream>
//#include <stdlib.h>
#include <string>

using namespace std;

class File {
private:
	ofstream fileWrite;
	ifstream fileRead;
	string texto;

	int x1, y1, x2, y2;

public:
	File() {}
	~File() {}

	void CargarDatos() {
		fileRead.open("JugadorPuntaje.txt", ios::in);

		if (fileRead.fail()) {
			fileRead.close();

			fileWrite.open("JugadorPuntaje.txt", ios::out);
			fileWrite << "100" << endl;
			fileWrite << "300" << endl;
			fileWrite << "30" << endl;
			fileWrite << "150" << endl;
			fileWrite << "200" << endl;
			fileWrite << "400" << endl;
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