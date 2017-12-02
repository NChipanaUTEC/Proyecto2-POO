#include "CEnemigo.h"

CEnemigo::CEnemigo()
{
    vidae=100;
    atke=35;
    dfse = 20;
}

CEnemigo::~CEnemigo()
{
    //dtor
}

//Setters
void CEnemigo::setvidae(int h)
{
    vidae = h;
}
void CEnemigo::setatke(int h)
{
    atke = h;
}
void CEnemigo::setdfse(int h)
{
    dfse = h;
}

//Getters
int CEnemigo::get_vidae()
{
    return vidae;
}

int CEnemigo::get_atke()
{
    return atke;
}

int CEnemigo::get_dfse()
{
    return dfse;
}
