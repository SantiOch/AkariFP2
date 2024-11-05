#include "reglasJuego.h"

const int numDir = 4;

void accion(tTablero& tab, int x, int y, tDir direccion, string accion);
int accionTab(const tTablero& juego, int x, int y, tDir direccion);
void cambioDireccion(const tDir& direccion, int& i, int& j);
void reset(tTablero& tab);

tDir siguiente(tDir& direccion) {

	switch (direccion) {
	case NORTE:
		direccion = SUR;
		break;
	case SUR:
		direccion = OESTE;
		break;
	case OESTE:
		direccion = ESTE;
		break;
	case ESTE:
		direccion = NORTE;
		break;
	}
	return direccion;
}

bool comprobarNumPared(const tTablero& juego, int x, int y) {

	bool cierto = false;
	int num = 0;

	tDir direccion = NORTE;

	for (int i = 0; i < numDir; i++) {
		num = num + accionTab(juego, x, y, direccion);
		direccion = siguiente(direccion);
	}

	if (num == numParedRestringida(celdaEnPos(juego, x, y))) {
		cierto = true;
	}

	return cierto;
}

bool estaTerminado(const tTablero& juego) {

	bool terminado = true;
	bool terminadoDentro = false;

	int num = 0;
	int i = 0;
	int j = 0;

	tCelda c;

	while (!terminadoDentro && i < getNumFilas(juego)) {

		while (!terminadoDentro && j < getNumCols(juego)) {

			c = celdaEnPos(juego, i, j);

			if (estaApagada(c)) {
				terminado = false;
				terminadoDentro = true;
			}

			else if (esParedRestringida(c)) {

				if (!comprobarNumPared(juego, i, j)) {
					terminado = false;
					terminadoDentro = true;
				}
			}

			j++;
		}

		j = 0;
		i++;
	}

	return terminado;
}

bool esPosQuit(int x, int y) {

	bool salir = false;

	if (x == -1 && y == 0) {
		salir = true;
	}

	return salir;
}

void ejecutarPos(tTablero& tab, int x, int y) {

	tDir direccion = NORTE;
	tCelda c = celdaEnPos(tab, x, y);

	if (x == -1 && y == -1) {
		reset(tab);
	}

	else if (!esBombilla(c) && !esPared(c) && !estaIluminada(c)) {

		string accionNombre = "ilumina";

		ponBombilla(c);
		ponCeldaEnPos(tab, x, y, c);

		for (int i = 0; i < numDir; i++) {
			accion(tab, x, y, direccion, accionNombre);
			direccion = siguiente(direccion);
		}
	}
	else if (esBombilla(c)) {

		string accionNombre = "apaga";

		apagaCelda(c);
		ponCeldaEnPos(tab, x, y, c);

		for (int i = 0; i < numDir; i++) {
			accion(tab, x, y, direccion, accionNombre);
			direccion = siguiente(direccion);
		}
	}
}


void accion(tTablero& tab, int x, int y, tDir direccion, string accion) {

	int i = 0;
	int j = 0;

	cambioDireccion(direccion, i, j);

	int iaux = x + i;
	int jaux = y + j;

	tCelda c = celdaEnPos(tab, iaux, jaux);

	while (!esPared(c) && iaux > -1 && jaux > -1 && iaux < getNumFilas(tab) && jaux < getNumCols(tab)) {

		if (!esBombilla(c)) {

			if (accion == "ilumina") {
				iluminaCelda(c);
			}

			else {
				apagaCelda(c);
			}
		}

		ponCeldaEnPos(tab, iaux, jaux, c);

		iaux = iaux + i;
		jaux = jaux + j;

		c = celdaEnPos(tab, iaux, jaux);
	}
}

int accionTab(const tTablero& juego, int x, int y, tDir direccion) {

	int i = 0;
	int j = 0;

	cambioDireccion(direccion, i, j);

	int numP = 0;
	i = x + i;
	j = y + j;

	tCelda c = celdaEnPos(juego, i, j);

	if (esBombilla(c)) {
		numP = 1;
	}

	return numP;
}

void cambioDireccion(const tDir& direccion, int& i, int& j) {

	switch (direccion) {

	case NORTE:
		i = 0;
		j = -1;
		break;

	case SUR:
		i = 0;
		j = 1;
		break;

	case OESTE:
		i = -1;
		j = 0;
		break;

	case ESTE:
		i = 1;
		j = 0;
		break;
	}
}

void reset(tTablero& tab) {

	for (int i = 0; i < getNumFilas(tab); i++) {

		for (int j = 0; j < getNumCols(tab); j++) {

			if (!esPared(celdaEnPos(tab, i, j))) {

				tCelda auxc = celdaEnPos(tab, i, j);

				if (estaIluminada(auxc) || esBombilla(auxc)) {

					while (!estaApagada(auxc)) {
						apagaCelda(auxc);
						ponCeldaEnPos(tab, i, j, auxc);
					}
				}
			}
		}
	}
}
