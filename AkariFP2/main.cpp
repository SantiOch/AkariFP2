#include <iostream>
#include <fstream>
#include <iomanip>
#include "reglasJuego.h"
#include "listaPartidas.h"
#include "checkML.h"
using namespace std;

//void preguntar(int& x, int& y);
//void introDatosYMovExtra(tTablero& tab, int x, int y, ifstream& archivo);

int nivel();
string nombreFichero();

int main() {
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ifstream archivo;
	ofstream archivo1;

	tListaPartidas* listaPartidas = new tListaPartidas;

//	int x = 0;
//	int y = 0;
	int nivelJugado;
	int nIt = 0;

	cout << "Introduce el nombre del archivo: ";

	archivo.open(nombreFichero());

	if (archivo.is_open()) {

		iniciaListaPartidas(*listaPartidas);
		archivo >> *listaPartidas;

		nivelJugado = buscaPos(*listaPartidas, nivel());

		if (juega(*dameElem(*listaPartidas, nivelJugado), nIt)) {
			eliminarPartida(*listaPartidas, *dameElem(*listaPartidas, nivelJugado));
		} 
		cout << endl << "HAS HECHO " << nIt << " MOVIMIENTOS" << endl << endl;

		cout << "Dame el nombre del fichero en el que quieres guardar los datos: ";

		archivo1.open(nombreFichero());
		
		if (archivo1.is_open()) {
			archivo1 << *listaPartidas;
		}
	}

	else {
		cout << "No se pudo cargar correctamente el archivo" << endl;
	}

	destruyeListaPartidas(*listaPartidas);
	delete listaPartidas;
	listaPartidas = NULL;
	return 0;
}

int nivel() {

	int numNivel;

	cout << endl << "Seleciona el nivel: ";
	cin >> numNivel;

	return numNivel;
}

string nombreFichero() {

	string nombre;

	cin >> nombre;

	return nombre;
}

/*
void introDatosYMovExtra(tTablero& tab, int x, int y, ifstream& archivo) {

	int numMov;

	archivo >> tab;

	cout << tab;

	archivo >> numMov;

	for (int i = 0; i < numMov; i++) {
		archivo >> x >> y;
		ejecutarPos(tab, x, y);
		cout << tab;
	}

	archivo.close();
}
*/
