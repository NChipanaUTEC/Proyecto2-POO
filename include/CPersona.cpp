#include "CPersona.h"

CPersona::CPersona():vida(100),nivel(1),atk(40),dfs(10),xp(0),xpmax(10)
{

}

CPersona::~CPersona()
{
    //dtor
}

// Setters

void CPersona::setvida(int h)
{
    vida = h;
}

void CPersona::setnivel(int m)
{
    nivel = m;
}

void CPersona::setatk(int s)
{
    atk = s;
}

void CPersona::setdfs(int d)
{
    dfs = d;
}

void CPersona::setxp(int x)
{
    xp = x;
}

void CPersona::setxpmax(int xp)
{
    xpmax = xp;
}

void CPersona::setx(int pos_x)
{
    pos_x = x;
}

void CPersona::sety(int pos_y)
{
    pos_y = y;
}
//Getters

int CPersona::get_vida()
{
    return vida;
}

int CPersona::get_nivel()
{
    return nivel;
}

int CPersona::get_atk()
{
    return atk;
}

int CPersona::get_dfs()
{
    return dfs;
}

int CPersona::get_xp()
{
    return xp;
}

int CPersona::get_xpmax()
{
    return xpmax;
}

int CPersona::get_x()
{
    return x;
}

int CPersona::get_y()
{
    return y;
}

int CPersona::aumento_nivel()
{
    return CPersona::nivel ++;
}
