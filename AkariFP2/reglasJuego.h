#pragma once

#include <iostream>
#include "tablero.h"

using namespace std;

typedef enum tDir { NORTE, SUR, ESTE, OESTE };

bool estaTerminado(const tTablero& juego);
bool esPosQuit(int x, int y);
void ejecutarPos(tTablero& tab, int x, int y);