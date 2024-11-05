#pragma once

#include <iomanip>
#include <iostream>
#include <fstream>
#include "celda.h"


using namespace std;

const int MAX_FILS = 10;
const int MAX_COLS = 10;

const int HUECOS = 2;
const int N = 5;

typedef tCelda tTableroDatos[MAX_FILS][MAX_COLS];

struct tTablero {
	int nFils;
	int nCols;
	tTableroDatos datos;
};

int getNumFilas(const tTablero& tab);
int getNumCols(const tTablero& tab);
tCelda celdaEnPos(const tTablero& tablero, int x, int y);
void ponCeldaEnPos(tTablero& tablero, int x, int y, const tCelda& c);
ofstream& operator<<(ofstream& archivo, const tTablero& tab);
ostream& operator<<(ostream& out, const tTablero& tab);
ifstream& operator>>(ifstream& archivo, tTablero& tab);
void iniciaTablero(tTablero& tablero);
void destruyeTablero(tTablero& tablero);

