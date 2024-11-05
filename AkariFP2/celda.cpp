#include "celda.h"

char celdaToCharPared(const tCelda& celda);
tCelda charToCeldaPared(char c);

char celdaToChar(const tCelda& celda) {

	char aux;

	switch (celda.tipo) {

	case PARED:
		if (celda.numBombillas == -1) {
			aux = 'X';
		}
		else {
			aux = celdaToCharPared(celda);
		}

		break;

	case BOMBILLA:
		aux = '*';
		break;

	default:
		aux = ' ';
		break;
	}

	return aux;
}

tCelda charToCelda(char c) {

	tCelda celda;

	switch (c) {

	case '*':
		celda.tipo = BOMBILLA;
		break;


	case 'X':
		celda.tipo = PARED;
		celda.numBombillas = -1;
		break;

	case '.':
		celda.tipo = LIBRE;
		celda.numBombillas = 0;
		break;

	default:
		celda = charToCeldaPared(c);
		break;
	}

	return celda;
}

bool esPared(const tCelda& c) {

	bool pared = false;

	if (c.tipo == PARED) {
		pared = true;
	}

	return pared;
}

bool esParedRestringida(const tCelda& c) {

	bool paredRestringida = false;

	paredRestringida = esPared(c);

	if (paredRestringida == true) {

		if (c.numBombillas == -1) {
			paredRestringida = false;
		}
	}

	return paredRestringida;

}

int numParedRestringida(const tCelda& c) {

	int numBombillas = -1;
	bool pared = false;

	pared = esParedRestringida(c);

	if (pared == true) {
		numBombillas = c.numBombillas;
	}

	return numBombillas;
}

bool esBombilla(const tCelda& c) {

	bool bombilla = false;

	if (c.tipo == BOMBILLA) {
		bombilla = true;
	}

	return bombilla;
}

bool estaApagada(const tCelda& c) {

	bool apagada = false;

	if (c.tipo == LIBRE && c.numBombillas == 0) {
		apagada = true;
	}

	return apagada;
}

bool estaIluminada(const tCelda& c) {

	bool iluminada = false;

	if (c.tipo == LIBRE && c.numBombillas > 0) {
		iluminada = true;
	}

	return iluminada;
}

void apagaCelda(tCelda& c) {

	if (c.tipo == BOMBILLA) {
		c.tipo = LIBRE;
		c.numBombillas = 0;
	}
	else if (c.tipo == LIBRE) {
		c.numBombillas--;
	}
}

void iluminaCelda(tCelda& c) {

	c.tipo = LIBRE;
	c.numBombillas++;
}

void ponBombilla(tCelda& c) {
	c.tipo = BOMBILLA;
}

char celdaToCharPared(const tCelda& celda) {

	char numeroLetra = celda.numBombillas + '0';

	return numeroLetra;
}

tCelda charToCeldaPared(char c) {

	tCelda celda;

	celda.tipo = PARED;
	celda.numBombillas = c - '0';

	return celda;
}

char celdaToCharArchivo(const tCelda& celda) {

	char aux;

	switch (celda.tipo) {

	case PARED:
		if (celda.numBombillas == -1) {
			aux = 'X';
		}
		else {
			aux = celdaToCharPared(celda);
		}

		break;

	default:
		aux = '.';
		break;
	}

	return aux;
}