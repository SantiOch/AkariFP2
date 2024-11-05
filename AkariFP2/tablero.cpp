#include "tablero.h"
#include "colors.h"

void mostrarCoutSeparadorMat(const tTablero& tab);



int getNumFilas(const tTablero& tab) {

	return tab.nFils;
}

int getNumCols(const tTablero& tab) {

	return tab.nCols;
}

tCelda celdaEnPos(const tTablero& tablero, int x, int y) {

	return tablero.datos[x][y];
}

void ponCeldaEnPos(tTablero& tablero, int x, int y, const tCelda& c) {

	tablero.datos[x][y] = c;
}

ostream& operator<<(ostream& out, const tTablero& tab) {

	char aux;

	out << endl;

	/* muestra los numeros de columna*/
	out << "\t  |";

	for (int col = 0; col < tab.nFils; ++col) {
		out << ROSE << setw(HUECOS) << col << " " << RESET << '|';
	}

	out << endl;

	/* muestra la linea separadora */
	mostrarCoutSeparadorMat(tab);

	for (int i = 0; i < tab.nFils; i++) {

		/* muestra una fila donde todas las celdas son bombillas */
		out << "\t" << ROSE << setw(HUECOS) << i << RESET << '|';

		for (int j = 0; j < tab.nCols; j++) {

			aux = celdaToChar(tab.datos[i][j]);

			if (esBombilla(tab.datos[i][j]) || estaIluminada(tab.datos[i][j])) {
				out << BG_LBLUE << BLACK;
				out << setw(HUECOS) << setfill(' ') << aux << " " << RESET;
				out << '|';
			}

			else if (esParedRestringida(tab.datos[i][j])) {
				out << BG_BLACK << GRAY;
				out << setw(HUECOS) << setfill(' ') << aux << " " << RESET;
				out << '|';
			}

			else if (esPared(tab.datos[i][j])) {
				out << BG_BLACK << BLACK;
				out << setw(HUECOS) << setfill(' ') << aux << " " << RESET;
				out << '|';
			}

			else if (estaApagada(tab.datos[i][j])) {
				out << BG_GRAY << BLACK;
				out << setw(HUECOS) << setfill(' ') << aux << " " << RESET;
				out << '|';
			}
		}

		out << endl;

		/* muestra la linea separadora */
		mostrarCoutSeparadorMat(tab);
	}

	return out;
}

ifstream& operator>>(ifstream& archivo, tTablero& tab) {

	char aux;

	archivo >> tab.nFils >> tab.nCols;

	for (int i = 0; i < tab.nFils; i++) {

		for (int j = 0; j < tab.nCols; j++) {
			archivo >> aux;
			tab.datos[i][j] = charToCelda(aux);
		}
	}

	return archivo;
}


void iniciaTablero(tTablero& tablero) {

	tablero.nCols = 0;
	tablero.nFils = 0;
}

void destruyeTablero(tTablero& tablero) {

	tablero.nCols = 0;
	tablero.nFils = 0;
}

void mostrarCoutSeparadorMat(const tTablero& tab) {

	cout << "\t -+";

	for (int col = 0; col < tab.nCols; col++) {
		cout << setw(HUECOS + 2) << setfill('-') << '+' << setfill(' ');
	}

	cout << endl;
}

ofstream& operator<<(ofstream& archivo, const tTablero& tab) {

	archivo << tab.nFils << " " << tab.nCols << endl;

	for (int i = 0; i < tab.nFils; i++) {
		for (int j = 0; j < tab.nCols; j++) {

			archivo << celdaToCharArchivo(tab.datos[i][j]);
		}

		archivo << endl;
	}

	return archivo;
}




