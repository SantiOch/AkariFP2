#include "listaPartidas.h"

void iniciaListaPartidas(tListaPartidas& listaPartidas) {
    listaPartidas.nElem = 0;

}

ifstream& operator>>(ifstream& archivo, tListaPartidas& listaPartidas) {
    int aux;
    archivo >> aux;
    tPartida parAux;
    for (int i = 0; i < aux; i++) {
        listaPartidas.datos[i] = new tPartida;
        iniciaPartida(parAux);
        archivo >> parAux;
        insertarOrd(listaPartidas, parAux);
    }

    return archivo;
}

void insertarOrd(tListaPartidas& listaPartidas, const tPartida& partida) {
    

    int pos = 0;

    while (pos < listaPartidas.nElem && *listaPartidas.datos[pos] < partida) {
        pos++;
    }
    
   
    if (listaPartidas.nElem < MAX_PARTIDAS && partida < *listaPartidas.datos[pos]) {
    
        for (int i = listaPartidas.nElem; i > pos; i--) {
            *listaPartidas.datos[i] = *listaPartidas.datos[i - 1];
        }
    }
    *listaPartidas.datos[pos] = partida;
    listaPartidas.nElem++;
}

void destruyeListaPartidas(tListaPartidas& listaPartidas) {
    for (int i = 0; i < listaPartidas.nElem; i++) {
        destruyePartida(*listaPartidas.datos[i]);
        delete listaPartidas.datos[i];
        listaPartidas.datos[i] = NULL;
    }
    listaPartidas.nElem = 0;
}

int buscaPos(const tListaPartidas& listaPartidas, int nivel) {

    int i = 0;

    while (i < listaPartidas.nElem && *listaPartidas.datos[i] < nivel) i++;

    return i;
}

tPtrPartida dameElem(const tListaPartidas& listaPartidas, int pos) {

    tPtrPartida aux = NULL;

    if (pos < listaPartidas.nElem) {
        aux = listaPartidas.datos[pos];
    }

    return aux;
}

int dameNumElem(const tListaPartidas& listaPartidas) {
    return listaPartidas.nElem;
}

ofstream& operator<<(ofstream& archivo, const tListaPartidas& listaPartidas) {

    archivo << listaPartidas.nElem << endl;

    for (int i = 0; i < listaPartidas.nElem; i++) {
        archivo << *listaPartidas.datos[i];
    }

    return archivo;
}

void eliminarPartida(tListaPartidas& listaPartidas, const tPartida& partida) {

    int pos = 0;

    while (*listaPartidas.datos[pos] < partida) {
        pos++;
    }
    delete listaPartidas.datos[pos];
    listaPartidas.datos[pos] = NULL;
    for (pos; pos < listaPartidas.nElem ; pos++) {
        listaPartidas.datos[pos] = listaPartidas.datos[pos + 1];
    }
   

    listaPartidas.nElem--;
}

