#pragma once

#include <iostream>
#include <fstream>
#include "posicion.h"



using namespace std;

const int DIM = 2;

typedef struct {
	int cont;
	int size;
	tPosicion* arrayPos;
} tListaPosiciones;

void iniciaListaPosiciones(tListaPosiciones& lp);
void destruyeListaPosiciones(tListaPosiciones& lp);
void insertar(tListaPosiciones& lp, const tPosicion& pos);
int dameNumElem(const tListaPosiciones& lp);
tPosicion dameElem(const tListaPosiciones& lp, int i);
ofstream& operator<<(ofstream& archivo, const tListaPosiciones& lp);