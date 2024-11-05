#include "listaPosiciones.h"

void redimensionar(tListaPosiciones& lp);


void iniciaListaPosiciones(tListaPosiciones& lp) {
	lp.cont = 0;
	lp.arrayPos = new tPosicion[DIM];
	lp.size = DIM;
}

void destruyeListaPosiciones(tListaPosiciones& lp) {

	for (int i = 0; i < lp.cont; i++) {
		destruyePosicion(lp.arrayPos[i]);
	}

	lp.cont = 0;
	lp.size = 0;

	delete[] lp.arrayPos;
	lp.arrayPos = NULL;
}

void insertar(tListaPosiciones& lp, const tPosicion& pos) {

	if (lp.cont == lp.size) {
		redimensionar(lp);
	}

	lp.arrayPos[lp.cont] = pos;
	lp.cont++;
}

int dameNumElem(const tListaPosiciones& lp) {

	return lp.cont;
}

tPosicion dameElem(const tListaPosiciones& lp, int i) {

	return lp.arrayPos[i];
}

ofstream& operator<<(ofstream& archivo, const tListaPosiciones& lp) {
	archivo << lp.cont << endl;
	for (int i = 0; i < lp.cont; i++) {
		archivo << lp.arrayPos[i];
	}

	return archivo;
}

void redimensionar(tListaPosiciones& lp) {

	int cont = lp.cont;
	int newSize = lp.size * 2;
	tPosicion* lAux = new tPosicion[newSize];

	for (int i = 0; i < lp.cont; i++) {
		int x = dameX(lp.arrayPos[i]);
		int y = dameY(lp.arrayPos[i]);
		iniciaPosicion(lAux[i], x, y);
	}
	destruyeListaPosiciones(lp);
	lp.cont = cont;
	lp.size = newSize;
	lp.arrayPos = lAux;
}
