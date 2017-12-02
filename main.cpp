#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//#include <iostream>
//#include <stdio.h>
//#include <time.h>
//include <unistd.h>
//#include <dos.h>
//#include <windows.h>
#include "include/CPersona.h"
#include "include/CEnemigo.h"
#include "include/Intro.h"
#include "include/Congratulations.cpp"

int main()
{
    CPersona per;
    CEnemigo ene;
    per.setnivel(per.get_nivel()+1);
    per.setatk(per.get_atk()+ 3);
    per.setdfs(per.get_dfs()+3);
    per.setxpmax(per.get_xpmax()*1.5);
    per.setxp(0);
    introduccion();

    return 0;
}
