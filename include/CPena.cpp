#include "CPena.h"

CPena::CPena()
{
    vidae=500;
    atke=60;
    dfse = 30;
}

CPena::~CPena()
{
    //dtor
}

//Setters
void CPena::setvidae(int h)
{
    vidae = h;
}
void CPena::setatke(int h)
{
    atke = h;
}
void CPena::setdfse(int h)
{
    dfse = h;
}

//Getters
int CPena::get_vidae()
{
    return vidae;
}

int CPena::get_atke()
{
    return atke;
}

int CPena::get_dfse()
{
    return dfse;
}

