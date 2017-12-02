#include "FIghtSis.h"

void subirdenivel (int&nivel, int&atk, int&dfs, int&xpmax, int&vida)
{
	nivel += 1;
	atk += rand() % 3;
	dfs += rand() % 3;
	xpmax = xpmax*1.5;
	vida += rand() % 5;
}

int experiencia (int atke, int dfse)
{
    int random = rand()%10;
    int xp = (atke+dfse-random)/3;
    return xp;
}



int ataque (int atk, int dfse, int vidae)
{
    int random = rand()%(vidae%10);
	int poder = atk - dfse - random;
	if (poder <= 0)
		vidae -= 1;
	else
		vidae -= poder;
    return vidae;

}

void enemigo (int&atke, int&dfse, int&spde, int&vida)
{
	atke += rand() % 3;
	dfse += rand() % 3;
	spde += rand() % 3;
	vida += rand() % 6;
}
