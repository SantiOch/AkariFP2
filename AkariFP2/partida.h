#pragma once

#include <iostream>
#include <fstream>
#include "listaPosiciones.h"
#include "reglasJuego.h"

using namespace std;

typedef struct {
	tTablero tablero;
	tListaPosiciones listaBombillas;
	int nivel;
} tPartida;

void iniciaPartida(tPartida& partida);
void destruyePartida(tPartida& partida);
ifstream& operator>>(ifstream& archivo, tPartida& partida);
bool operator<(const tPartida& partida, int nivel);
bool operator<(const tPartida& partida1, const tPartida& partida2);
bool juega(tPartida& partida, int& nIt);
ofstream& operator<<(ofstream& archivo, const tPartida & partida);