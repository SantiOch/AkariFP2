#include "partida.h"

void preguntar(int& x, int& y);
void introDatosYMovExtra(tTablero& tab, ifstream& archivo);
void guarda(tPartida& partida);

void iniciaPartida(tPartida& partida) {
	partida.nivel = 0;
	iniciaListaPosiciones(partida.listaBombillas);
	iniciaTablero(partida.tablero);
}

void destruyePartida(tPartida& partida) {
	partida.nivel = 0;
	destruyeListaPosiciones(partida.listaBombillas);
	destruyeTablero(partida.tablero);
}

ifstream& operator>>(ifstream& archivo, tPartida& partida) {

	string nivel;

	archivo >> nivel >> partida.nivel;
	archivo >> partida.tablero;
	introDatosYMovExtra(partida.tablero, archivo);

	return archivo;
}

bool operator<(const tPartida& partida, int nivel) {
	return (partida.nivel < nivel);
}

bool operator<(const tPartida& partida1, const tPartida& partida2) {
	bool aux = false;
	if (partida1.nivel < partida2.nivel) {
		aux = true;
	}

	return aux;
}

bool juega(tPartida& partida, int& nIt) {

	bool cierto = false;
	bool salir = false;

	int x = 0;
	int y = 0;

	for (int i = 0; i < dameNumElem(partida.listaBombillas); i++) {
		x = dameX(dameElem(partida.listaBombillas, i));
		y = dameY(dameElem(partida.listaBombillas, i));
		ejecutarPos(partida.tablero, x, y);
	}

	while (!estaTerminado(partida.tablero) && !salir) {
		preguntar(x, y);
		if (esPosQuit(x, y)) {
			salir = true;
		}
		else {
			ejecutarPos(partida.tablero, x, y);
			cout << partida.tablero;
			nIt++;
			cout << endl;
		}
	}

	if (estaTerminado(partida.tablero)) {

		cout << "HAS GANADO!!!!!!!!!!!!! :)" << endl;

		cierto = true;
	}
	else {
		guarda(partida);
	}
	return cierto;
}

ofstream& operator<<(ofstream& archivo, const tPartida& partida) {

	archivo << "LEVEL " << partida.nivel << endl;
	archivo << partida.tablero;
	archivo << partida.listaBombillas;

	return archivo;
}

void preguntar(int& x, int& y) {

	cout << endl;
	cout << "Introduce el numero de la fila: ";
	cin >> x;
	cout << endl;
	cout << "Introduce el numero de la columna: ";
	cin >> y;
	cout << endl;
}


void introDatosYMovExtra(tTablero& tab, ifstream& archivo) {
	int x, y;
	int numMov;
	archivo >> numMov;

	for (int i = 0; i < numMov; i++) {
		archivo >> x >> y;
		ejecutarPos(tab, x, y);
	}
}

void guarda(tPartida& partida) {
	
	tPosicion pos;
	
	for (int i = 0; i < getNumFilas(partida.tablero); i++) {
		for (int j = 0; j < getNumCols(partida.tablero); j++) {
			if (esBombilla(celdaEnPos(partida.tablero, i, j))) {
				iniciaPosicion(pos, i, j);
				insertar(partida.listaBombillas, pos);
			}
		}
	}
}
