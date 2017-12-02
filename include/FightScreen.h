#ifndef FIGHTSCREEN_H_INCLUDED
#define FIGHTSCREEN_H_INCLUDED
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

//#include "Cemento.h"
#include "CEnemigo.h"
#include "CPersona.h"
#include "FIghtSis.h"
#include "GG.h"

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;
using namespace sf;
using namespace std;

void FightScreen();

#endif // FIGHTSCREEN_H_INCLUDED
