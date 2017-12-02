#ifndef FIGHTSIS_H_INCLUDED
#define FIGHTSIS_H_INCLUDED

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void subirdenivel (int&nivel, int&atk, int&dfs, int&xpmax, int&vida);
int experiencia (int atke, int dfse);
int ataque (int atk, int dfse, int vidae);
void enemigo (int&atke, int&dfse, int&spde, int&vida);

#endif // FIGHTSIS_H_INCLUDED
